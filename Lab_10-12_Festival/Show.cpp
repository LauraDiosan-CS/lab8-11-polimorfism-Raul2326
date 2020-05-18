#include "Show.h"

Show::Show() {
	this->ava_places = 0;
	this->sold_places = 0;
}

Show::Show(string name, string date, string time, string location, int ava_places, int sold_place) {
	this->name = name;
	this->date = date;
	this->time = time;
	this->location = location;
	this->ava_places = ava_places;
	this->sold_places = sold_place;
}

Show::Show(const Show& s) {
	this->name = s.name;
	this->date = s.date;
	this->time = s.time;
	this->location = s.location;
	this->ava_places = s.ava_places;
	this->sold_places = s.sold_places;
}

Show::~Show() {

}

Show* Show::clone() {
	return new Show(this->name, this->date, this->time, this->location, this->ava_places, this->sold_places);
}

string Show::getName() {
	return this->name;
}

string Show::getDate() {
	return this->date;
}

string Show::getTime() {
	return this->time;
}

string Show::getLocation() {
	return this->location;
}

int Show::getAva_places() {
	return this->ava_places;
}

int Show::getSold_places() {
	return this->sold_places;
}

void Show::setName(string name) {
	this->name = name;
}

void Show::setDate(string date) {
	this->date = date;
}

void Show::setTime(string time) {
	this->time = time;
}

void Show::setLocation(string location) {
	this->location = location;
}

void Show::setAva_places(int ava_places) {
	this->ava_places = ava_places;
}

void Show::setSold_places(int sold_places) {
	this->sold_places = sold_places;
}

Show& Show::operator=(const Show& s) {
	this->name = s.name;
	this->date = s.date;
	this->time = s.time;
	this->location = s.location;
	this->ava_places = s.ava_places;
	this->sold_places = s.sold_places;
	return *this;
}

string Show::convert_int_to_string(int n) {
	string s = to_string(n);
	return s;
}

bool Show::operator==(const Show& s) {
	return (this->name == s.name) && (this->date == s.date) && (this->time == s.time) && (this->location == s.location) && (this->ava_places == s.ava_places) && (this->sold_places == s.sold_places);
}

string Show::toString(string delim) {
	return this->name + delim + this->date + delim + this->time + delim + this->location + delim + convert_int_to_string(this->ava_places) + delim + convert_int_to_string(this->sold_places);
}

string Show::getType() {
	return "";
}

vector<string> Show::getActors() {
	vector<string> a;
	return a;
}
