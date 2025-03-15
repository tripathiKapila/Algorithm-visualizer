#ifndef DFS_HPP
#define DFS_HPP

#include "GraphAlgorithm.hpp"
#include <vector>

class DFS : public GraphAlgorithm {
public:
    DFS(const Graph& graph);
    std::vector<Action> run() override;
private:
    void dfs(int node, std::vector<bool>& visited, std::vector<bool>& inStack);
};

#endif // DFS_HPP 