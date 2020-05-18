#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Show{
protected:
	string name;
	string date;
	string time;
	string location;
	int ava_places;
	int sold_places;
public:
	Show();
	Show(string name, string date, string time, string location, int ava_places, int sold_place);
	Show(const Show& s);
	~Show();

	virtual Show* clone();
	string convert_int_to_string(int n);

	string getName();
	string getDate();
	string getTime();
	string getLocation();
	int getAva_places();
	int getSold_places();

	void setName(string name);
	void setDate(string date);
	void setTime(string time);
	void setLocation(string location);
	void setAva_places(int ava_places);
	void setSold_places(int sold_places);

	Show& operator=(const Show& s);
	bool operator==(const Show& s);
	virtual string toString(string delim);
	virtual string getType();
	virtual vector<string> getActors();
};

