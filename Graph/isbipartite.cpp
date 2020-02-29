#include <iostream> 
#include <queue> 
#define V 4 
using namespace std; 
bool isBipartite(int graph[][V], int src) 
{ 
	int col[V]; 
	for (int i=0;i<V;++i) 
		col[i]=-1; 
	col[src]=1;  
	queue<int> q; 
	q.push(src); 
	while(!q.empty()) 
	{ 
		int u=q.front(); 
		q.pop(); 
		if (graph[u][u]==1) 
		return false;  
		for (int v=0;v<V;++v) 
		{  
			if(graph[u][v]&&col[v]==-1) 
			{ 
				col[v]=1-col[u]; 
				q.push(v); 
			} 
			else if(graph[u][v]&&col[v]==col[u]) 
				return false; 
		} 
	} 
	return true; 
} 
int main() 
{ 
	int graph[][V]={{0, 1, 0, 1}, 
		{1, 0, 1, 0}, 
		{0, 1, 0, 1}, 
		{1, 0, 1, 0} 
	}; 
	isBipartite(graph,0)?cout<<"Yes":cout<<"No"; 
	return 0; 
} 
