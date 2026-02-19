#include<iostream>
#include<list>
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
    l[v].push_back(u);
  }

  void display()
  {
    for(int i=0;i<v;i++)
    {
      cout<<i<<" :";

      for(int v: l[i])
      {
        cout<<v<<" ";
      }
      cout<<endl;
    }
  }
};
int main()
{
  Graph g(6);

  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(1,3);
  g.addEdge(2,3);
  g.addEdge(2,4);
  g.addEdge(4,5);

  g.display();
  return 0;
}