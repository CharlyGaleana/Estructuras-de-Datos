#include <stack>

#ifndef SORT_H
#define SORT_H

template <class T>
class Sort {

public:
	Sort();
	void static insertionSort(T * begin, T * end);
	void static selectionSort(T * begin, T * end);
	void static bubbleSort(T * begin, T * end);
	void static mergeSort(T * begin, T * end);
	void static quickSort(T * begin, T * end);

	int static insertionSortCount(T * begin, T * end);
	int static selectionSortCount(T * begin, T * end);
	int static bubbleSortCount(T * begin, T * end);
	int static mergeSortCount(T * begin, T * end);
	int static quickSortCount(T * begin, T * end);

private:
	int static partition(T * begin, T * end);

};

template <class T>
Sort<T>::Sort() {

}

template <class T>
void Sort<T>::insertionSort(T * begin, T * end) {
	T * A = begin;
	int n = end - begin;
	int i, j;
	T aux;

	for (i = 1; i < n; i++) {
		j = i - 1;
		aux = A[i];

		while (j >= 0 && aux < A[j]) {
			A[j + 1] = A[j];
			j--;
		}

		A[j + 1] = aux;
	}
}

template <class T>
int Sort<T>::insertionSortCount(T * begin, T * end) {
	T * A = begin;
	int n = end - begin;
	int i, j;
	T aux;
	int ret = 0;

	for (i = 1; i < n; i++) {
		j = i - 1;
		aux = A[i];

		while (j >= 0 && aux < A[j]) {
			A[j + 1] = A[j];
			j--;
			ret++;
		}
		if(j >= 0)
			ret++;

		A[j + 1] = aux;
	}

	return ret;
}

template <class T>
void Sort<T>::selectionSort(T * begin, T * end) {
	T * A = begin;
	int n = end - begin;
	int i, j, minIdx;

	for (i = 0; i < n; i++) {
		minIdx = i;

		for (j = minIdx + 1; j < n; j++)
			if (A[j] < A[minIdx])
				minIdx = j;

		std::swap(A[i], A[minIdx]);
	}

}

template <class T>
int Sort<T>::selectionSortCount(T * begin, T * end) {
	T * A = begin;
	int n = end - begin;
	int i, j, minIdx;
	int ret = 0;

	for (i = 0; i < n; i++) {
		minIdx = i;

		for (j = minIdx + 1; j < n; j++){
			if (A[j] < A[minIdx])
				minIdx = j;
			ret++;
		}

		std::swap(A[i], A[minIdx]);
	}

	return ret;

}

template <class T>
void Sort<T>::bubbleSort(T * begin, T * end) {
	T * A = begin;
	int n = end - begin;
	int i, j;

	for (j = n; j; j--)
		for (i = 0; i < j - 1; i++)
			if (A[i] > A[i + 1])
				std::swap(A[i], A[i + 1]);

}

template <class T>
int Sort<T>::bubbleSortCount(T * begin, T * end) {
	T * A = begin;
	int n = end - begin;
	int i, j;
	int ret = 0;

	for (j = n; j; j--)
		for (i = 0; i < j - 1; i++){
			if (A[i + 1] < A[i])
				std::swap(A[i], A[i + 1]);
			ret++;
		}

	return ret;

}

template <class T>
void Sort<T>::mergeSort(T * begin, T * end) {

	if (begin + 1 >= end)
		return;

	T * A = begin;
	int n = end - begin;
	T * mid = begin + (n / 2);

	mergeSort(begin, mid);
	mergeSort(mid, end);

	//merge
	T * aux = new int[n];
	T * leftIdx = begin, * rightIdx = mid;
	int i = 0;
	while (leftIdx != mid || rightIdx != end) {
		if (leftIdx == mid)
			aux[i++] = *(rightIdx++);
		else if (rightIdx == end)
			aux[i++] = *(leftIdx++);
		else if (*leftIdx < *rightIdx)
			aux[i++] = *(leftIdx++);
		else
			aux[i++] = *(rightIdx++);
	}

	for (i = 0; i < n; i++) {
		(*begin) = aux[i];
		begin++;
	}

	delete aux;
}

template <class T>
int Sort<T>::mergeSortCount(T * begin, T * end) {

	if (begin + 1 == end)
		return 0;

	T * A = begin;
	int n = end - begin;
	T * mid = begin + (n / 2);
	int ret = 0;

	ret += mergeSortCount(begin, mid);
	ret += mergeSortCount(mid, end);

	//merge
	T * aux = new T[n];
	T * leftIdx = begin, * rightIdx = mid;
	int i = 0;
	while (leftIdx != mid || rightIdx != end) {
		if (leftIdx == mid)
			aux[i++] = *(rightIdx++);
		else if (rightIdx == end)
			aux[i++] = *(leftIdx++);
		else{ if (*leftIdx < *rightIdx)
			aux[i++] = *(leftIdx++);
		else 
			aux[i++] = *(rightIdx++);
			ret++;
		}
	}

	for (i = 0; i < n; i++) {
		(*begin) = aux[i];
		begin++;
	}

	//delete aux;
	return ret;
}

template <class T>
int Sort<T>::partition(T * begin, T * end) {
	T * A = begin;
	int n = end - begin;
	int pivot = 0;

	int i, j = 0;
	for (i = 1; i < n; i++)
		if (A[i] < A[pivot]) {
			if (pivot == j)
				pivot = i;
			std::swap(A[i], A[j++]);
		}

	std::swap(A[j], A[pivot]);

	/*for (i = 0; i < n; i++)
		std::cout << A[i] << " ";
	std::cout << "\n";*/

	return j;
}

template <class T> 
void Sort<T>::quickSort(T * begin, T *  end) {
	std::stack< std::pair<T *, T * > > s;
	s.push(std::make_pair(begin, end));

	T * b, * e;

	while(!s.empty()){
		b = s.top().first;
		e = s.top().second;
		s.pop();

		if(b + 1 < e){
			int p = partition(b, e);

			s.push(std::make_pair(b, b + p));
			s.push(std::make_pair(b + p + 1, e));
		}
	}
}

template <class T> 
int Sort<T>::quickSortCount(T * begin, T *  end) {
	std::stack< std::pair<T *, T * > > s;
	s.push(std::make_pair(begin, end));

	T * b, * e;
	int ret = 0;

	while(!s.empty()){
		b = s.top().first;
		e = s.top().second;
		s.pop();

		if(b + 1 < e){
			int p = partition(b, e);
			ret += e - b + 1;
			s.push(std::make_pair(b, b + p));
			s.push(std::make_pair(b + p + 1, e));
		}
	}

	return ret;
}

#endif // !SORT_H