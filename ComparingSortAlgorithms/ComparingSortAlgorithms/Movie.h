#include <string>

#ifndef MOVIE_H
#define MOVIE_H

class Movie{

public:
	Movie();
	Movie(int s, int year, std::string title);
	bool operator<(const Movie &o) const;
	std::string title;
	int year;
	int s;

private:
	//std::string title;

};

#endif
