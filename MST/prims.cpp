// c++ code for prim's algorithm
#include <bits/stdc++.h>
using namespace std;


#define V 10

int minKey(int key[], bool mstSet[])
{

	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void printMST(int parent[], int graph[V][V])
{
	cout<<"Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}

void primMST(int graph[V][V])
{

	int parent[V];

	int key[V];

	bool mstSet[V];


	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++)
	{

		int u = minKey(key, mstSet);


		mstSet[u] = true;


		for (int v = 0; v < V; v++)


			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}


	printMST(parent, graph);
}


int main()
{

	int graph[V][V] = { { 0, 15, 10, 19, 0 ,0,0,0,0,0},
						{ 15, 0, 0, 7, 17,0,0,0,0,0 },
						{ 10, 0, 0, 16, 0,14,0,0,0,0 },
						{ 19, 7, 16, 0, 12,6,3,0,0,0},
						{ 0, 17, 0, 12, 0,0,20,13,0,0 },
						{ 0, 0, 14, 6, 0,0,9,0,5,0 },
						{ 0, 0, 0, 3, 20,9,0,4,1,11 },
						{ 0, 0, 0, 0,13,0,4,0,0,2 },
						{ 0, 0, 0, 0, 0,5,1,0,0,18 },
						{ 0, 0, 0, 0, 0,0,2,1,18,0 },
						 };


	primMST(graph);

	return 0;
}
