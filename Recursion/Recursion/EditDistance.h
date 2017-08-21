#include <string>

#ifndef EDITDISTANCE_H
#define EDITDISTANCE_H

class EditDistance {

public:
	EditDistance(std::string a, std::string b);
	static int editDistance(std::string a, std::string b);

private:
	int editDistance(int i, int j);
	std::string a, b;

};

#endif
