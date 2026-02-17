#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);

    cout << "Enter edges (u v) meaning u -> v:\n";
    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;  // Increase indegree of v
    }

    queue<int> q;

    // Push vertices with indegree 0
    for(int i = 0; i < V; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    cout << "Topological Order: ";
    int count = 0;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        count++;

        for(int neighbor : adj[node])
        {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    // Check if cycle exists
    if(count != V)
        cout << "\nGraph contains a cycle! Topological sorting not possible.";

    return 0;
}