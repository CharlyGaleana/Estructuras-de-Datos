#include "BinaryTree.h"
#include <stack>
#include <vector>

#ifndef LINKEDBINARYTREE_H
#define LINKEDBINARYTREE_H

template <class T>
struct Node {
	T data;
	Node * left, * right;

	Node(T data) {
		this->data = data;
		this->left = this->right = NULL;
	}

	Node(T data, Node<T> * left, Node<T> * right) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

template <class T>
class LinkedBinaryTree : public BinaryTree<T> {

public:
	LinkedBinaryTree();
	LinkedBinaryTree(T root);
	bool isEmpty();
	int size();
	bool contains(T data);
	int depth();
	void insert(T data);
	std::vector<T> preOrder();
	std::vector<T> inOrder();

private:
	Node<T> * root;
	int _size;
	bool contains(Node<T> * node, T data);
	int depth(Node<T> * root);
	void inOrder(Node<T> * node, std::vector<T> & list);

};

template <class T>
LinkedBinaryTree<T>::LinkedBinaryTree() {
	root = NULL;
}

template <class T>
LinkedBinaryTree<T>::LinkedBinaryTree(T root) {
	Node<T> * r = new Node<T>(root);
	this->root = r;
}

template <class T>
bool LinkedBinaryTree<T>::contains(Node<T> * node, T data) {
	if (node == NULL)
		return false;

	if (node->data == data)
		return true;

	return contains(node->left, data) | contains(node->right, data);
}

template <class T>
bool LinkedBinaryTree<T>::contains(T data) {
	return this->contains(this->root, data);
}

template <class T>
int LinkedBinaryTree<T>::size() {
	return _size;
}

template <class T>
std::vector<T> LinkedBinaryTree<T>::preOrder() {
	std::stack< Node<T> * > s;
	std::vector<T> list;

	Node<T> * curr;
	s.push(root);
	while (!s.empty()) {
		curr = s.top();
		s.pop();

		list.push_back( curr->data );
		if (curr->left != NULL)
			s.push(curr->left);
		if (curr->right != NULL)
			s.push(curr->right);
	}

	return list;
}

template<class T>
void LinkedBinaryTree<T>::inOrder(Node<T> * node, std::vector<T> & list) {
	if (node == NULL)
		return;

	inOrder(node->left, list);
	list.push_back(node->data);
	inOrder(node->right, list);
}

template<class T>
std::vector<T> LinkedBinaryTree<T>::inOrder() {
	std::vector<T> list;
	inOrder(root, list);
	return list;
}

template<class T>
int LinkedBinaryTree<T>::depth(Node<T> * node) {
	if (node == NULL)
		return 0;

	return std::max(depth(node->left), depth(node->right)) + 1;
}

template<class T>
int LinkedBinaryTree<T>::depth() {
	return depth(root);
}

template<class T>
void LinkedBinaryTree<T>::insert(T data) { 
	Node<T> * newNode = new Node<T>(data);
	_size++;

	if (_size == 1) {
		root = newNode;
		return;
	}

	Node<T> * curr = root, * prev = NULL;

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
bool LinkedBinaryTree<T>::isEmpty() {
	return _size > 0;
}

#endif // !LINKEDBINARYTREE_H