#include <iostream>
#include "Sort.h"

int main() {
	int A[17] = { 7, 5, 5, 9, 8, 12, 0, -1, 3, 12, 23, 1, 7, 8, 10, 0, 19 };
	Sort<int>::mergeSort(A, A + 17);

	int i;
	for (i = 0; i < 17; i++)
		std::cout << A[i] << " ";
	std::cout << "\n";

	int B[17]  = { 7, 5, 5, 9, 8, 12, 0, -1, 3, 12, 23, 1, 7, 8, 10, 0, 19 };
	Sort<int>::quickSort(B, B + 17);
	for (i = 0; i < 17; i++)
		std::cout << B[i] << " ";

	int a;
	std::cin >> a;

	return 0;
}