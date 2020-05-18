#pragma once
#include "Show.h"

class Movie:public Show{
private:
	vector<string> actors;
public:
	Movie();
	Movie(string name, vector<string> actors, string date, string time, string location, int ava_places, int sold_place);
	Movie(const Movie& s);
	~Movie();

	Movie* clone();

	vector<string> getActors();

	void setActors(vector<string>actors);

	string convert_vector_to_string(vector<string>, string delim);
	Movie& operator=(const Movie& m);
	bool operator==(const Movie& m);
	string toString(string delim);
	string getType();


};

