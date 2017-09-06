#include "BinaryTree.h"

#ifndef LINKEDBINARYTREE_H
#define LINKEDBINARYTREE_H

template <class T>
struct Node {
	T data;
	Node * left, * right;

	Node(T data) {
		this->data = data;
		this->left = this->right = null;
	}

	Node(T data, Node<T> * left, Node<T> * right) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

template <class T>
class LinkedBinaryTree : public BinaryTree {

public:
	LinkedBinaryTree();
	LinkedBinaryTree(T root);
	bool isEmpty();
	int size();
	bool contains(T data);

private:
	Node<T> * root;
	int _size;

	bool contains(Node<T> * node, T data);

};

template <class T>
LinkedBinaryTree<T>::LinkedBinaryTree() {
	root = null;
}

template <class T>
LinkedBinaryTree<T>::LinkedBinaryTree(T root) {
	Node<T> * r = new Node<T>(root);
	this->root = r;
}

template <class T>
bool LinkedBinaryTree<T>::contains(Node<T> * node, T * data) {
	
}

#endif // !LINKEDBINARYTREE_H