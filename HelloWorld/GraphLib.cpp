#include "GraphLib.h"


//GraphLib& GraphLib::instance()
//{
//	static GraphLib    instance; // Guaranteed to be destroyed
//	return instance;			 // Instantiated on first use.
//}

std::unique_ptr<std::vector<int>> rootVector = std::make_unique<std::vector<int>>(10, -1);

bool contains(int n)
{
	for (int i = 0; i < rootVector->size(); i++)
	{
		if (n == rootVector->at(i)) return true;
	}
	return false;
}

void checkRoots(int a, int b)
{
	for (int i = 0; i < rootVector->size(); i++)
	{
		if (rootVector->at(i) == b) 
			rootVector->at(i) = a;
	}
}

void GraphLib::printDisjointSet(std::vector<GEdge> queries, Graph& graph)
{
	rootVector->clear();
	rootVector->resize(graph.getVerticesSize(), -1);

	for (GEdge e : graph.getEdges())
	{
		int a = e.a;
		int b = e.b;
		if (rootVector->at(a) == -1 && rootVector->at(b) == -1)
		{
			rootVector->at(a) = e.a;
			rootVector->at(b) = e.a;
		} 
		else if (rootVector->at(a) != 0)
		{
			rootVector->at(b) = rootVector->at(a);
			checkRoots(a, b);
		}
		else if (rootVector->at(b) != 0) {
			rootVector->at(a) = rootVector->at(b);
			checkRoots(b, a);
		}
	}

	std::cout << "Root values:" << std::endl;
	for (int i = 0; i < rootVector->size(); i++) {
		std::cout << rootVector->at(i) << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < rootVector->size(); i++) {
		std::cout << i + 1 << " ";
	}
	std::cout << std::endl;

	for (GEdge query : queries) 
	{
		int a = query.a;
		int b = query.b;

		if (rootVector->at(a) == rootVector->at(b))
			printf("The (%d, %d) pair is connected\n", a, b);
		else
			printf("The (%d, %d) pair is not connected\n", a, b);
	}
}

