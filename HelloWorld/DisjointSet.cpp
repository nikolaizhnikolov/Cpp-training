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
	int v = root.at(n);
	if (v < 0) return -1;

	if (v == n)	return n;
	else return v = find(v);
}

int DisjointSet::findRank(int n)
{
	int v = root.at(n);

	if (v == n) return rank.at(n);
	else return rank.at(n) = findRank(v);
}

void DisjointSet::make(int a, int b)
{
	root.at(a) = a;
	root.at(b) = a;
	rank.at(a) = 2;
	rank.at(b) = 2;
}

void DisjointSet::resizeSet(int a, int b)
{
	const size_t& size = root.size();
	if (a + 1 > size || b + 1 > size)
	{
		size_t newSize = std::max(a, b) + 1;
		root.resize(newSize, -1);
		rank.resize(newSize, -1);
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
	{
		root.at(a) = root.at(b);
		rank.at(b)++;
	}
	else if (findB == -1)
	{
		root.at(b) = root.at(a);
		rank.at(a)++;
	}
	else if (findA != findB)
	{
		if (rank.at(a) >= rank.at(b))
		{
			root.at(find(b)) = root.at(a);
			rank.at(a) += rank.at(b);
		}
		else
		{
			root.at(find(a)) = root.at(b);
			rank.at(b) += rank.at(a);
		}
	}
}
