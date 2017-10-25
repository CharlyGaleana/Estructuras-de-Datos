#include <vector>
#include <cstdlib>

using namespace std;

#ifndef SKIPLIST_H
#define SKIPLIST_H

template <class T>
struct SkipListNode {
	
	SkipListNode(int level){
		next.resize(level);
	}

	SkipListNode(T data, int level) {
		this->data = data;
		next.resize(level);
	}

	~SkipListNode() {
		next.swap( vector<SkipListNode *> () )
	}

	T data;
	vector<SkipListNode *> next;
};

template <class T>
class SkipList {
public:
	SkipList();
	~SkipList();
	bool search(T value);
	void insert(T value);
	void remove(T value);

private:
	//void increase_size()
	SkipListNode<T> * head, * tail;
	int level = 1;
	int max_level = 20;
	int ramdomLevel();
	SkipListNode<T> * search(T value, vector<SkipListNode<T> *> update);

};

template<class T>
SkipList<T>::SkipList() {
	head = new SkipListNode(1);
	tail = new SkipListNode(1);
	head->next[0] = tail;
}

template<class T>
int SkipList<T>::ramdomLevel() {
	int res = 1;
	int r = rand();
	while (res < max_level && r&1) {
		res++;
		r >>= 1;
	}
	return res;
}

template<class T>
SkipListNode<T> * SkipList<T>::search(T value, vector<SkipListNode<T> *> update) {
	SkipListNode<T> * curr = header;
	for (int i = level - 1; i >= 0; i--) {
		while (curr->next[i] != tail && curr->next[i]->data < value)
			curr = curr->next[i];
		update[i] = curr;
	}

	curr = curr->next[0];
	return curr;
}

template<class T>
bool SkipList<T>::search(T value) {
	SkipListNode<T> * curr = header;
	for (int i = level - 1; i >= 0; i--) 
		while (curr->next[i] != tail && curr->next[i]->data < value)
			curr = curr->next[i];

	curr = curr->next[0];
	if (curr != tail && curr->data == value)
		return true;
	return false;
}

template<class T>
void SkipList<T>::insert(T value) {
	vector<SkipListNode<T> *> update(max_level);
	SkipListNode<T> * = search(value, update);

	if (curr != tail) {
	
	}

}

#endif // !SKIPLIST_H

