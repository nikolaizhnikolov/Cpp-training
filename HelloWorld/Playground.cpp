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

#include <vector>
#include <set>
#include "SortLib.h"

int main() {
	std::shared_ptr<Graph> graph = std::make_shared<Graph>();
	std::vector<GEdge> queries;
	std::vector<std::shared_ptr<int>> sortingValues;

	std::ifstream data("sorting_values.txt");
	if (data.is_open()) {
		int values;
		data >> values;
		for (int i = 0; i < values; i++) {
			int x;
			data >> x;
			sortingValues.push_back(std::make_shared<int>(x));
		}
		
		//int pairNumber;
		//data >> pairNumber;
		//for (int i = 0; i < pairNumber; i++) {
		//	int x, y;
		//	data >> x >> y;
		//	graph->addEdge(GEdge(x, y));
		//}

		//int queryNumber;
		//data >> queryNumber;
		//for (int i = 0; i < queryNumber; i++) {
		//	int x, y;
		//	data >> x >> y;
		//	queries.push_back(GEdge(x, y));
		//}
	}
	data.close();

	SortLib<int>::selectionSort(sortingValues);
	for (std::shared_ptr<int> i : sortingValues) 
		std::cout <<* i << " ";

	return 0;
}
