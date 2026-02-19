#include<iostream>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class Graph
{
  public:
  int v;
  list<int> *l;
  
  Graph(int vertex)
  {
    v=vertex;
    l=new list<int> [v];
  }
  
  void addEdge(int u,int v)
  {
    l[u].push_back(v);
  }
  
  void dfsHelper(int u,vector<int> &visited,stack<int> &s)
  {
     visited[u]=true;
     
     for(int v: l[u])
     {
       if(!visited[v])
       {
         dfsHelper(v,visited,s);
       }
     }
    
     s.push(u);
  }
  
  void dfs()
  {
    int u=0;
    vector<int> visited(v,false);
    stack<int> s;
    
    
    for(int i=0;i<v;i++)
    {
      if(!visited[i])
      {
        dfsHelper(i,visited,s);
      }
    }
    
    while(!s.empty())
    {
      cout<<s.top()<<" ";
      s.pop();
    }
  }
  
};
int main()
{
  
  Graph g(6);
  
  g.addEdge(3,1);
  g.addEdge(4,1);
  g.addEdge(4,0);
  g.addEdge(5,0);
  g.addEdge(5,2);
  g.addEdge(2,3);
  
  g.dfs();
  return 0;
}