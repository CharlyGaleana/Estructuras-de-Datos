#ifndef LISTNODE_H
#define LISTNODE_H

template <class T> 
class ListNode{

public:
	ListNode();
	ListNode(T data);
	~ListNode();

	T getData();
	ListNode<T> * getNext();
	void setData(T data);
	void setNext(ListNode<T> * next);

private:
	T data;
	ListNode<T> * next;

};

template <class T>
ListNode<T>::ListNode(){
	this->data = NULL;
	this->next = NULL;
}

template <class T>
ListNode<T>::ListNode(T data){
	this->data = data;
	this->next = NULL;
}

template <class T>
ListNode<T>::~ListNode(){
	
}

template <class T>
T ListNode<T>::getData(){
	return data;
}

template <class T>
ListNode<T> * ListNode<T>::getNext(){
	return next;
}

template <class T>
void ListNode<T>::setData(T data){
	this->data = data;
}

template <class T>
void ListNode<T>::setNext(ListNode<T> * next){
	this->next = next;
}

#endif