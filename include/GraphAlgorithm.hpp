#ifndef GRAPH_ALGORITHM_HPP
#define GRAPH_ALGORITHM_HPP

#include "Algorithm.hpp"
#include <vector>

using Graph = std::vector<std::vector<int>>;

class GraphAlgorithm : public Algorithm {
public:
    GraphAlgorithm(const Graph& graph) : mGraph(graph) {}
protected:
    const Graph& mGraph;
    std::vector<Action> mActions;
    
    void logCompare(int index1, int index2, int value1, int value2) {
        mActions.push_back(Action(ActionType::Compare, index1, index2, value1, value2));
    }
    void logVisit(int index) {
        mActions.push_back(Action(ActionType::Visit, index));
    }

    void logTreeEdge(int from, int to) {
        mActions.push_back(Action(ActionType::TreeEdge, from, to));
    }

    void logBackEdge(int from, int to) {
        mActions.push_back(Action(ActionType::BackEdge, from, to));
    }

    void logExit(int index) {
        mActions.push_back(Action(ActionType::Exit, index));
    }
};

#endif // GRAPH_ALGORITHM_HPP 