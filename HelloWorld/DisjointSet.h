#pragma once

#include <vector>
#include "GEdge.h"

class DisjointSet
{
	std::vector<int> disjointSet;

public:
	DisjointSet(std::vector<GEdge> edges);

	int find(int n);

	void make(int a, int b);
	void gunion(int a, int b);
	void resizeSet(int a, int b);

	bool connected(int a, int b);

	std::vector<int> getSet() { return disjointSet; };
};

