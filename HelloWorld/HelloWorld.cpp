// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <functional>

#include "Fibonacci.h"


int main() {
	int n = 15;

	auto start = std::chrono::steady_clock::now();
	std::cout << "Fibonacci number of " << n << " is: " << fibonacci(15) << std::endl;
	auto end = std::chrono::steady_clock::now();

	std::chrono::duration<double> duration = end - start;
	std::cout << "Elapsed time: " << duration.count() << std::endl;

	return 0;
}

//#include "SomeFunction.h"
//
//int main()
//{
//    std::cout << "Hello World!\n";
//
//    std::cout << SomeFunction::calculate(10, 15) << std::endl;
//
//    SomeFunction a(10);
//    SomeFunction b(20);
//
//    std::cout << SomeFunction::calculate(a, b);
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
