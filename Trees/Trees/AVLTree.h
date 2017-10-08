#include "BinaryTree.h"
#include <stack>
#include <vector>
#include <cmath>
#include <queue>

#ifndef AVLTREE_H
#define ALVTREE_H

template <class T>
struct Node {
	T data;
	Node * left, *right, *parent;
	int h;

	Node(T data) {
		this->data = data;
		left = right = parent = NULL;
		h = 1;
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
		h = std::max((left != NULL ? left->h : 0), (right != NULL ? right->h: 0)) + 1;
		return h;
	}

};

template <class T>
class AVLTree : public BinaryTree<T> {

public:
	AVLTree();

	bool isEmpty();
	int size();
	bool contains(T data);
	void insert(T data);
	void deleteElement(T data);
	std::vector<std::vector<T>> levelOrder();
	void printLevelOrder();
	std::vector<T> inOrder();

private:
	Node<T> * root;
	int _size;

	void rebalanceToTheRoot(Node<T> * node);
	void balance(Node<T> * node);
	void balanceLeftLeft(Node<T> * node);
	void balanceLeftRight(Node<T> * node);
	void balanceRightRight(Node<T> * node);
	void balanceRightLeft(Node<T> * node);
	void inOrder(Node<T> * node, std::vector<T> & list);

};

template <class T>
AVLTree<T>::AVLTree() {
	root = NULL;
	_size = 0;
}

template <class T>
void AVLTree<T>::balanceLeftLeft(Node<T> * node) {
	Node<T> * a, *b, *A, *B, *C, *p;

	a = node;
	b = node->left;
	A = b->left;
	B = b->right;
	C = a->right;
	p = a->parent;

	if (p != NULL) {
		if (p->left == a) p->left = b;
		else p->right = b;
	}
	b->parent = p;

	b->right = a;
	a->parent = b;
	a->left = B;
	if(B != NULL) B->parent = a;

	a->updateHeight();
	b->updateHeight();

	if (root == a)
		root = b;
}

template<class T>
void AVLTree<T>::balanceRightRight(Node<T> * node) {
	Node<T> * a, *b, *A, *B, *C, *p;

	a = node;
	b = node->right;
	A = a->left;
	B = b->left;
	C = b->right;
	p = a->parent;

	if (p != NULL) {
		if (p->left == a) p->left = b;
		else p->right = b;
	}
	b->parent = p;

	b->left = a;
	a->parent = b;
	a->right = B;
	if (B != NULL) B->parent = a;

	a->updateHeight();
	b->updateHeight();

	if (root == a)
		root = b;
}

template<class T>
void AVLTree<T>::balanceLeftRight(Node<T> * node) {
	Node<T> * a, *b, *c, *B, *C, *p;

	a = node;
	b = a->left;
	c = b->right;

	B = c->left;
	C = c->right;
	p = a->parent;

	if (p != NULL) {
		if (p->left == a) p->left = c;
		else p->right = c;
	}
	c->parent = p;

	c->left = b;
	b->parent = c;
	c->right = a;
	a->parent = c;
	b->right = B;
	if (B != NULL) B->parent = b;
	a->left = C;
	if (C != NULL) C->parent = a;

	a->updateHeight();
	b->updateHeight();
	c->updateHeight();

	if (root == a)
		root = c;
}

template<class T>
void AVLTree<T>::balanceRightLeft(Node<T> * node) {
	Node<T> * a, *b, *c, *B, *C, *p;

	a = node;
	b = a->right;
	c = b->left;

	B = c->left;
	C = c->right;
	p = a->parent;

	if (p != NULL) {
		if (p->left == a) p->left = c;
		else p->right = c;
	}
	c->parent = p;

	c->left = a;
	a->parent = c;
	c->right = b;
	b->parent = c;
	a->right = B;
	if (B != NULL) B->parent = a;
	b->left = C;
	if (C != NULL) C->parent = b;

	a->updateHeight();
	b->updateHeight();
	c->updateHeight();

	if (root == a)
		root = c;
}

