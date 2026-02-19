#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class Graph
{
public:
    int v;
    list<int> *l;

    Graph(int n)
    {
        v = n;
        l = new list<int>[v];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfs()
    {
        queue<int> q;
        vector<bool> visited(v, false);

        q.push(0);
        visited[0] = true;

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for(int v : l[u])
            {
                if(!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
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

    g.bfs();
    return 0;
}
