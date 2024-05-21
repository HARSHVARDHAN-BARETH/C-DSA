#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;

    // Recursive call for every connected node
    for(auto i: adj[node])
    {
        if(!visited[i])
        {
            dfs(i, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Create adjacency list
    unordered_map<int, list<int>> adj;

    // Prepare adjacency list
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    // Find all connected components
    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main()
{
    int V = 5; // Number of vertices
    int E = 3; // Number of edges
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};

    vector<vector<int>> components = depthFirstSearch(V, E, edges);

    cout << "Connected Components:" << endl;
    for(const auto& component : components)
    {
        for(int node : component)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
