#include <iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Graph
{
    public:
    unordered_map<int, list<int> > adj;
    
    void addEdge(int u, int v, bool direction)
    {
        //direction 0 => undirected Graph
        //direction 1 => directed Graph
        
        //create an edge from u to v
        adj[u].push_back(v);
        
        if(direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    
    void printAdjList()
    {
        for(auto i:adj)
        {
            cout << i.first << "->";
            for(auto j:i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes " << endl;
    cin >> n;
    
    int m;
    cout << "Enter the number of edges " << endl;
    cin >> m;
    
    Graph g;
    
    for(int i=0 ;i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        //created an undirected graph
        g.addEdge(u, v, 0);
    }
    
    //print graph
    
    g.printAdjList();
    
    return 0;
}

    
Enter the number of nodes: 5
Enter Enter the number of edges 
the number of edges: 6
Enter edge 1: 0 1
Enter edge 2: 0 4
Enter edge 3: 1 2
Enter edge 4: 1 3
Enter edge 5: 1 4
Enter edge 6: 3 4

0->1 4 
1->0 2 3 4 
4->0 1 3 
2->1 
3->1 4 


