#include <vector>

#ifndef HEAP_H
#define HEAP_H

template <class T>
class Heap {

public:
	Heap();
	~Heap();
	push(T);
	T pop();
	T top();
	bool isEmpty();

private:
	std::vector<T> heap;
	int n;

};

template<class T>
Heap<T>::Heap() {
	
};

template<class T>
Heap<T>::~Heap() {
	heap.clear();
}



template <class T>
bool Heap<T>::isEmpty() {
	return heap.size == 0;
}

#endif // !HEAP_H

