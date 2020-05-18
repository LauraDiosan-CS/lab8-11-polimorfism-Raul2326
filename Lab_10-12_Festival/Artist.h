#pragma once
#include "Show.h"

class Artist:public Show{
private:
public:
	Artist();
	Artist(string name, string date, string time, string location, int ava_places, int sold_place);
	Artist(const Artist& a);
	~Artist();

	Artist* clone();

	Artist& operator=(const Artist& a);
	bool operator==(const Artist& a);
	string toString(string delim);
	string getType();
};

