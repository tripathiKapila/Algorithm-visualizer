#include "DFS.hpp"

DFS::DFS(const Graph& graph) : GraphAlgorithm(graph) {}

std::vector<Action> DFS::run() {
    mActions.clear();
    if (mGraph.empty()) return mActions;
    std::vector<bool> visited(mGraph.size(), false);
    dfs(0, visited);
    return mActions;
}

void DFS::dfs(int node, std::vector<bool>& visited) {
    visited[node] = true;
    logVisit(node);
    for (int neighbor : mGraph[node]) {
        logCompare(node, neighbor, 0, 0);
        if (!visited[neighbor]) {
            dfs(neighbor, visited);
        }
    }
}
