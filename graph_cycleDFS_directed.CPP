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
  }

  bool isCycleundidfs(int src,vector<bool> &visited,vector<bool> &recpath)
  {
    visited[src]=true;
    recpath[src]=true;
    
    for(int v : l[src])
    {
      if(!visited[v])
      {
        if(isCycleundidfs(v,visited,recpath))
        {
          return true;
        }
      }
      else if(recpath[v]) //Cycle detect
      {
        return true;
      }
    }
    recpath[src]=false;
    return false;
  }
  
  bool isCycle()
  {
    vector<bool> visited(v,false);
    vector<bool> recpath(v,false);
    
    for(int i=0;i<v;i++)
    {
      if(!visited[i])
      {
        if(isCycleundidfs(i,visited,recpath))
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

  g.addEdge(1,0);
  g.addEdge(0,2);
  g.addEdge(2,3);
  g.addEdge(3,1);

  cout << "Cycle detect or not : " << g.isCycle();
  return 0;
}
