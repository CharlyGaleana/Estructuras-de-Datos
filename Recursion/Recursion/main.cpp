#include <iostream>
#include <string>
#include "StringPermutation.h"
#include "EditDistance.h"

int main() {
	std::string a, b;
	a = "hola", b = "oa";
	std::cout << EditDistance::editDistance(a, b) << "\n";

	int x;
	std::cin >> x;
	return 0;
}