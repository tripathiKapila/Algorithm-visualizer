#include "Visualizer.hpp"
#include "Button.hpp"
#include "UIManager.hpp"
#include "InputManager.hpp"
#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>

// Helper function to convert HSV to RGB.
sf::Color hsvToRgb(float hue, float saturation, float value) {
    float C = value * saturation;
    float X = C * (1 - std::fabs(std::fmod(hue / 60.0f, 2) - 1));
    float m = value - C;
    float r, g, b;
    if (hue < 60) {
        r = C; g = X; b = 0;
    } else if (hue < 120) {
        r = X; g = C; b = 0;
    } else if (hue < 180) {
        r = 0; g = C; b = X;
    } else if (hue < 240) {
        r = 0; g = X; b = C;
    } else if (hue < 300) {
        r = X; g = 0; b = C;
    } else {
        r = C; g = 0; b = X;
    }
    return sf::Color(static_cast<sf::Uint8>((r + m) * 255),
                     static_cast<sf::Uint8>((g + m) * 255),
                     static_cast<sf::Uint8>((b + m) * 255));
}

// Updated helper function to create beautiful colors for array bars.
sf::Color getBarColor(int value) {
    // Assuming value ranges from 1 to 100.
    float ratio = (value - 1) / 99.0f;
    // Create a gradient from purple (hue ~270) to orange (hue ~30)
    float hue = 270 - ratio * 240; // when ratio = 0, hue = 270 (purple); when ratio = 1, hue = 30 (orange)
    return hsvToRgb(hue, 0.8f, 0.9f);
}

