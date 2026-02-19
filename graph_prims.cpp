#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

class Graph
{
public:
    int v;
    list<pair<int,int>> *l; // node, weight

    Graph(int vertex)
    {
        v = vertex;
        l = new list<pair<int,int>>[v];
    }

    void addEdge(int u, int v, int w)
    {
        l[u].push_back({v, w});
        l[v].push_back({u, w}); // undirected graph
    }

    void primMST(int src)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // {weight, node}

        vector<int> key(v, INT_MAX);
        vector<bool> mst(v, false);
        vector<int> parent(v, -1);

        key[src] = 0;
        pq.push({0, src});

        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            
            mst[u] = true;

            for(auto edge : l[u])
            {
                int v = edge.first;
                int wt = edge.second;

                if(!mst[v] && wt < key[v])
                {
                    key[v] = wt;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }

        int cost = 0;
        cout << "Edges in MST:\n";
        for(int i = 1; i < v; i++)
        {
            cout << parent[i] << " - " << i << " : " << key[i] << endl;
            cost += key[i];
        }

        cout << "Total cost = " << cost << endl;
    }
};

int main()
{
    Graph g(6);

    g.addEdge(0,1,2);
    g.addEdge(0,2,4);
    g.addEdge(1,2,1);
    g.addEdge(1,3,7);
    g.addEdge(2,4,3);
    g.addEdge(3,5,1);
    g.addEdge(4,3,2);
    g.addEdge(4,5,5);

    g.primMST(0);
    return 0;
}
