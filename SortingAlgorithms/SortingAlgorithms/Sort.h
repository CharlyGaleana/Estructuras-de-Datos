#ifndef SORT_H
#define SORT_H

template <class T>
class Sort {

public:
	Sort();
	void static insertionSort(T * begin, T * end);
	void static selectionSort(T * begin, T * end);
	void static bubbleSort(T * begin, T * end);

private:


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
void Sort<T>::bubbleSort(T * begin, T * end) {
	T * A = begin;
	int n = end - begin;
	int i, j;

	for (j = n; j; j--)
		for (i = 0; i < j - 1; i++)
			if (A[i] > A[i + 1])
				std::swap(A[i], A[i + 1]);
}

#endif // !SORT_H

