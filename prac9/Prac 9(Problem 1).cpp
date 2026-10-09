#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

    void DFS(int start)
    {
        vector<bool> visited(vertices, false);
        stack<int> s;

        s.push(start);

        cout << "DFS Traversal: ";

        while (!s.empty())
        {
            int current = s.top();
            s.pop();

            if (visited[current])
            {
                continue;
            }

            visited[current] = true;
            cout << current << " ";

            for (int i = adj[current].size() - 1; i >= 0; i--)
            {
                if (!visited[adj[current][i]])
                {
                    s.push(adj[current][i]);
                }
            }
        }

        cout << endl;
    }

    void BFS(int start)
    {
        vector<bool> visited(vertices, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        cout << "BFS Traversal: ";

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int i = 0; i < adj[current].size(); i++)
            {
                int next = adj[current][i];

                if (!visited[next])
                {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }

        cout << endl;
    }
};

int main()
{
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    int start = 0;

    g.DFS(start);
    g.BFS(start);

    return 0;
}