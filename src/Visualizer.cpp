#include "Visualizer.hpp"
#include <iostream>
#include <fstream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Visualizer::Visualizer(unsigned int width, unsigned int height)
    : mWindow(sf::VideoMode(width, height), "Algorithm Visualizer", sf::Style::Close)
    , mIsPlaying(false)
    , mPlaybackSpeed(1.0f)
    , mCurrentActionIndex(0)
    , mComparisons(0)
    , mSwaps(0)
    , mNodesVisited(0)
{
    // Load font
    if (!mFont.loadFromFile("../assets/fonts/OpenSans-Regular.ttf")) {
        std::cerr << "Error loading font\n";
    }

    // Initialize UI elements with wider buttons
    mPlayButton = std::make_shared<Button>(
        sf::Vector2f(100, 40),  // Back to normal width
        sf::Vector2f(10, height - 50),
        mFont,
        "Play"
    );
    mPlayButton->setCallback([this]() {
        mIsPlaying = !mIsPlaying;
        updatePlayButtonText();
    });
    mPlayButton->setTooltip("Play/Pause visualization");

    mRestartButton = std::make_shared<Button>(
        sf::Vector2f(100, 40),
        sf::Vector2f(120, height - 50),  // Adjusted position
        mFont,
        "Restart"
    );
    mRestartButton->setCallback([this]() {
        mCurrentActionIndex = 0;
        mComparisons = 0;
        mSwaps = 0;
        mNodesVisited = 0;
        mData = originalData;
        mAnimationManager.reset();
        mIsPlaying = false;
        updatePlayButtonText();
    });
    mRestartButton->setTooltip("Restart visualization");

    mBackButton = std::make_shared<Button>(
        sf::Vector2f(100, 40),
        sf::Vector2f(230, height - 50),  // Adjusted position
        mFont,
        "Back"
    );
    mBackButton->setCallback([this]() {
        mReturnToMenu = true;
    });
    mBackButton->setTooltip("Return to main menu");

    // Initialize speed display text
    mSpeedText.setFont(mFont);
    mSpeedText.setCharacterSize(14);
    mSpeedText.setFillColor(sf::Color::Yellow);  // Make speed more visible
    mSpeedText.setPosition(mWindow.getSize().x - 100, 10);  // Position at top right

    mUIManager.addButton(mPlayButton);
    mUIManager.addButton(mRestartButton);
    mUIManager.addButton(mBackButton);

    // Initialize input bindings
    mInputManager.bindKey(sf::Keyboard::Space, InputAction::PlayPauseToggle);
    mInputManager.bindKey(sf::Keyboard::Right, InputAction::Step);
    mInputManager.bindKey(sf::Keyboard::Up, InputAction::SpeedUp);
    mInputManager.bindKey(sf::Keyboard::Down, InputAction::SpeedDown);

    mInputManager.bindAction(InputAction::PlayPauseToggle, [this]() {
        mIsPlaying = !mIsPlaying;
        updatePlayButtonText();
    });

    mInputManager.bindAction(InputAction::Step, [this]() {
        if (!mIsPlaying) nextStep();
    });

    mInputManager.bindAction(InputAction::SpeedUp, [this]() {
        mPlaybackSpeed = std::min(4.0f, mPlaybackSpeed * 1.5f);
    });

    mInputManager.bindAction(InputAction::SpeedDown, [this]() {
        mPlaybackSpeed = std::max(0.25f, mPlaybackSpeed / 1.5f);
    });

    // Initialize metrics text
    mMetricsText.setFont(mFont);
    mMetricsText.setCharacterSize(14);
    mMetricsText.setFillColor(sf::Color::White);
    mMetricsText.setPosition(10, 10);

    // Initialize instructions text
    mInstructionsText.setFont(mFont);
    mInstructionsText.setCharacterSize(14);
    mInstructionsText.setFillColor(sf::Color::White);
    mInstructionsText.setPosition(10, height - 90);
    mInstructionsText.setString(
        "Controls:\n"
        "Space - Play/Pause | Right Arrow - Step\n"
        "Up/Down Arrows - Adjust Speed"
    );
}

void Visualizer::run() {
    sf::Clock clock;
    // Reset state when starting visualization
    mIsPlaying = false;
    mPlaybackSpeed = 1.0f;
    mCurrentActionIndex = 0;
    mComparisons = 0;
    mSwaps = 0;
    mNodesVisited = 0;
    mPlayButton->setText("Play");

    while (mWindow.isOpen() && !mReturnToMenu) {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
    mReturnToMenu = false;
}

void Visualizer::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mWindow.close();
        }
        mUIManager.handleEvent(event, mWindow);
        mInputManager.processEvent(event);
    }
}

