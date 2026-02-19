#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
public:
    int v;
    list<int> *l;

    Graph(int vertex)
    {
        v = vertex;
        l = new list<int>[v];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfsHelper(int src, vector<bool> &visited) //src -> start
    {
        cout << src << " ";
        visited[src] = true;

        for (int v : l[src])
        {
            if (!visited[v])
            {
                dfsHelper(v, visited);
            }
        }
    }

    void dfs()
    {
        int src = 0;
        vector<bool> visited(v, false);
        dfsHelper(src, visited);
        cout << endl; // ✅ print newline once at the end
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    

    g.dfs(); // DFS starting from 0
}
