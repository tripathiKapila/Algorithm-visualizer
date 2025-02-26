#include "Visualizer.hpp"
#include "Button.hpp"
#include "UIManager.hpp"
#include "InputManager.hpp"
#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

Visualizer::Visualizer(unsigned int width, unsigned int height)
    : mWindow(sf::VideoMode(width, height), "Algorithm Visualizer")
{
    if (!mFont.loadFromFile("assets/fonts/OpenSans-Regular.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }

    // Setup UI Buttons.
    mPlayButton = std::make_shared<Button>(
        sf::Vector2f(100.f, 40.f),
        sf::Vector2f(10.f, height - 50.f),
        mFont, "Play", 18
    );
    mRestartButton = std::make_shared<Button>(
        sf::Vector2f(100.f, 40.f),
        sf::Vector2f(120.f, height - 50.f),
        mFont, "Restart", 18
    );
    mBackButton = std::make_shared<Button>(
        sf::Vector2f(100.f, 40.f),
        sf::Vector2f(230.f, height - 50.f),
        mFont, "Menu", 18
    );

    // Rewind and FastForward buttons.
    mRewindButton = std::make_shared<Button>(
        sf::Vector2f(100.f, 40.f),
        sf::Vector2f(340.f, height - 50.f),
        mFont, "Rewind", 18
    );
    mFastForwardButton = std::make_shared<Button>(
        sf::Vector2f(100.f, 40.f),
        sf::Vector2f(450.f, height - 50.f),
        mFont, "Fwd", 18
    );

    // Optional tooltips.
    mPlayButton->setTooltip("Toggle play/pause");
    mRestartButton->setTooltip("Restart the visualization");
    mBackButton->setTooltip("Return to menu");
    mRewindButton->setTooltip("Rewind the visualization");
    mFastForwardButton->setTooltip("Fast-forward the visualization");

    // Button callbacks.
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
        mData = originalData;
        mCurrentActionIndex = 0;
        mComparisons = 0;
        mSwaps = 0;
        mNodesVisited = 0;
        mNodePositions.clear();
        mAnimationManager.reset();
        if (mIsGraphMode)
            mVisitedNodes.assign(mGraph.size(), false);
    });

    mBackButton->setCallback([this]() {
        mReturnToMenu = true;
        std::cout << "Returning to menu." << std::endl;
    });

    // Rewind button: jump back 5 actions and reapply actions.
    mRewindButton->setCallback([this]() {
        if (mCurrentActionIndex > 0) {
            mCurrentActionIndex = (mCurrentActionIndex > 5 ? mCurrentActionIndex - 5 : 0);
            reapplyActionsUntil(mCurrentActionIndex);
            std::cout << "Rewound to action index " << mCurrentActionIndex << std::endl;
        }
    });

    // FastForward button: jump forward 5 actions and reapply actions.
    mFastForwardButton->setCallback([this]() {
        if (mCurrentActionIndex < mActions.size()) {
            mCurrentActionIndex = std::min(mActions.size() - 1, mCurrentActionIndex + 5);
            reapplyActionsUntil(mCurrentActionIndex);
            std::cout << "Fast forwarded to action index " << mCurrentActionIndex << std::endl;
        }
    });

    // Add buttons to UI manager.
    mUIManager.addButton(mPlayButton);
    mUIManager.addButton(mRestartButton);
    mUIManager.addButton(mBackButton);
    mUIManager.addButton(mRewindButton);
    mUIManager.addButton(mFastForwardButton);

    // Setup text for metrics and instructions.
    mMetricsText.setFont(mFont);
    mMetricsText.setCharacterSize(16);
    mMetricsText.setFillColor(sf::Color::White);
    mMetricsText.setPosition(10.f, 10.f);

    // Multi-line instructions to prevent a long single line.
    mInstructionsText.setFont(mFont);
    mInstructionsText.setCharacterSize(14);
    mInstructionsText.setFillColor(sf::Color::White);
    // We'll place this in updateLayout() so it doesn't overlap.
    // Just set a default position for now:
    mInstructionsText.setPosition(10.f, height - 120.f);

    mInstructionsText.setString(
        "Controls:\n"
        "S=Save, L=Load, T=Reset\n"
        "Up=SpeedUp, Down=SpeedDown\n"
        "R=Rewind, F=FastForward\n"
        "Right=Step, Click=Modify, Menu=Return"
    );

    // Bind keys to actions.
    mInputManager.bindKey(sf::Keyboard::Right, InputAction::Step);
    mInputManager.bindKey(sf::Keyboard::S, InputAction::Save);
    mInputManager.bindKey(sf::Keyboard::L, InputAction::Load);
    mInputManager.bindKey(sf::Keyboard::R, InputAction::Rewind);
    mInputManager.bindKey(sf::Keyboard::F, InputAction::FastForward);
    mInputManager.bindKey(sf::Keyboard::Up, InputAction::SpeedUp);
    mInputManager.bindKey(sf::Keyboard::Down, InputAction::SpeedDown);
    mInputManager.bindKey(sf::Keyboard::T, InputAction::Reset);

    // Bind action callbacks.
    mInputManager.bindAction(InputAction::Step, [this]() { nextStep(); });
    mInputManager.bindAction(InputAction::Save, [this]() { saveData(); });
    mInputManager.bindAction(InputAction::Load, [this]() { loadData(); });
    mInputManager.bindAction(InputAction::Reset, [this]() {
        mData = originalData;
        mCurrentActionIndex = 0;
        mComparisons = 0;
        mSwaps = 0;
        mNodesVisited = 0;
        mNodePositions.clear();
        mAnimationManager.reset();
        if (mIsGraphMode)
            mVisitedNodes.assign(mGraph.size(), false);
    });
    mInputManager.bindAction(InputAction::SpeedUp, [this]() { mPlaybackSpeed += 0.5f; });
    mInputManager.bindAction(InputAction::SpeedDown, [this]() {
        if (mPlaybackSpeed > 0.5f)
            mPlaybackSpeed -= 0.5f;
    });
    mInputManager.bindAction(InputAction::Rewind, [this]() {
        if (mCurrentActionIndex > 0) {
            mCurrentActionIndex = (mCurrentActionIndex > 5 ? mCurrentActionIndex - 5 : 0);
            reapplyActionsUntil(mCurrentActionIndex);
            std::cout << "Rewound to action index " << mCurrentActionIndex << std::endl;
        }
    });
    mInputManager.bindAction(InputAction::FastForward, [this]() {
        if (mCurrentActionIndex < mActions.size()) {
            mCurrentActionIndex = std::min(mActions.size() - 1, mCurrentActionIndex + 5);
            reapplyActionsUntil(mCurrentActionIndex);
            std::cout << "Fast forwarded to action index " << mCurrentActionIndex << std::endl;
        }
    });
}

