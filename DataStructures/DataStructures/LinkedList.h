#include "ListNode.h"
#include <iostream>
#include <stack>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<class T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();
	/**
	*Inserts an element at the end of the list.
	*/
	void insertAtTheEnd(T value);
	/**
	*Inserts an element at the specified index.
	*Retruns true if the element was inserted, false otherwise.
	*/
	bool insertAt(int index, T value);
	/**
	*Removes the first element of the list.
	*/
	bool removeFirst();
	/**
	*Removes the element at specified index.
	*If an element exists at specified index, it is removed and the function returns true,
	*otherwise it returns false.
	*/
	bool removeAt(int index);
	/**
	*Returns the element at the specified index.
	*/
	T getElementAt(int index);
	/**
	*Prints the elements in the linked list in order.
	*/
	void printElements();
	/**
	*Prints the elements inthe linked list in inversed order.
	*/
	void printElementsInInverseOrder();
	/**
	*Returns the size of the list.
	*/
	
	int size();

private:
	/**
	*Returns the node at the specified index, if no such node exist, it returns NULL.
	*/
	ListNode<T> * getNodeAt(int index);

	int _size;
	ListNode<T> * root;
	ListNode<T> * last;

};

template<class T>
LinkedList<T>::LinkedList(){
	root = new ListNode<T>;
	last = root;
	_size = 0;
}

template<class T>
LinkedList<T>::~LinkedList(){
	//to do
}

template<class T>
void LinkedList<T>::insertAtTheEnd(T value){
	ListNode<T> * node = new ListNode<T>();
	node->setData(value);
	last->setNext(node);
	last = node;
	_size++;
}

template<class T>
bool LinkedList<T>::insertAt(int index, T value){
	if(index > _size || index < 0)
		return false;

	
	if(index < _size){
		ListNode<T> * newNode = new ListNode<T>(), * aux = getNodeAt(index - 1);
		newNode->setData(value);
		newNode->setNext(aux->getNext());
		aux->setNext(newNode);
	} else {
		insertAtTheEnd(value);	
	}

	_size++;
	return true;
}

template<class T>
bool LinkedList<T>::removeFirst(){
	if(_size < 1)
		return false;

	ListNode<T> * firstNode = root->getNext();
	root->setNext( firstNode->getNext() );
	_size--;
	if(_size == 0)
		last = root;
	
	delete(firstNode);
	return true;
}

template<class T>
bool LinkedList<T>::removeAt(int index){
	if(index >= _size || index < 0)
		return false;

	if(index == 0)
		return removeFirst();

	ListNode<T> * prev = getNodeAt(index - 1);
	ListNode<T> * toRemove = prev->getNext();
	prev->setNext( toRemove->getNext() );
	if(toRemove == last)
		last = prev;

	delete(toRemove);
	_size--;
	return true;

}

template<class T>
T LinkedList<T>::getElementAt(int index){
	if(index >= size)
		return NULL;

	ListNode<T> * node = getNodeAt(index);
	return node->getData();
}

template<class T>
ListNode<T> * LinkedList<T>::getNodeAt(int index){
	if(index >= _size || index < 0)
		return NULL;

	ListNode<T> * node = root;
	int i = 0;
	for(; i <= index; i++)
		node = node->getNext();

	return node;
}

template<class T>
void LinkedList<T>::printElements(){
	ListNode<T> * curr = root;
	while(curr != last){
		curr = curr->getNext();
		std::cout << curr->getData() << "\n";
	}
}

template<class T>
void LinkedList<T>::printElementsInInverseOrder(){
	ListNode<T> * curr = root;
	std::stack<T> stack;
	while(curr != last){
		curr = curr->getNext();
		stack.push(curr->getData());
	}

	while(!stack.empty()){
		std::cout << stack.top() << "\n";
		stack.pop();
	}
}

template<class T>
int size(){
	return _size();
}

#endif