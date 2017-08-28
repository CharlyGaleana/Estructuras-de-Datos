#include <iostream>
#include "Sort.h"

int main() {
	int A[10] = { 5, 5, 9, 8, 0, 3, 12, 1, 7, 10 };
	Sort<int>::bubbleSort(A, A + 10);

	int i;
	for (i = 0; i < 10; i++)
		std::cout << A[i] << " ";
	std::cout << "\n";

	int a;
	std::cin >> a;

	return 0;
}