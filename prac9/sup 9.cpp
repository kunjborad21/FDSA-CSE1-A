#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    int vertices;
    vector<vector<int>> adj;

public:
    Graph(int v)
    {
        vertices = v;
        adj.resize(v);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool DFS(int current, int parent, vector<bool>& visited)
    {
        visited[current] = true;

        for (int i = 0; i < adj[current].size(); i++)
        {
            int next = adj[current][i];

            if (!visited[next])
            {
                if (DFS(next, current, visited))
                {
                    return true;
                }
            }
            else if (next != parent)
            {
                return true;
            }
        }

        return false;
    }

    bool hasCycle()
    {
        vector<bool> visited(vertices, false);

        for (int i = 0; i < vertices; i++)
        {
            if (!visited[i])
            {
                if (DFS(i, -1, visited))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(3, 4);

    if (g.hasCycle())
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}