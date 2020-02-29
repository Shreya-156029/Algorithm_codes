#include<bits/stdc++.h>
using namespace std;
class Graph
{
   int V;
   list<int> *adj;
   public:
  Graph(int V);
  void addedge(int v,int w);
  void topsortutil(int v,bool visited[],stack<int> &stk);
  void topsort();
};
Graph::Graph(int V)
{
  this->V=V;
  adj=new list<int>[V];
}
void Graph::addedge(int v,int w)
{
    adj[v].push_back(w);
}
void Graph::topsortutil(int v,bool visited[],stack<int> &stk)
{
    visited[v]=true;
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
    {
       if(!visited[*i])
       topsortutil(*i,visited,stk);
    }
    stk.push(v);
}
void Graph::topsort()
{


  stack<int> stk;
  bool *visited=new bool[V];
  for(int i=0;i<V;i++)
  visited[i]=false;
  for(int i=0;i<V;i++)
  {
    if(visited[i]==false)
    topsortutil(i,visited,stk);
  }
  while(stk.empty()==false)
  {
    cout<<stk.top()<<" ";
    stk.pop();
   }
}

int main()
{
	Graph g(6);
	g.addedge(5, 2);
    g.addedge(5, 0);
    g.addedge(4, 0);
    g.addedge(4, 1);
    g.addedge(2, 3);
    g.addedge(3, 1);
    g.topsort();
}
