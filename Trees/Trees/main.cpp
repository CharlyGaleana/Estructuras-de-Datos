#include <iostream>
#include <algorithm>
#include <vector>
//#include "BinarySearchTree.h"
#include "AVLTree.h"

int main() {

	AVLTree<int> * tree = new AVLTree<int>;

	int n = 14;
	int A[14] = { 100, 50, 13, 33, 8, -2, 31, 314, 69, 23, 45, 21, 48, 15 };

	for (int j = 0; j < n; j++) {
		tree->insert(A[j]);
		tree->printLevelOrder();
		std::cout << "\n\n";
	}

	tree->printLevelOrder();

	std::cout << tree->contains(13) << "\n";
	std::cout << tree->contains(-1) << "\n";
	std::cout << tree->contains(31) << "\n";
	std::cout << tree->contains(68) << "\n";
	std::cout << tree->contains(314) << "\n";

	tree->deleteElement(45);
	tree->printLevelOrder();
	std::cout << "\n\n";
	
	tree->deleteElement(48);
	tree->printLevelOrder();
	std::cout << "\n\n";

	tree->deleteElement(33);
	tree->printLevelOrder();
	std::cout << "\n\n";

	tree->insert(49);
	tree->printLevelOrder();
	std::cout << "\n\n";

	tree->deleteElement(100);
	tree->printLevelOrder();
	std::cout << "\n\n";

	tree->deleteElement(13);
	tree->printLevelOrder();
	std::cout << "\n\n";

	tree->insert(28);
	tree->printLevelOrder();
	std::cout << "\n\n";

	tree->insert(29);
	tree->printLevelOrder();
	std::cout << "\n\n";
	
	tree->deleteElement(8);
	tree->printLevelOrder();
	std::cout << "\n\n";

	tree->insert(-3);
	tree->printLevelOrder();
	std::cout << "\n\n";
	/*tree->deleteElement(13);
	tree->printLevelOrder();
	std::cout << "\n\n";
	
	tree->deleteElement(45);
	tree->printLevelOrder();
	std::cout << "\n\n";

	tree->deleteElement(48);
	tree->printLevelOrder();
	std::cout << "\n\n";
	*/

	/*
	tree->deleteElement(1);
	tree->deleteElement(1);

	p = tree->inOrder();
	for (int i = 0; i < p.size(); i++)
		std::cout << p[i] << " ";
	std::cout << "\n\n";

	tree->insert(7);
	tree->insert(-4);
	tree->insert(9);
	tree->insert(1);

	p = tree->inOrder();
	for (int i = 0; i < p.size(); i++)
		std::cout << p[i] << " ";
	std::cout << "\n\n";

	tree->deleteElement(1000);

	p = tree->inOrder();
	for (int i = 0; i < p.size(); i++)
		std::cout << p[i] << " ";
	std::cout << "\n\n";

	tree->deleteElement(-1);
	tree->deleteElement(2);

	p = tree->inOrder();
	for (int i = 0; i < p.size(); i++)
		std::cout << p[i] << " ";
	std::cout << "\n\n";

	std::cout << tree->depth();
	*/

	int a;
	std::cin >> a;

	return 0;
}