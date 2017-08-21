#include <iostream>
#include <string>
#include "StringPermutation.h"

StringPermutation::StringPermutation(std::string str) {
	this->str = str;
}

void StringPermutation::printPermutations(std::string str, std::string perm) {
	if (str.size() == 0) {
		std::cout << perm << "\n";
		return;
	}

	int i = 0;
	for (i = 0; i < str.size(); i++) 
		printPermutations(str.substr(0, i) + str.substr(i + 1, str.size() - i + 1), perm + str[i]);
}

void StringPermutation::printPermutations() {
	this->printPermutations(this->str, "");
}