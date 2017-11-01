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
	SkipList(int max_level);
	~SkipList();
	bool search(T value);
	void insert(T value);
	void remove(T value);
	int size();

private:
	//void increase_size()
	SkipListNode<T> * head, * tail;
	int level = 1;
	int max_level = 20;
	int ramdomLevel();
	SkipListNode<T> * search(T value, vector<SkipListNode<T> *> &update);
	int _size;

};

template<class T>
SkipList<T>::SkipList() {
	head = new SkipListNode(max_level);
	tail = new SkipListNode(max_level);

	for(int i = 0; i < max_level; i++)
		head->next[i] = tail;
	_size = 0;
}

template<class T>
SkipList<T>::SkipList(int max_level) {
	this->max_level = max_level;
	head = new SkipListNode(max_level);
	tail = new SkipListNode(max_level);

	for (int i = 0; i < max_level; i++)
		head->next[i] = tail;
	_size = 0;
}

template<class T>
SkipList<T>::~SkipList() {

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
SkipListNode<T> * SkipList<T>::search(T value, vector<SkipListNode<T> *> &update) {
	SkipListNode<T> * curr = header;
	for (int i = level - 1; i >= 0; i--) {
		while (curr->next[i] != tail && curr->next[i]->data < value)
			curr = curr->next[i];
		update[i] = curr;
	}

	curr = curr->next[0];
	if (curr != tail && curr->data == value)
		return curr;
	return NULL;
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
	vector<SkipListNode<T> *> update(level);
	SkipListNode<T> * curr= search(value, update);

	if (curr == NULL) {
		int lvl = ramdomLevel();
		if (lvl > level) {
			update.resize(lvl, head);
			level = lvl;
		}
		SkipListNode<T> * newNode = new SkipListNode<T>(value, lvl);
		for (int i = 0; i < lvl; i++) {
			newNode->next[i] = update[i]->next[i];
			update[i]->next[i] = newNode;
		}

		_size++;
	}
}

template<class T>
void SkipList<T>::remove(T value) {
	vector<SkipListNode<T> *> update(level);
	SkipListNode<T> * curr = search(value, update);

	if (curr != NULL) {
		for (int i = 0; i < level; i++) {
			if (update[i]->next[i] != curr) break;
			update[i]->next[i] = curr->next[i];
		}

		delete curr;

		while (level > 1){
			if (head->next[level - 1] == tail)
				level--;
			else
				break;
		}

		_size--;
	}
}

template<class T>
int SkipList<T>::size() {
	return _size;
}

#endif // !SKIPLIST_H

