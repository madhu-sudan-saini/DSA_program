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

    bool isCycleDfs(int u, int parent,vector<bool> &visited) //u -> start
    {
        visited[u] = true;

        for (int v : l[u])
        {
            if (!visited[v])
            {
                if(isCycleDfs(v, u,visited))
                {
                    return true;
                }
            }
            else if(parent !=v)
            {
                return true;
            }
        }
        return false;
    }

    bool isCycle()
    {
        int src = 0;
        vector<bool> visited(v, false);
        int parent;
        
        if(isCycleDfs(src, parent,visited))
        {
            return true;
        }
        else
        {
            return false;
        }
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
    

    cout<<"cycle detect or not :"<<g.isCycle()<<endl;; // DFS starting from 0
}
