#include "Graph.h"

Graph::Graph(std::vector<GEdge> edges)
{
	for (GEdge e : edges) {
		addEdge(e);
	}
}

Graph::Graph(std::set<int> vertices, std::vector<GEdge> edges)
{
	for (GEdge e : edges) {
		addEdge(e);
	}
	for (int vertex : vertices)
	{
		addVertex(vertex);
	}
}

void Graph::addEdge(GEdge edge)
{
	if(containsEdge(edge)) return;

	edges.push_back(edge);
	addVertex(edge.a);
	addVertex(edge.b);
}

bool Graph::containsEdge(GEdge& edge) const
{
	for (GEdge e : edges) {
		if (e == edge) return true;
	}
	return false;
}
