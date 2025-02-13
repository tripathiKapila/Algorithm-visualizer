#ifndef GRAPH_ALGORITHM_HPP
#define GRAPH_ALGORITHM_HPP

#include "Algorithm.hpp"
#include <vector>

// Graph represented as an adjacency list.
using Graph = std::vector<std::vector<int>>;

class GraphAlgorithm : public Algorithm {
public:
    GraphAlgorithm(const Graph& graph) : mGraph(graph) {}
protected:
    const Graph& mGraph;
    std::vector<Action> mActions;
    
    // Helper methods for logging.
    void logCompare(int index1, int index2, int value1, int value2) {
        mActions.push_back(Action(ActionType::Compare, index1, index2, value1, value2));
    }
    void logVisit(int index) {
        mActions.push_back(Action(ActionType::Visit, index));
    }
};

#endif // GRAPH_ALGORITHM_HPP
