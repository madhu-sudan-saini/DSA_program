#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<map>
#include<climits>
using namespace std;

class Graph
{
  public:
  int v;
  list<pair<int,int>> *l; //node,weight
  
  Graph(int vertex)
  {
    v=vertex;
    l=new list<pair<int,int>> [v];
  }
  
  void addEdge(int u,int v,int w)
  {
    l[u].push_back({v,w});
  }
  
  void dijastra(int src)
  {
    priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>> > pq; //queue -> {dict,node}
    vector<int> dict(v,INT_MAX);
    
    dict[src]=0;
    pq.push({0,src});
    
    while(pq.size() > 0)
    {
      int u=pq.top().second;
      int currdict=pq.top().first;
      pq.pop();
      
      for(auto edge: l[u])
      {
        int v=edge.first;
        int weight=edge.second;
        
        if(dict[v] > currdict + weight)
        {
          dict[v]=currdict + weight;
          pq.push({dict[v],v});
        }
      }
      
    }
    
    for(int i=0;i<v;i++)
    {
      cout<<i<<"  "<<dict[i]<<endl;
    }
    
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
  
  g.dijastra(0);
  return 0;
}   