void Visualizer::update(sf::Time deltaTime) {
    static float timeSinceLastStep = 0.0f;
    const float stepInterval = 0.5f / mPlaybackSpeed;  // Adjust this value to control animation speed
    
    if (mIsPlaying && !mAnimationManager.isActive()) {
        timeSinceLastStep += deltaTime.asSeconds();
        if (timeSinceLastStep >= stepInterval) {
            nextStep();
            timeSinceLastStep = 0.0f;
        }
    }
    mAnimationManager.update(deltaTime.asSeconds());

    // Update play button text
    updatePlayButtonText();
}

void Visualizer::render() {
    mWindow.clear(mThemeManager.getBackgroundColor());

    if (mIsGraphMode) {
        renderGraph();
    } else {
        renderArray();
    }

    // Update and render metrics
    std::string metricsStr = "Comparisons: " + std::to_string(mComparisons) +
                            " | Nodes Visited: " + std::to_string(mNodesVisited) +
                            " | Progress: " + std::to_string(mCurrentActionIndex) + "/" + std::to_string(mActions.size());
    mMetricsText.setString(metricsStr);
    mWindow.draw(mMetricsText);
    mWindow.draw(mSpeedText);  // Draw speed text

    mInstructionsText.setFillColor(sf::Color::Yellow);
    mWindow.draw(mInstructionsText);

    renderUI();
    mWindow.display();
}

void Visualizer::renderArray() {
    const float BAR_WIDTH = 15.f;
    const float BAR_SPACING = 2.f;
    const float MAX_BAR_HEIGHT = 400.f;
    const float BASE_Y = mWindow.getSize().y - 100.f;

    for (size_t i = 0; i < mData.size(); ++i) {
        float height = (mData[i] / 100.0f) * MAX_BAR_HEIGHT;
        float x = 50.f + i * (BAR_WIDTH + BAR_SPACING);
        float y = BASE_Y - height;

        x = mAnimationManager.getCurrentPosition(i, x);

        sf::RectangleShape bar(sf::Vector2f(BAR_WIDTH, height));
        bar.setPosition(x, y);
        bar.setFillColor(mThemeManager.getBarColor(mData[i]));
        mWindow.draw(bar);

        // Draw value on top of bar
        sf::Text valueText;
        valueText.setFont(mFont);
        valueText.setString(std::to_string(mData[i]));
        valueText.setCharacterSize(12);
        valueText.setFillColor(sf::Color::White);
        valueText.setPosition(x + BAR_WIDTH/2 - valueText.getLocalBounds().width/2,
                            y - 20);
        mWindow.draw(valueText);
    }
}

void Visualizer::renderGraph() {
    const float NODE_RADIUS = 20.f;
    const float CENTER_X = mWindow.getSize().x / 2.f;
    const float CENTER_Y = mWindow.getSize().y / 2.f;
    const float RADIUS = 200.f;

    // Calculate node positions if not already calculated
    if (mNodePositions.empty()) {
        float angleStep = 2 * M_PI / mGraph.size();
        for (size_t i = 0; i < mGraph.size(); ++i) {
            float angle = i * angleStep;
            float x = CENTER_X + RADIUS * std::cos(angle);
            float y = CENTER_Y + RADIUS * std::sin(angle);
            mNodePositions.push_back(sf::Vector2f(x, y));
        }
        mVisitedNodes.resize(mGraph.size(), false);
    }

    // Draw edges
    for (size_t i = 0; i < mGraph.size(); ++i) {
        for (int neighbor : mGraph[i]) {
            sf::Color edgeColor = sf::Color(100, 100, 100);  // Default gray

            // Check if this edge is part of the current traversal
            if (mCurrentActionIndex > 0 && mCurrentActionIndex <= mActions.size()) {
                const Action& action = mActions[mCurrentActionIndex - 1];
                if ((action.index1 == i && action.index2 == neighbor) ||
                    (action.index1 == neighbor && action.index2 == i)) {
                    switch (action.type) {
                        case ActionType::Compare:
                            edgeColor = sf::Color::Cyan;     // Edge being considered
                            break;
                        case ActionType::TreeEdge:
                            edgeColor = sf::Color::Green;    // Tree edge (discovery)
                            break;
                        case ActionType::BackEdge:
                            edgeColor = sf::Color::Red;      // Back edge (cycle)
                            break;
                        default:
                            break;
                    }
                }
            }

            sf::Vertex line[] = {
                sf::Vertex(mNodePositions[i], edgeColor),
                sf::Vertex(mNodePositions[neighbor], edgeColor)
            };
            mWindow.draw(line, 2, sf::Lines);
        }
    }

    // Draw nodes
    for (size_t i = 0; i < mGraph.size(); ++i) {
        sf::CircleShape node(NODE_RADIUS);
        node.setPosition(mNodePositions[i].x - NODE_RADIUS,
                        mNodePositions[i].y - NODE_RADIUS);
        
        // Set node color based on state
        sf::Color nodeColor = sf::Color::White;  // Unvisited

        if (mCurrentActionIndex > 0 && mCurrentActionIndex <= mActions.size()) {
            const Action& action = mActions[mCurrentActionIndex - 1];
            if (action.index1 == i) {
                switch (action.type) {
                    case ActionType::Visit:
                        nodeColor = sf::Color::Yellow;  // Currently being visited
                        mVisitedNodes[i] = true;
                        break;
                    case ActionType::Exit:
                        nodeColor = sf::Color::Green;   // Finished visiting
                        break;
                    default:
                        break;
                }
            }
        }
        
        if (mVisitedNodes[i] && nodeColor == sf::Color::White) {
            nodeColor = sf::Color(150, 150, 150);  // Previously visited
        }
        
        node.setFillColor(nodeColor);
        node.setOutlineThickness(2);
        node.setOutlineColor(sf::Color::Black);
        mWindow.draw(node);

        // Draw node number
        sf::Text text;
        text.setFont(mFont);
        text.setString(std::to_string(i));
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
        sf::FloatRect textBounds = text.getLocalBounds();
        text.setPosition(mNodePositions[i].x - textBounds.width/2,
                        mNodePositions[i].y - textBounds.height/2);
        mWindow.draw(text);
    }
}

