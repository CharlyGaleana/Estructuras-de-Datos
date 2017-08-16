#include <iostream>
#include "LinkedList.h"

int main(){
	LinkedList<int> * list = new LinkedList<int>();
	list->insertAtTheEnd(2);
	list->insertAtTheEnd(4);
	list->insertAtTheEnd(3);
	list->insertAt(1, 1);
	list->insertAt(3, 8);
	list->removeFirst();
	list->insertAt(4, 0);
	list->removeAt(0);
	list->insertAt(2, 5);
	list->removeAt(2);
	list->removeAt(3);
	list->insertAtTheEnd(-1);
	list->printElements();
	list->printElementsInInverseOrder();
	int a;
	std::cin >> a;
	return 0;
}