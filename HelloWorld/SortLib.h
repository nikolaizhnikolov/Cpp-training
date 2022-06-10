#pragma once

#include <vector>
#include <iostream>

class SortLib
{
public:
	static void bubbleSort(std::vector<std::shared_ptr<int>> values);
private:
	static void swap(std::shared_ptr<int> a, std::shared_ptr<int> b);
};

