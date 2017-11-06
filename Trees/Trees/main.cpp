#include <iostream>
#include <algorithm>
#include <vector>
//#include "BinarySearchTree.h"
#include "SkipList.h"

int main() {

	SkipList<int> * skiplist = new SkipList<int>;

	int n = 20;
	int A[20] = {10, 8, 2, 20, 52, 3, 19, 14, 7, 9, 31, 40, 81, 24, 1, -1, 63, 25, 90, 99};

	for (int j = 0; j < n; j++) {
		skiplist->insert(A[j]);
		//tree->printLevelOrder();
		//std::cout << "\n\n";
	}
	

	skiplist->print();

	std::cout << skiplist->search(12) << "\n";
	std::cout << skiplist->search(90) << "\n";
	std::cout << skiplist->search(13) << "\n";
	std::cout << skiplist->search(1) << "\n";
	
	skiplist->remove(-1);
	skiplist->remove(99);
	skiplist->remove(40);

	skiplist->print();

	int a;
	std::cin >> a;

	return 0;
}