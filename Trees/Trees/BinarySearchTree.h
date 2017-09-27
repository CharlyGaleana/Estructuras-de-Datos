#include "BinaryTree.h"
#include <stack>
#include <vector>

#ifndef BinarySearchTree_H
#define BinarySearchTree_H

template <class T>
struct Node {
	T data;
	Node * left, * right;

	Node(T data) {
		this->data = data;
		this->left = this->right = NULL;
	}

	~Node() {
		
	}

	Node(T data, Node<T> * left, Node<T> * right) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

template <class T>
class BinarySearchTree : public BinaryTree<T> {

public:
	BinarySearchTree();
	BinarySearchTree(T root);
	bool isEmpty();
	int size();
	bool contains(T data);
	int depth();
	void insert(T data);
	Node<T> * find(T data);
	std::vector<T> preOrder();
	std::vector<T> inOrder();
	T minValue();
	void deleteElement(T data);

private:
	Node<T> * root;
	int _size;
	bool contains(Node<T> * node, T data);
	int depth(Node<T> * root);
	void inOrder(Node<T> * node, std::vector<T> & list);
	Node<T> * find(Node<T> * node, T data);
	Node<T> * minNode(Node<T> * node);
	bool isLeaf(Node<T> * node);

};

template <class T>
BinarySearchTree<T>::BinarySearchTree() {
	root = NULL;
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(T root) {
	Node<T> * r = new Node<T>(root);
	this->root = r;
}

template <class T>
bool BinarySearchTree<T>::contains(Node<T> * node, T data) {
	while (node != NULL && node->data != data) {
		if (data < node->data)
			node = node->left;
		else
			node = node->right;
	}

	return node != NULL;

}

template <class T>
bool BinarySearchTree<T>::contains(T data) {
	return this->contains(this->root, data);
}

template <class T>
Node<T> * BinarySearchTree<T>::find(Node<T> * node, T data) {
	while (node != NULL && node->data != data) {
		if (data < node->data)
			node = node->left;
		else
			node = node->right;
	}

	return node;
}

template <class T>
Node<T> * BinarySearchTree<T>::find(T data) {
	return find(root, data);
}

template <class T>
int BinarySearchTree<T>::size() {
	return _size;
}

template <class T>
std::vector<T> BinarySearchTree<T>::preOrder() {
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
void BinarySearchTree<T>::inOrder(Node<T> * node, std::vector<T> & list) {
	if (node == NULL)
		return;

	inOrder(node->left, list);
	list.push_back(node->data);
	inOrder(node->right, list);
}

template<class T>
std::vector<T> BinarySearchTree<T>::inOrder() {
	std::vector<T> list;
	inOrder(root, list);
	return list;
}

template<class T>
int BinarySearchTree<T>::depth(Node<T> * node) {
	if (node == NULL)
		return 0;

	return std::max(depth(node->left), depth(node->right)) + 1;
}

template<class T>
int BinarySearchTree<T>::depth() {
	return depth(root);
}

template<class T>
void BinarySearchTree<T>::insert(T data) { 
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

template <class T>
Node<T> * BinarySearchTree<T>::minNode(Node<T> * node) {
	while (node->left != NULL)
		node = node->left;
	return node;
}

template <class T>
void BinarySearchTree<T>::deleteElement(T data) {
	
	if (root == NULL)
		return;

	//find node;
	Node<T> * node, * parent, * prev;
	node = root; parent = NULL;

	while (node != NULL && node->data != data) {
		parent = node;
		if (data < node->data)
			node = node->left;
		else
			node = node->right;
	}

	if (node == NULL)
		return;

	_size--;

	//if node is the root and it doesn't have right or left child.
	if (node == root && (node->left == NULL || node->right == NULL) ) {
		if (node->left == NULL)
			root = node->right;
		if (node->right == NULL)
			root = node->left;
		delete node;
		return;
	}

	//if node has right child swap the values in node and its in-order succesor.
	if (node->right != NULL) {
		prev = node->right;
		parent = node;
		while (prev->left != NULL) {
			parent = prev;
			prev = prev->left;
		}

		node->data = prev->data;

		if (parent == node)
			node->right = prev->right;
		else
			parent->left = prev->right;

		delete prev;
		return;
	}

	//if node doesn't have right child, make its parent point to its left child.
	if (parent->left == node)
		parent->left = node->left;
	else
		parent->right = node->left;
		
	delete node;

}

template <class T>
bool BinarySearchTree<T>::isLeaf(Node<T> * node) {
	return node->left = NULL && node->right = NULL;
}

template <class T>
T BinarySearchTree<T>::minValue() {
	return minNode(root)->data;
}

template<class T>
bool BinarySearchTree<T>::isEmpty() {
	return _size > 0;
}

#endif // !BinarySearchTree_H