Visualizer::Visualizer(unsigned int width, unsigned int height)
    : mWindow(sf::VideoMode(width, height), "Algorithm Visualizer")
{
    if (!mFont.loadFromFile("assets/fonts/OpenSans-Regular.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }

    // Setup UI Buttons using the Button class.
    mPlayButton = std::make_shared<Button>(
        sf::Vector2f(100.f, 40.f),
        sf::Vector2f(10.f, height - 50.f),
        mFont,
        "Play",
        18
    );
    mRestartButton = std::make_shared<Button>(
        sf::Vector2f(100.f, 40.f),
        sf::Vector2f(120.f, height - 50.f),
        mFont,
        "Restart",
        18
    );
    // NEW: Back/Menu Button
    mBackButton = std::make_shared<Button>(
        sf::Vector2f(100.f, 40.f),
        sf::Vector2f(230.f, height - 50.f),
        mFont,
        "Menu",
        18
    );

    // Set callbacks for the buttons.
    mPlayButton->setCallback([this]() {
        mIsPlaying = !mIsPlaying;
        if (mIsPlaying) {
            mPlayButton->setText("Pause");
            std::cout << "Visualization is now playing." << std::endl;
        } else {
            mPlayButton->setText("Play");
            std::cout << "Visualization is now paused." << std::endl;
        }
    });

    mRestartButton->setCallback([this]() {
        // Restart: Reset state to original data.
        mData = originalData;
        mCurrentActionIndex = 0;
        mComparisons = 0;
        mSwaps = 0;
        mNodesVisited = 0;
        mNodePositions.clear();
        mSwapAnimation.active = false;
        if (mIsGraphMode) {
            mVisitedNodes.assign(mGraph.size(), false);
        }
    });
    
    mBackButton->setCallback([this]() {
        mReturnToMenu = true;
        std::cout << "Returning to menu." << std::endl;
    });

    mUIManager.addButton(mPlayButton);
    mUIManager.addButton(mRestartButton);
    mUIManager.addButton(mBackButton);

    // Setup Metrics Text.
    mMetricsText.setFont(mFont);
    mMetricsText.setCharacterSize(16);
    mMetricsText.setFillColor(sf::Color::White);
    mMetricsText.setPosition(10.f, 10.f);

    // Setup Instructions Text.
    mInstructionsText.setFont(mFont);
    mInstructionsText.setCharacterSize(14);
    mInstructionsText.setFillColor(sf::Color::White);
    mInstructionsText.setPosition(10.f, height - 90.f);
    mInstructionsText.setString("Controls: S=Save, L=Load, R=Reset, Up/Down=Speed, Right=Step, Click=Modify, Menu=Return");

    // Bind keys to actions using InputManager.
    mInputManager.bindKey(sf::Keyboard::Right, InputAction::Step);
    mInputManager.bindKey(sf::Keyboard::S, InputAction::Save);
    mInputManager.bindKey(sf::Keyboard::L, InputAction::Load);
    mInputManager.bindKey(sf::Keyboard::R, InputAction::Reset);
    mInputManager.bindKey(sf::Keyboard::Up, InputAction::SpeedUp);
    mInputManager.bindKey(sf::Keyboard::Down, InputAction::SpeedDown);
    
    mInputManager.bindAction(InputAction::Step, [this]() {
        nextStep();
    });
    mInputManager.bindAction(InputAction::Save, [this]() {
        saveData();
    });
    mInputManager.bindAction(InputAction::Load, [this]() {
        loadData();
    });
    mInputManager.bindAction(InputAction::Reset, [this]() {
        mData = originalData;
        mCurrentActionIndex = 0;
        mComparisons = 0;
        mSwaps = 0;
        mNodesVisited = 0;
        mNodePositions.clear();
        mSwapAnimation.active = false;
        if (mIsGraphMode) {
            mVisitedNodes.assign(mGraph.size(), false);
        }
    });
    mInputManager.bindAction(InputAction::SpeedUp, [this]() {
        mPlaybackSpeed += 0.5f;
    });
    mInputManager.bindAction(InputAction::SpeedDown, [this]() {
        if (mPlaybackSpeed > 0.5f)
            mPlaybackSpeed -= 0.5f;
    });
}

void Visualizer::setData(const std::vector<int>& data) {
    mData = data;
    originalData = data;
    mNodePositions.clear(); // Reset any previously computed positions.
}

void Visualizer::setGraph(const Graph& graph) {
    mGraph = graph;
    mNodePositions.clear(); // Ensure node positions get recalculated.
    // Initialize visited status for each node.
    mVisitedNodes.assign(mGraph.size(), false);
}

void Visualizer::loadActions(const std::vector<Action>& actions) {
    mActions = actions;
    mCurrentActionIndex = 0;
    mComparisons = 0;
    mSwaps = 0;
    mNodesVisited = 0;
}

void Visualizer::saveData() {
    std::ofstream ofs("data.txt");
    if (!ofs) {
        std::cerr << "Error saving data!" << std::endl;
        return;
    }
    for (int val : mData) {
        ofs << val << " ";
    }
    ofs.close();
    std::cout << "Data saved to data.txt\n";
}

void Visualizer::loadData() {
    std::ifstream ifs("data.txt");
    if (!ifs) {
        std::cerr << "Error loading data!" << std::endl;
        return;
    }
    mData.clear();
    int val;
    while (ifs >> val) {
        mData.push_back(val);
    }
    ifs.close();
    std::cout << "Data loaded from data.txt\n";
}

void Visualizer::handleBarClick(sf::Vector2f mousePos) {
    if (mIsGraphMode) {
        for (size_t i = 0; i < mNodePositions.size(); ++i) {
            sf::CircleShape circle(20.f);
            circle.setOrigin(20.f, 20.f);
            circle.setPosition(mNodePositions[i]);
            if (circle.getGlobalBounds().contains(mousePos)) {
                std::cout << "Node " << i << " clicked." << std::endl;
                return;
            }
        }
    } else {
        float barWidth = static_cast<float>(mWindow.getSize().x) / mData.size();
        int index = static_cast<int>(mousePos.x / barWidth);
        if (index >= 0 && index < static_cast<int>(mData.size())) {
            std::cout << "Bar at index " << index << " clicked. Value: " << mData[index] << "\n";
        }
    }
}

void Visualizer::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            mWindow.close();

        if (event.type == sf::Event::Resized) {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            mWindow.setView(sf::View(visibleArea));
            if (mIsGraphMode)
                mNodePositions.clear();
            updateLayout();
        }
        mUIManager.handleEvent(event, mWindow);
        mInputManager.processEvent(event);
        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x),
                                  static_cast<float>(event.mouseButton.y));
            handleBarClick(mousePos);
        }
    }
}

