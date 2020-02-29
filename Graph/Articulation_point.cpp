#include<iostream> 
#include <list> 
#define NIL -1 
using namespace std;
class Graph 
{ 
	int V;
	list<int> *adj;
	void artptUtil(int v,bool visited[],int disc[],int low[],int parent[],bool ap[]); 
	public: 
	Graph(int V);
	void addEdge(int v,int w);
	void artpt();
}; 
Graph::Graph(int V) 
{ 
	this->V=V; 
	adj=new list<int>[V]; 
} 
void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
	adj[w].push_back(v);
} 
void Graph::artptUtil(int u,bool visited[],int disc[],int low[],int parent[],bool ap[]) 
{ 
	static int time=0; 
	int children=0; 
	visited[u]=true; 
	disc[u]=low[u]=++time; 
	list<int>::iterator i; 
	for (i =adj[u].begin();i!=adj[u].end();++i) 
	{ 
		int v=*i; 
		if (!visited[v]) 
		{ 
			children++; 
			parent[v]=u; 
			artptUtil(v,visited,disc,low,parent,ap); 
			low[u]=min(low[u],low[v]); 
			if (parent[u] == NIL && children > 1) 
			ap[u] = true; 
			if (parent[u] != NIL && low[v] >= disc[u]) 
			ap[u] = true; 
		} 
		else if (v != parent[u]) 
			low[u] = min(low[u], disc[v]); 
	} 
}
void Graph::artpt() 
{
	bool *visited = new bool[V]; 
	int *disc = new int[V]; 
	int *low = new int[V]; 
	int *parent = new int[V]; 
	bool *ap = new bool[V]; 
	for (int i = 0; i < V; i++) 
	{ 
		parent[i] = NIL; 
		visited[i] = false; 
		ap[i] = false; 
	} 
	for (int i = 0; i < V; i++) 
		if (visited[i] == false) 
			artptUtil(i, visited, disc, low, parent, ap); 
	for (int i = 0; i < V; i++) 
		if (ap[i] == true) 
		{
			cout << i << " "; 
		}
	int i;
	for (i = 0; i < V; i++) 
	{	if (ap[i] == true) 
		{
			cout <<"\nGraph is not biconnected ";
			break; 
		}
	}
	if(i==V)
		cout <<"\nGraph is biconnected ";
} 
int main() 
{ 
	cout << "\nArticulation points in graph \n"; 
	Graph g3(7); 
	g3.addEdge(0, 1); 
	g3.addEdge(1, 2); 
	g3.addEdge(2, 0); 
	g3.addEdge(1, 3); 
	g3.addEdge(1, 4); 
	g3.addEdge(1, 6); 
	g3.addEdge(3, 5); 
	g3.addEdge(4, 5); 
	g3.artpt(); 
	return 0; 
} 