void Visualizer::renderUI() {
    mUIManager.render(mWindow);
}

void Visualizer::nextStep() {
    if (mCurrentActionIndex >= mActions.size()) {
        mIsPlaying = false;
        mPlayButton->setText("Restart");
        return;
    }

    const Action& action = mActions[mCurrentActionIndex++];
    switch (action.type) {
        case ActionType::Compare:
            mComparisons++;
            break;
        case ActionType::Swap:
            mSwaps++;
            if (!mIsGraphMode) {
                float x1 = 50.f + action.index1 * 17.f;
                float x2 = 50.f + action.index2 * 17.f;
                mAnimationManager.startSwapAnimation(
                    action.index1, action.index2,
                    x1, x2, x2, x1,
                    action.value1, action.value2,
                    0.5f / mPlaybackSpeed
                );
                std::swap(mData[action.index1], mData[action.index2]);
            }
            break;
        case ActionType::Visit:
            mNodesVisited++;
            if (mIsGraphMode && action.index1 < mVisitedNodes.size()) {
                mVisitedNodes[action.index1] = true;
            }
            break;
        case ActionType::Set:
            if (!mIsGraphMode) {
                mData[action.index1] = action.value1;
            }
            break;
        case ActionType::TreeEdge:
        case ActionType::BackEdge:
            // These are handled in renderGraph()
            break;
        case ActionType::Exit:
            // This is handled in renderGraph()
            break;
    }

    // If we've reached the end, update the play button text
    if (mCurrentActionIndex >= mActions.size()) {
        mPlayButton->setText("Restart");
    }
}

void Visualizer::loadActions(const std::vector<Action>& actions) {
    mActions = actions;
    mCurrentActionIndex = 0;
    mComparisons = 0;
    mSwaps = 0;
    mNodesVisited = 0;
    originalData = mData;
}

void Visualizer::setData(const std::vector<int>& data) {
    mData = data;
    originalData = data;
}

void Visualizer::setGraph(const Graph& graph) {
    mGraph = graph;
    mNodePositions.clear();
    mVisitedNodes = std::vector<bool>(graph.size(), false);
}

void Visualizer::saveData() {
    std::ofstream file("data.txt");
    if (file.is_open()) {
        for (int value : mData) {
            file << value << " ";
        }
        file.close();
    }
}

void Visualizer::loadData() {
    std::vector<int> loadedData;
    std::ifstream file("data.txt");
    if (file.is_open()) {
        int value;
        while (file >> value) {
            loadedData.push_back(value);
        }
        file.close();
        if (!loadedData.empty()) {
            setData(loadedData);
        }
    }
}

void Visualizer::updatePlayButtonText() {
    if (mCurrentActionIndex >= mActions.size()) {
        mPlayButton->setText("Restart");
    } else {
        mPlayButton->setText(mIsPlaying ? "Pause" : "Play");
    }
    // Update speed text with better formatting
    std::string speedStr = "Speed: " + std::to_string(mPlaybackSpeed).substr(0, 4) + "x";
    mSpeedText.setString(speedStr);
} 