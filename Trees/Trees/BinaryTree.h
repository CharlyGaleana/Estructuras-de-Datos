#ifndef BINARYTREE_H
#define BINARYTREE_H

template <class T>
class BinaryTree {
public:
	virtual bool isEmpty();
	virtual int size();
	virtual bool contains(T data);
	virtual void insert();
	virtual BinaryTree<T>::iterator inOrder();
};

#endif