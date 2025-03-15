#ifndef BFS_HPP
#define BFS_HPP

#include "GraphAlgorithm.hpp"
#include <queue>

class BFS : public GraphAlgorithm {
public:
    BFS(const Graph& graph);
    std::vector<Action> run() override;
};

#endif // BFS_HPP 