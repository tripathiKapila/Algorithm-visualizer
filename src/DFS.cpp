#include "DFS.hpp"

DFS::DFS(const Graph& graph) : GraphAlgorithm(graph) {}

std::vector<Action> DFS::run() {
    mActions.clear();
    if (mGraph.empty()) return mActions;
    std::vector<bool> visited(mGraph.size(), false);
    std::vector<bool> inStack(mGraph.size(), false);  // Track nodes in current path
    dfs(0, visited, inStack);
    return mActions;
}

void DFS::dfs(int node, std::vector<bool>& visited, std::vector<bool>& inStack) {
    visited[node] = true;
    inStack[node] = true;  // Mark node as being in current path
    
    // Log that we're visiting this node
    logVisit(node);

    for (int neighbor : mGraph[node]) {
        // First, show we're considering this edge
        logCompare(node, neighbor, 0, 0);
        
        if (!visited[neighbor]) {
            // This is a tree edge - we're discovering a new node
            logTreeEdge(node, neighbor);
            dfs(neighbor, visited, inStack);
        }
        else if (inStack[neighbor]) {
            // This is a back edge - we found a cycle
            logBackEdge(node, neighbor);
        }
    }
    
    inStack[node] = false;  // Remove node from current path
    // Log that we're done with this node
    logExit(node);
} 