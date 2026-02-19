#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<queue>
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
  
  void toposort()
  {
    vector<int> result;
    
    
    vector<int> indege(v,0);
    for(int u=0;u<v;u++)
    {
      for(int v:l[u])
      {
        indege[v]++;
      }
    }
  
  queue<int> q;
  for(int i=0;i<v;i++)
  {
    if(indege[i]==0)
    {
      q.push(i);
    }
  }
  
  while(q.size() >0)
  {
    int curr=q.front();
    q.pop();
    
    result.push_back(curr);
    
    for(int v: l[curr])
    {
      indege[v]--;
      
      if(indege[v]==0)
      {
        q.push(v);
      }
    }
  }
  
    for(int val : result)
    {
      cout<<val<<" ";
    }
    cout<<endl;
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
  
  g.toposort();
  return 0;
}