
#include <bits/stdc++.h>
using namespace std;

class Edge
{
	public:
	int src, dest;
};

class Graph
{
	public:
	int V, E; // no. of vertices and edges
	Edge* edge; // array of edges
};

Graph* createGraph(int V, int E)
{
	Graph* graph = new Graph();
	graph->V = V;
	graph->E = E;
    int sizeOfArray = (graph->E) * sizeof(Edge);
	graph->edge = new Edge[sizeOfArray];
	return graph;
}

int find(int parent[], int i)
{
	if (parent[i] == -1)
		return i;
	return find(parent, parent[i]);
}

void Union(int parent[], int x, int y)
{
	int xset = find(parent, x);
	int yset = find(parent, y);
	if(xset != yset)
	{
		parent[xset] = yset;
	}
}

int isCycle( Graph* graph )
{
	int totalVertexSize = graph->V *sizeof(int);
	int *parent = new int[totalVertexSize];
	memset(parent, -1, totalVertexSize);
    int totalEdges = graph->E;
	for(int i = 0; i < totalEdges ; ++i)
	{
		int x = find(parent, graph->edge[i].src);
		int y = find(parent, graph->edge[i].dest);
        cout<<x<<" "<<y<<endl;
        // if rep of both vertex is same means a cycle is there
		if (x == y)
			return 1;
        // otherwise make union
		Union(parent, x, y);
         for(int i=0;i<graph->V;i++)
    cout<<parent[i]<<" ";
    cout<<endl;
	}
	return 0;
}

int main()
{

	int V = 3, E = 2;
	Graph* graph = createGraph(V, E);

	// add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;

	// add edge 1-2
	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;

	// // add edge 0-2
	// graph->edge[2].src = 0;
	// graph->edge[2].dest = 2;

	if (isCycle(graph))
		cout<<"cycle\n";
	else
		cout<<"No-cycle\n";

	return 0;
}