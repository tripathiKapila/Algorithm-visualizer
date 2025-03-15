#include "BFS.hpp"

BFS::BFS(const Graph& graph) : GraphAlgorithm(graph) {}

std::vector<Action> BFS::run() {
    mActions.clear();
    if (mGraph.empty()) return mActions;
    std::vector<bool> visited(mGraph.size(), false);
    std::queue<int> q;
    int startNode = 0;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        logVisit(node);
        for (int neighbor : mGraph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                logCompare(node, neighbor, 0, 0);
            }
        }
    }
    return mActions;
} 