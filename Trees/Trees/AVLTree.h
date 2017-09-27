#include "BinaryTree.h"
#include <stack>
#include <vector>

#ifndef AVLTREE_H
#define ALVTREE_H

template <class T>
struct Node {
	T data;
	Node * left, *right, *parent;
	int h;

	Node(T data) {
		data = data;
		left = right = parent = NULL;
	}

	/*-----Pending
	Node(T data, Node<T> * left, Node<T> * right) {
		this->data = data;
		this->left = left;
		this->right = right;
	}

	Node(T data, Node<T> * left, Node<T> * right, Node<T> * parent) {
		this->data = data;
		this->left = left;
		this->right = right;
	}*/

	~Node() {}
	
	//balanceFactor(node) = heightRightSubtree(node) - heightLeftSubtree(node)
	int balanceFactor() {
		int lf = left != NULL ? left->h : 0;
		int rf = right != NULL ? right->h : 0;

		return rf - lf;
	}

	int updateHeight() {
		h = max((left != NULL ? left->h, 0), (right != NULL ? right->h, 0)) + 1;
		return h;
	}

};

template <class T>
class AVLTree : public BinaryTree {

public:
	AVLTree();

	bool isEmpty();
	int size();
	bool contains(T data);
	void insert(T data);
	void deleteValue(T data);
	std::vector<T> inOrder();

private:
	Node<T> * root;
	int _size;
	void 

	void balance(T node);
	void balanceLeftLeft(T node);
	void balanceLeftRight(T node);
	void balanceRightRight(T node);
	void balanceRightLeft(T node);

};

template <class T>
AVLTree<T>::AVLTree() {

}

template <class T>
void AVLTree<T>::insert(T data) {
	Node<T> * newNode = new Node<T>(data);
	_size++;

	if (_size == 1) {
		root = newNode;
		return;
	}

	Node<T> * node = root, * prev = NULL;

	while (curr != NULL) {
		prev = curr;
		if (data < curr->data)
			curr = curr->left;
		else
			curr = curr->right;
	}

	if (data < prev->data)
		prev->left = newNode;
	else
		prev->right = newNode;
}

template<class T>
void AVLTree<T>::inOrder(Node<T> * node, std::vector<T> & list) {
	if (node == NULL)
		return;

	inOrder(node->left, list);
	list.push_back(node->data);
	inOrder(node->right, list);
}

template <class T>
int AVLTree<T>::size() {
	return _size;
}

#endif // !AVLTREE_H