void Visualizer::update(sf::Time deltaTime) {
    static float accumulator = 0.f;
    if (mSwapAnimation.active) {
        mSwapAnimation.elapsed += deltaTime.asSeconds();
        if (mSwapAnimation.elapsed >= mSwapAnimation.duration) {
            std::swap(mData[mSwapAnimation.index1], mData[mSwapAnimation.index2]);
            mSwapAnimation.active = false;
            mSwapAnimation.elapsed = 0.f;
            mCurrentActionIndex++;
        }
    } else if (mIsPlaying) {
        accumulator += deltaTime.asSeconds();
        if (accumulator >= (1.f / mPlaybackSpeed)) {
            nextStep();
            accumulator = 0.f;
        }
    }
}

void Visualizer::nextStep() {
    if (mSwapAnimation.active)
        return;

    if (mCurrentActionIndex >= mActions.size()) {
        std::cout << "All actions processed. Restarting simulation..." << std::endl;
        mData = originalData;
        mCurrentActionIndex = 0;
        mComparisons = 0;
        mSwaps = 0;
        mNodesVisited = 0;
        mNodePositions.clear();
        mSwapAnimation.active = false;
        if (mIsGraphMode)
            mVisitedNodes.assign(mGraph.size(), false);
        return;
    }

    const Action& action = mActions[mCurrentActionIndex];
    switch (action.type) {
        case ActionType::Compare:
            mComparisons++;
            mCurrentActionIndex++;
            break;
        case ActionType::Swap:
            mSwaps++;
            {
                float barWidth = static_cast<float>(mWindow.getSize().x) / mData.size();
                mSwapAnimation.index1 = action.index1;
                mSwapAnimation.index2 = action.index2;
                mSwapAnimation.elapsed = 0.f;
                mSwapAnimation.startX1 = action.index1 * barWidth;
                mSwapAnimation.startX2 = action.index2 * barWidth;
                mSwapAnimation.targetX1 = action.index2 * barWidth;
                mSwapAnimation.targetX2 = action.index1 * barWidth;
                mSwapAnimation.value1 = mData[action.index1];
                mSwapAnimation.value2 = mData[action.index2];
                mSwapAnimation.active = true;
            }
            break;
        case ActionType::Set:
            if (action.index1 < mData.size()) {
                mData[action.index1] = action.value1;
                mCurrentActionIndex++;
            }
            break;
        case ActionType::Visit:
            mNodesVisited++;
            if (mIsGraphMode && action.index1 < mVisitedNodes.size()) {
                mVisitedNodes[action.index1] = true;
            }
            mCurrentActionIndex++;
            break;
    }
}

float Visualizer::lerp(float a, float b, float t) {
    return a + t * (b - a);
}

void Visualizer::render() {
    // Draw a dark blue-gray background.
    mWindow.clear(sf::Color(44, 62, 80));
    if (mIsGraphMode)
        renderGraph();
    else
        renderArray();
    renderUI();
    mWindow.display();
}

