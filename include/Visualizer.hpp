#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Action.hpp"
#include "GraphAlgorithm.hpp"  // For the Graph typedef.
#include "UIManager.hpp"
#include "InputManager.hpp"
#include <memory>

class Visualizer {
public:
    Visualizer(unsigned int width, unsigned int height);
    void run();
    void loadActions(const std::vector<Action>& actions);
    void setData(const std::vector<int>& data);

    // For graph visualization: pass the graph structure.
    void setGraph(const Graph& graph);

    // Save and load the current data array to/from a file.
    void saveData();
    void loadData();

    // Set graph mode to render nodes and edges.
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
    float lerp(float a, float b, float t);

    sf::RenderWindow mWindow;
    sf::Font mFont;
    std::vector<int> mData;
    std::vector<int> originalData;  // For resetting to original data.
    std::vector<Action> mActions;
    std::size_t mCurrentActionIndex = 0;

    // Graph data (if in graph mode).
    Graph mGraph;
    std::vector<sf::Vector2f> mNodePositions;

    // NEW: Visited nodes tracking for graph mode.
    std::vector<bool> mVisitedNodes;

    // Metrics for display.
    unsigned int mComparisons = 0;
    unsigned int mSwaps = 0;
    unsigned int mNodesVisited = 0;

    // Playback control.
    bool mIsPlaying = false;
    float mPlaybackSpeed = 1.0f; // Steps per second.

    // UI elements managed by UIManager.
    UIManager mUIManager;
    std::shared_ptr<class Button> mPlayButton;
    std::shared_ptr<class Button> mRestartButton;
    std::shared_ptr<class Button> mBackButton; // NEW: Button to return to menu.
    sf::Text mMetricsText;
    sf::Text mInstructionsText;

    // Graph mode flag.
    bool mIsGraphMode = false;

    // Input Manager for centralized event processing.
    InputManager mInputManager;

    // Swap Animation structure for smooth swaps.
    struct SwapAnimation {
        bool active = false;
        int index1 = -1;
        int index2 = -1;
        float elapsed = 0.f;
        float duration = 0.5f;
        float startX1 = 0.f;
        float startX2 = 0.f;
        float targetX1 = 0.f;
        float targetX2 = 0.f;
        int value1 = 0;
        int value2 = 0;
    } mSwapAnimation;
    
    // NEW: Flag to return to menu.
    bool mReturnToMenu = false;
};

#endif // VISUALIZER_HPP
