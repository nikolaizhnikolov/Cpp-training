#include <vector>
#include <iostream>
#include <exception>
#include "Fibonacci.h"

/**
* Fibonnaci generating code under different formats for practice.
*
* fibonacci_int_print():
*	- limited to int size
*	- prints values during function call
*
*/

const short MAX_INT_NUMBER = 47;
const short MAX_UINT_NUMBER = 47;

int64_t x1 = 1;
int64_t x2 = 1;
int64_t temp = 1;

void reset() {
	x1 = 1;
	x2 = 1;
	temp = 1;
}

void fibonacci_int_print(int f) {
	reset();

	std::cout << "Printing fibonnaci sequence up to: " << f << std::endl;

	int result = 0;
	if (f == 0) result = 0;
	//else if (f == 1) result = 1;
	else {
		for (int i = 1; i <= f; i++) {
			x2 += x1;
			x1 = temp;
			temp = x2;
			std::cout << x2 << " ";
		}
	}

	return;
}

void fibonacci_int_print_max() {
	reset();
	for (int i = 2; x2 >= 0; i++) {
		x2 += x1;
		x1 = temp;
		temp = x2;

		//printf("Number at %d: %d\n", i, x2);
	}
}

long fibonacci(int n) {
	if (n < 2) return n;
	else return fibonacci(n - 1) + fibonacci(n - 2);
}