template <class T>
void AVLTree<T>::balance(Node<T> * node) {
	if (node->balanceFactor() == -2)
		if (node->left->balanceFactor() <= 0)
			balanceLeftLeft(node);
		else
			balanceLeftRight(node);
	else
		if (node->right->balanceFactor() >= 0)
			balanceRightRight(node);
		else
			balanceRightLeft(node);
}

template <class T>
void AVLTree<T>::rebalanceToTheRoot(Node<T> * node) {
	Node<T> * prev;

	while (node != NULL) {
		node->h = node->updateHeight();
		prev = node->parent;
		if (abs(node->balanceFactor()) >= 2)
			balance(node);

		node = prev;
	}
}

template <class T>
void AVLTree<T>::insert(T data) {
	Node<T> * node = new Node<T>(data);
	_size++;

	if (_size == 1) {
		root = node;
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
		prev->left = node;
	else
		prev->right = node;
	node->parent = prev;

	rebalanceToTheRoot(node);
}

template<class T>
void AVLTree<T>::deleteElement(T data) {
	if (root == NULL)
		return;

	//find node;
	Node<T> * node, *parent, *curr;
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
	if (node == root && (node->left == NULL || node->right == NULL)) {
		if (node->left == NULL) {
			root = node->right;
			node->right->parent = NULL;
		}
		if (node->right == NULL) {
			root = node->left;
			node->right->parent = NULL;
		}

		delete node;
		return;
	}

	//if node has right child swap the values in node and its in-order succesor.
	//rebalance from the in-order sucessor's parent
	if (node->right != NULL) {
		curr = node->right;
		parent = node;
		while (curr->left != NULL) {
			parent = curr;
			curr = curr->left;
		}

		node->data = curr->data;

		if (parent == node) {
			node->right = curr->right;
			if(curr->right != NULL) curr->right->parent = node;
		}
		else {
			parent->left = curr->right;
			if(curr->right != NULL) curr->right->parent = parent;
		}

		rebalanceToTheRoot(parent);
		delete curr;
		return;
	}

	//if node doesn't have right child, make its parent point to its left child.
	if (parent->left == node)
		parent->left = node->left;
	else
		parent->right = node->left;
	if(node->left != NULL)
		node->left->parent = parent;

	rebalanceToTheRoot(parent);

	delete node;
}

template<class T>
bool AVLTree<T>::contains(T data) {
	Node<T> * node = root;
	while (node != NULL && node->data != data) {
		if (data < node->data)
			node = node->left;
		else
			node = node->right;
	}

	return node != NULL;
}

template<class T>
void AVLTree<T>::inOrder(Node<T> * node, std::vector<T> & list) {
	if (node == NULL)
		return;

	inOrder(node->left, list);
	list.push_back(node->data);
	inOrder(node->right, list);
}

template<class T>
std::vector< std::vector<T> > AVLTree<T>::levelOrder(){
	std::vector< std::vector<T> > levelOrder;
	levelOrder.resize(root->updateHeight());

	std::queue< std::pair< Node<T> *, int > > q;
	std::pair<Node<T> *, int> act = std::make_pair(root, 0);
	q.push(act);

	while(!q.empty()){
		act = q.front();
		q.pop();

		levelOrder[act.second].push_back( act.first->data );
		if(act.first->left != NULL)
			q.push( std::make_pair(act.first->left, act.second + 1) );

		if(act.first->right != NULL)
			q.push( std::make_pair(act.first->right, act.second + 1) );
	}

	return levelOrder;
}

template<class T>
std::vector<T> AVLTree<T>::inOrder() {
	std::vector<T> ret;
	inOrder(root, ret);
	return ret;
}

template<class T>
void AVLTree<T>::printLevelOrder(){
	std::vector< std::vector<T> > order = levelOrder();
	for(int i = 0; i < order.size(); i++){
		std::cout << "Level " << i << ": ";
		for(int j = 0; j < order[i].size(); j++)
			std::cout << order[i][j] << " ";
		std::cout << "\n";
	}
}

template <class T>
int AVLTree<T>::size() {
	return _size;
}

template <class T>
bool AVLTree<T>::isEmpty() {
	return _size == 0;
}

#endif // !AVLTREE_H