void Visualizer::setData(const std::vector<int>& data) {
    mData = data;
    originalData = data;
    mNodePositions.clear();
}

void Visualizer::setGraph(const Graph& graph) {
    mGraph = graph;
    mNodePositions.clear();
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
    for (int val : mData)
        ofs << val << " ";
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
    while (ifs >> val)
        mData.push_back(val);
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
    mAnimationManager.update(deltaTime.asSeconds());
    static float accumulator = 0.f;
    if (!mAnimationManager.isActive() && mIsPlaying) {
        accumulator += deltaTime.asSeconds();
        if (accumulator >= (1.f / mPlaybackSpeed)) {
            nextStep();
            accumulator = 0.f;
        }
    }
}

void Visualizer::nextStep() {
    if (mAnimationManager.isActive())
        return;
    if (mCurrentActionIndex >= mActions.size()) {
        std::cout << "All actions processed. Restarting simulation..." << std::endl;
        mData = originalData;
        mCurrentActionIndex = 0;
        mComparisons = 0;
        mSwaps = 0;
        mNodesVisited = 0;
        mNodePositions.clear();
        mAnimationManager.reset();
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
        {
            mSwaps++;
            float barWidth = static_cast<float>(mWindow.getSize().x) / mData.size();
            float startX1 = action.index1 * barWidth;
            float startX2 = action.index2 * barWidth;
            float targetX1 = action.index2 * barWidth;
            float targetX2 = action.index1 * barWidth;
            mAnimationManager.startSwapAnimation(
                action.index1, action.index2,
                startX1, startX2, targetX1, targetX2,
                mData[action.index1], mData[action.index2],
                0.5f
            );
            mCurrentActionIndex++;
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
            if (mIsGraphMode && action.index1 < mVisitedNodes.size())
                mVisitedNodes[action.index1] = true;
            mCurrentActionIndex++;
            break;
    }
}

//
// UPDATED: Dynamically position the instructions text above the buttons.
//
void Visualizer::updateLayout() {
    sf::Vector2u winSize = mWindow.getSize();

    // Position the buttons at the bottom.
    mPlayButton->setPosition(sf::Vector2f(10.f,  winSize.y - 50.f));
    mRestartButton->setPosition(sf::Vector2f(120.f, winSize.y - 50.f));
    mBackButton->setPosition(sf::Vector2f(230.f, winSize.y - 50.f));
    mRewindButton->setPosition(sf::Vector2f(340.f, winSize.y - 50.f));
    mFastForwardButton->setPosition(sf::Vector2f(450.f, winSize.y - 50.f));

    // Measure the instructions text's local bounds
    sf::FloatRect textBounds = mInstructionsText.getLocalBounds();
    float textHeight = textBounds.height;

    // We'll leave a small gap (e.g., 10 px) above the buttons
    float gap = 10.f;
    // The Y position of the button row is (winSize.y - 50.f)
    // So let's position the instructions text above that row, minus a gap
    float newY = (float)winSize.y - 50.f - gap - textHeight;
    mInstructionsText.setPosition(10.f, newY);
}

void Visualizer::render() {
    mWindow.clear(mThemeManager.getBackgroundColor());
    if (mIsGraphMode)
        renderGraph();
    else
        renderArray();
    renderUI();
    mWindow.display();
}

void Visualizer::renderArray() {
    float barWidth = static_cast<float>(mWindow.getSize().x) / mData.size();
    for (std::size_t i = 0; i < mData.size(); ++i) {
        sf::RectangleShape bar;
        float barHeight = static_cast<float>(mData[i] * 3);
        float defaultX = i * barWidth;
        float xPos = mAnimationManager.getCurrentPosition(i, defaultX);
        bar.setSize(sf::Vector2f(barWidth - 1, barHeight));
        bar.setPosition(xPos, 300.f - barHeight);
        bar.setFillColor(mThemeManager.getBarColor(mData[i]));
        mWindow.draw(bar);
    }
}

void Visualizer::renderGraph() {
    std::vector<sf::Color> palette = {
        sf::Color(52, 152, 219),
        sf::Color(46, 204, 113),
        sf::Color(155, 89, 182),
        sf::Color(241, 196, 15),
        sf::Color(230, 126, 34),
        sf::Color(231, 76, 60),
        sf::Color(26, 188, 156),
        sf::Color(149, 165, 166),
        sf::Color(52, 73, 94)
    };
    if (mNodePositions.empty() && !mData.empty()) {
        int n = static_cast<int>(mData.size());
        float centerX = mWindow.getSize().x / 2.f;
        float centerY = mWindow.getSize().y / 2.f;
        float radius = std::min(centerX, centerY) - 50.f;
        for (int i = 0; i < n; i++) {
            float angle = (2 * 3.14159265f * i) / n;
            float x = centerX + radius * std::cos(angle);
            float y = centerY + radius * std::sin(angle);
            mNodePositions.push_back(sf::Vector2f(x, y));
        }
    }
    // Draw edges
    for (size_t i = 0; i < mGraph.size(); ++i) {
        for (int neighbor : mGraph[i]) {
            if (static_cast<int>(i) < neighbor && neighbor < static_cast<int>(mNodePositions.size())) {
                sf::Vertex line[] = {
                    sf::Vertex(mNodePositions[i], sf::Color::White),
                    sf::Vertex(mNodePositions[neighbor], sf::Color::White)
                };
                mWindow.draw(line, 2, sf::Lines);
            }
        }
    }
    // Draw nodes
    for (size_t i = 0; i < mData.size(); ++i) {
        sf::CircleShape circle(20.f);
        circle.setOrigin(20.f, 20.f);
        circle.setPosition(mNodePositions[i]);
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
    ss << "Comparisons: " << mComparisons
       << "\nSwaps: " << mSwaps
       << "\nNodes Visited: " << mNodesVisited;
    mMetricsText.setString(ss.str());
    mWindow.draw(mMetricsText);
    mWindow.draw(mInstructionsText);
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

// Reapply actions to restore an earlier state
void Visualizer::reapplyActionsUntil(std::size_t endIndex) {
    mData = originalData;
    mComparisons = 0;
    mSwaps = 0;
    mNodesVisited = 0;
    mAnimationManager.reset();
    
    if (mIsGraphMode) {
        mVisitedNodes.assign(mGraph.size(), false);
    }

    for (std::size_t i = 0; i < endIndex && i < mActions.size(); ++i) {
        const Action& action = mActions[i];
        switch (action.type) {
            case ActionType::Compare:
                mComparisons++;
                break;
            case ActionType::Swap:
                mSwaps++;
                if (action.index1 < mData.size() && action.index2 < mData.size())
                    std::swap(mData[action.index1], mData[action.index2]);
                break;
            case ActionType::Set:
                if (action.index1 < mData.size())
                    mData[action.index1] = action.value1;
                break;
            case ActionType::Visit:
                mNodesVisited++;
                if (mIsGraphMode && action.index1 < mVisitedNodes.size())
                    mVisitedNodes[action.index1] = true;
                break;
        }
    }
}
