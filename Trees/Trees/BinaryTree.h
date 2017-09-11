#include <vector>

#ifndef BINARYTREE_H
#define BINARYTREE_H

template <class T>
class BinaryTree {
public:
	virtual bool isEmpty() = 0;
	virtual int size() = 0;
	virtual bool contains(T data) = 0;
	virtual void insert(T data) = 0;
	virtual std::vector<T> preOrder() = 0;
	virtual std::vector<T> inOrder() = 0;
};
 
//template <class T>
//bool BinaryTree<T>::isEmpty() {
//
//}
//
//template <class T>
//int BinaryTree<T>::size() {
//	return 0;
//}
//
//template <class T>
//bool BinaryTree<T>::contains(T data) {
//	return true;
//}
//
//template <class T>
//void BinaryTree<T>::insert(T data) {
//
//}
//
//template <class T>
//std::vector<T> BinaryTree<T>::preOrder() {
//	
//}


#endif