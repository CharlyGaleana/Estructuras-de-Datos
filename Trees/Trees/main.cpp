#include <iostream>
#include <algorithm>
#include <vector>
#include "LinkedBinaryTree.h"

int main() {

	LinkedBinaryTree<int> * tree = new LinkedBinaryTree<int>;
	tree->insert(1);
	tree->insert(2);
	tree->insert(4);
	tree->insert(3);
	tree->insert(8);
	tree->insert(9);
	tree->insert(1);
	tree->insert(0);
	tree->insert(-1);

	std::vector<int> p = tree->inOrder();
	for (int i = 0; i < p.size(); i++)
		std::cout << p[i] << " ";
	std::cout << "\n";

	std::cout << tree->depth();

	int a;
	std::cin >> a;

	return 0;
}