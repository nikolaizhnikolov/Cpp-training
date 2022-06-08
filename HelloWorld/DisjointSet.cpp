#include "DisjointSet.h"

DisjointSet::DisjointSet(std::vector<GEdge> edges)
{
	for (GEdge e : edges)
	{
		gunion(e.a, e.b);
	}
}

int DisjointSet::find(int n)
{
	// Handle infinite loops when new elements are not set yet.
	int v = disjointSet.at(n);
	if (v < 0) return -1;

	if (v == n)	return n;
	else return v = find(v);
}

void DisjointSet::make(int a, int b)
{
	disjointSet.at(a) = a;
	disjointSet.at(b) = a;
}

void DisjointSet::resizeSet(int a, int b)
{
	const size_t& size = disjointSet.size();
	if (a + 1 > size || b + 1 > size)
	{
		size_t newSize = std::max(a, b) + 1;
		disjointSet.resize(newSize, -1);
	}
}

bool DisjointSet::connected(int a, int b)
{
	resizeSet(a, b);
	return find(a) == find(b);
}

void DisjointSet::gunion(int a, int b)
{
	resizeSet(a, b);
	int findA = find(a);
	int findB = find(b);
	if (findA == -1 && findB == -1)
		make(a, b);
	else if (findA == -1)
		disjointSet.at(a) = disjointSet.at(b);
	else if (findB == -1)
		disjointSet.at(b) = disjointSet.at(a);
	else if (findA != findB)
		disjointSet.at(a) = disjointSet.at(b);
}
