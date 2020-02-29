// C++ program for Kruskal's algorithm to find Minimum Spanning Tree using kruskal's algorithm

#include <bits/stdc++.h>
using namespace std;


class Edge
{
	public:
	int src, dest, weight;
};


class Graph
{
	public:
	int V, E;
	Edge* edge;
};

Graph* createGraph(int V, int E)
{
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
   return graph;
}


class subset
{
	public:
	int parent;
	int rank;
};

int find(subset subsets[], int i)
{

	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);

	return subsets[i].parent;
}


void Union(subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}


int myComp(const void* a, const void* b)
{
	Edge* a1 = (Edge*)a;
	Edge* b1 = (Edge*)b;
	return a1->weight > b1->weight;
}

void KruskalMST(Graph* graph)
{
	int V = graph->V;
	Edge result[V];
	int e = 0;
	int i = 0;

	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);


	subset *subsets = new subset[( V * sizeof(subset) )];


	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	while (e < V - 1 && i < graph->E)
	{

		Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);
		if (x != y)
		{
			result[e++] = next_edge;
			Union(subsets, x, y);
		}

	}


	cout<<"Following are the edges in the constructed MST\n";
	for (i = 0; i < e; ++i)
		cout<<result[i].src<<" -- "<<result[i].dest<<" == "<<result[i].weight<<endl;
	return;
}


int main()
{

	int V = 10;
	int E = 19;
	Graph* graph = createGraph(V, E);



	// add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 15;

	// add edge 0-2
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 10;

	// add edge 0-3
	graph->edge[2].src = 0;
	graph->edge[2].dest = 3;
	graph->edge[2].weight = 19;

	// add edge 1-4
	graph->edge[3].src = 1;
	graph->edge[3].dest = 4;
	graph->edge[3].weight = 17;

	// add edge 1-3
	graph->edge[5].src = 1;
	graph->edge[5].dest = 3;
	graph->edge[5].weight = 7;
	// add edge 2-0
	graph->edge[6].src = 2;
	graph->edge[6].dest = 0;
	graph->edge[6].weight = 10;
	// add edge 2-3
	graph->edge[7].src = 2;
	graph->edge[7].dest = 3;
	graph->edge[7].weight = 16;
	// add edge 2-5
	graph->edge[8].src = 2;
	graph->edge[8].dest = 5;
	graph->edge[8].weight = 14;
	// add edge 3-1
	graph->edge[9].src = 3;
	graph->edge[9].dest = 1;
	graph->edge[9].weight = 7;
	// add edge 3-2
	graph->edge[10].src = 3;
	graph->edge[10].dest = 2;
	graph->edge[10].weight = 16;
	// add edge 3-4
	graph->edge[11].src = 3;
	graph->edge[11].dest = 4;
	graph->edge[11].weight = 12;
	// add edge 3-5
	graph->edge[12].src = 3;
	graph->edge[12].dest = 5;
	graph->edge[12].weight = 6;
	// add edge 4-6
	graph->edge[13].src = 4;
	graph->edge[13].dest = 6;
	graph->edge[13].weight = 20;
	// add edge 4-7
	graph->edge[14].src = 4;
	graph->edge[14].dest = 7;
	graph->edge[14].weight = 13;
	// add edge 6-7
	graph->edge[15].src = 6;
	graph->edge[15].dest = 7;
	graph->edge[15].weight = 4;
	// add edge 6-8
	graph->edge[16].src = 6;
	graph->edge[16].dest = 8;
	graph->edge[16].weight = 1;
	// add edge 6-9
	graph->edge[17].src = 6;
	graph->edge[17].dest = 9;
	graph->edge[17].weight = 11;
	// add edge 9-7
	graph->edge[18].src = 9;
	graph->edge[18].dest = 7;
	graph->edge[18].weight = 2;
	// add edge 9-8
	graph->edge[19].src = 6;
	graph->edge[19].dest = 9;
	graph->edge[19].weight = 18;






	KruskalMST(graph);

	return 0;
}