void Visualizer::renderArray() {
    float barWidth = static_cast<float>(mWindow.getSize().x) / mData.size();
    float t = mSwapAnimation.active ? (mSwapAnimation.elapsed / mSwapAnimation.duration) : 1.f;
    for (std::size_t i = 0; i < mData.size(); ++i) {
        sf::RectangleShape bar;
        float barHeight = static_cast<float>(mData[i] * 3);
        float xPos = i * barWidth;
        // Use the beautiful color based on the bar's value.
        sf::Color barColor = getBarColor(mData[i]);
        // If this bar is being animated, interpolate its position.
        if (mSwapAnimation.active) {
            if (static_cast<int>(i) == mSwapAnimation.index1) {
                xPos = lerp(mSwapAnimation.startX1, mSwapAnimation.targetX1, t);
            } else if (static_cast<int>(i) == mSwapAnimation.index2) {
                xPos = lerp(mSwapAnimation.startX2, mSwapAnimation.targetX2, t);
            }
        }
        bar.setSize(sf::Vector2f(barWidth - 1, barHeight));
        bar.setPosition(xPos, 300.f - barHeight);
        bar.setFillColor(barColor);
        mWindow.draw(bar);
    }
}

void Visualizer::renderGraph() {
    // Predefined attractive color palette.
    std::vector<sf::Color> palette = {
        sf::Color(52, 152, 219),   // Peter River
        sf::Color(46, 204, 113),   // Emerald
        sf::Color(155, 89, 182),   // Amethyst
        sf::Color(241, 196, 15),   // Sun Flower
        sf::Color(230, 126, 34),   // Carrot
        sf::Color(231, 76, 60),    // Alizarin
        sf::Color(26, 188, 156),   // Turquoise
        sf::Color(149, 165, 166),  // Concrete
        sf::Color(52, 73, 94)      // Wet Asphalt
    };

    if (mNodePositions.empty() && !mData.empty()) {
        int n = mData.size();
        float centerX = mWindow.getSize().x / 2.f;
        float centerY = mWindow.getSize().y / 2.f;
        float radius = std::min(centerX, centerY) - 50;
        for (int i = 0; i < n; i++) {
            float angle = (2 * 3.14159265f * i) / n;
            float x = centerX + radius * std::cos(angle);
            float y = centerY + radius * std::sin(angle);
            mNodePositions.push_back(sf::Vector2f(x, y));
        }
    }
    // Draw edges using white color.
    for (size_t i = 0; i < mGraph.size(); ++i) {
        for (int neighbor : mGraph[i]) {
            if (static_cast<int>(i) < neighbor && neighbor < static_cast<int>(mNodePositions.size())) {
                sf::Vertex line[] =
                {
                    sf::Vertex(mNodePositions[i], sf::Color::White),
                    sf::Vertex(mNodePositions[neighbor], sf::Color::White)
                };
                mWindow.draw(line, 2, sf::Lines);
            }
        }
    }
    // Draw nodes.
    for (size_t i = 0; i < mData.size(); ++i) {
        sf::CircleShape circle(20.f);
        circle.setOrigin(20.f, 20.f);
        circle.setPosition(mNodePositions[i]);
        // If visited, use bright red; otherwise, choose a color from the palette.
        if (mVisitedNodes.size() > i && mVisitedNodes[i])
            circle.setFillColor(sf::Color::Red);
        else
            circle.setFillColor(palette[i % palette.size()]);
        circle.setOutlineThickness(3.f);
        circle.setOutlineColor(sf::Color::White);
        mWindow.draw(circle);
    }
}

void Visualizer::renderUI() {
    mUIManager.render(mWindow);
    std::stringstream ss;
    ss << "Comparisons: " << mComparisons << "\nSwaps: " << mSwaps
       << "\nNodes Visited: " << mNodesVisited;
    mMetricsText.setString(ss.str());
    mWindow.draw(mMetricsText);
    mWindow.draw(mInstructionsText);
}

void Visualizer::updateLayout() {
    sf::Vector2u winSize = mWindow.getSize();
    mPlayButton->setPosition(sf::Vector2f(10.f, winSize.y - 50.f));
    mRestartButton->setPosition(sf::Vector2f(120.f, winSize.y - 50.f));
    mBackButton->setPosition(sf::Vector2f(230.f, winSize.y - 50.f));
    mInstructionsText.setPosition(10.f, winSize.y - 90.f);
}

void Visualizer::run() {
    sf::Clock clock;
    while (mWindow.isOpen() && !mReturnToMenu) {
        
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
    mWindow.close();
}
