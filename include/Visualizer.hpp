#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Action.hpp"
#include "GraphAlgorithm.hpp"
#include "UIManager.hpp"
#include "InputManager.hpp"
#include <memory>
#include "AnimationManager.hpp"
#include "ThemeManager.hpp"

class Visualizer {
public:
    Visualizer(unsigned int width, unsigned int height);
    void run();
    void loadActions(const std::vector<Action>& actions);
    void setData(const std::vector<int>& data);
    void setGraph(const Graph& graph);
    void saveData();
    void loadData();
    void setGraphMode(bool isGraph) { mIsGraphMode = isGraph; }

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void renderArray();
    void renderGraph();
    void renderUI();
    void nextStep();
    void updateLayout();
    void handleBarClick(sf::Vector2f mousePos);
    void reapplyActionsUntil(std::size_t endIndex);
    void updatePlayButtonText();

    sf::RenderWindow mWindow;
    sf::Font mFont;
    std::vector<int> mData;
    std::vector<int> originalData;
    std::vector<Action> mActions;
    std::size_t mCurrentActionIndex = 0;

    Graph mGraph;
    std::vector<sf::Vector2f> mNodePositions;
    std::vector<bool> mVisitedNodes;

    unsigned int mComparisons = 0;
    unsigned int mSwaps = 0;
    unsigned int mNodesVisited = 0;

    bool mIsPlaying = false;
    float mPlaybackSpeed = 1.0f;

    UIManager mUIManager;
    std::shared_ptr<class Button> mPlayButton;
    std::shared_ptr<class Button> mRestartButton;
    std::shared_ptr<class Button> mBackButton;
    std::shared_ptr<class Button> mRewindButton;
    std::shared_ptr<class Button> mFastForwardButton;

    sf::Text mMetricsText;
    sf::Text mInstructionsText;
    sf::Text mSpeedText;

    bool mIsGraphMode = false;

    InputManager mInputManager;

    AnimationManager mAnimationManager;
    ThemeManager mThemeManager;

    bool mReturnToMenu = false;
};

#endif // VISUALIZER_HPP 