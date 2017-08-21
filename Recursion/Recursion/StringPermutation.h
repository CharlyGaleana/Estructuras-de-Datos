#include <string>

#ifndef STRINGPERMUTATION_H
#define STRINGPERMUTATION_H

class StringPermutation {

public:
	StringPermutation(std::string str);
	void printPermutations();

private:
	std::string str;
	void printPermutations(std::string str, std::string perm);

};

#endif