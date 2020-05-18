#include "Artist.h"

Artist::Artist() :Show() {

}

Artist::Artist(string name, string date, string time, string location, int ava_places, int sold_place) : Show(name, date, time, location, ava_places, sold_place) {

}

Artist::Artist(const Artist& a):Show(a) {

}

Artist::~Artist() {

}

Artist* Artist::clone() {
	return new Artist(this->name, this->date, this->time, this->location, this->ava_places, this->sold_places);
}

Artist& Artist::operator=(const Artist& a) {
	Show::operator=(a);
	return *this;
}

bool Artist::operator==(const Artist& a) {
	return Show::operator==(a);
}

string Artist::toString(string delim) {
	return "A" + delim + Show::toString(delim);
}

string Artist::getType() {
	return "A";
}