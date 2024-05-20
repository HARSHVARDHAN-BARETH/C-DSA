#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <list>

// Use the standard namespace for simplicity
using namespace std;

// Function to prepare the adjacency list from the list of edges
void prepareAdjList(unordered_map<int, list<int>>& adjList, vector<pair<int, int>>& edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

// BFS traversal from a given node
void bfs(unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited, vector<int>& ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        // Store the front node into the answer
        ans.push_back(frontNode);

        // Traverse all neighbors of the front node
        for (auto neighbor : adjList[frontNode]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

// Function to return the BFS traversal of the graph
vector<int> bfsTraversal(int vertex, vector<pair<int, int>> edges) {
    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // Traverse all components of the graph
    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

// Main function to test the BFS traversal
int main() {
    int vertex = 5;
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}
    };

    vector<int> result = bfsTraversal(vertex, edges);

    // Print the BFS traversal result
    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
