#pragma once
#include <set>
#include <string>
#include <vector>

#include "GEdge.h"


class Graph
{
private:
	std::set<int> vertices;
	std::vector<GEdge> edges;
public:
	Graph() {};
	Graph(std::vector<GEdge> GEdges);
	Graph(std::set<int> vertices, std::vector<GEdge> GEdges);
	
	void addEdge(GEdge GEdge);
	void addVertex(int vertex) { vertices.insert(vertex); };

	bool containsEdge(GEdge& GEdge) const;

	std::vector<GEdge> getEdges() const { return edges; };
	std::set<int> getVertices() const { return vertices; };

	int getVerticesSize() const { return int(getVertices().size()); };

};

