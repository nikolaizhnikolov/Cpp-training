// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <functional>
#include <fstream>

#include "Fibonacci.h"
#include "Graph.h"
#include "GraphLib.h"
#include "DisjointSet.h"


int main() {
	std::shared_ptr<Graph> graph = std::make_shared<Graph>();
	std::vector<GEdge> queries;


	std::ifstream data("graph_pairs.txt");
	if (data.is_open()) {
		int pairNumber;
		data >> pairNumber;
		for (int i = 0; i < pairNumber; i++) {
			int x, y;
			data >> x >> y;
			graph->addEdge(GEdge(x, y));
		}

		int queryNumber;
		data >> queryNumber;
		for (int i = 0; i < queryNumber; i++) {
			int x, y;
			data >> x >> y;
			queries.push_back(GEdge(x, y));
		}
	}
	data.close();


	DisjointSet ds = DisjointSet(graph->getEdges());

	std::vector<int> set = ds.getSet();
	for (int i : set) 
	{

		std::cout << i << " ";
	}
	std::cout << std::endl;
	for ( int i = 0; i < set.size(); i++)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (GEdge e : queries)
	{
		std::cout << e.a << " and " << e.b << " are connected: " << ds.connected(e.a, e.b) << std::endl;
	}


	return 0;
}
