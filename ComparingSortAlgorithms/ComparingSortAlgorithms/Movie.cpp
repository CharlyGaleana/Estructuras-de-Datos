#include "Movie.h"
#include "string"

Movie::Movie(){

}

Movie::Movie(int year, int s, std::string title){
	this->year = year;
	this->s = s;
	this->title = title;
}

bool Movie::operator<(const Movie &o) const{
	return this->title < o.title;
}