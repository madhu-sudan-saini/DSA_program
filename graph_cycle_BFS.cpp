#include<iostream>
#include<list>
#include<vector>
#include<queue>
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

  bool isCycleBfs(int src, vector<bool> &visited)
  {
    queue<pair<int,int>> q;
    q.push({src, -1});
    visited[src] = true;

    while(!q.empty())
    {
      int u = q.front().first;
      int parU = q.front().second;
      q.pop();  

      for(int v : l[u])
      {
        if(!visited[v])
        {
          visited[v] = true;
          q.push({v, u});
        }
        else if(v != parU)
        {
          return true;
        }
      }
    }
    return false;
  }

  bool isCycle()
  {
    vector<bool> visited(v, false);

    for(int i = 0; i < v; i++)
    {
      if(!visited[i])
      {
        if(isCycleBfs(i, visited))
          return true;
      }
    }
    return false;
  }
};

int main()
{
  Graph g(5);

  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(0,3);
  g.addEdge(1,2);
  g.addEdge(3,4);

  cout << "Cycle detect or not : " << g.isCycle();
  return 0;
}
