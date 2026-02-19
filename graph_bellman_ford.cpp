#include<iostream>
#include<list>
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
    }

    void bellmanFord(int src)
    {
        vector<int> dist(v, INT_MAX);
        dist[src] = 0;

        // Relax all edges V-1 times
        for (int i = 1; i <= v - 1; i++)
        {
            for (int u = 0; u < v; u++)
            {
                for (auto edge : l[u])
                {
                    int v = edge.first;
                    int weight = edge.second;

                    if (dist[v] > dist[u] + weight)
                    {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        cout << "Vertex  Distance from Source\n";
        for (int i = 0; i < v; i++)
        {
            cout << i << "       " << dist[i] << endl;
        }
    }
};

int main()
{
    Graph g(6);

    g.addEdge(0,1,2);
    g.addEdge(0,2,4);
    g.addEdge(1,2,-2);
    g.addEdge(1,3,7);
    g.addEdge(2,4,3);
    g.addEdge(3,5,-1);
    g.addEdge(4,3,2);
    g.addEdge(4,5,5);

    g.bellmanFord(0);

    return 0;
}
