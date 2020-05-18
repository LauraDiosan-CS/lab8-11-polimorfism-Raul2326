#include "Movie.h"

Movie::Movie():Show() {

}

Movie::Movie(string name, vector<string> actors, string date, string time, string location, int ava_places, int sold_place) : Show(name, date, time, location, ava_places, sold_place) {
	this->actors = actors;
}

Movie::Movie(const Movie& m) : Show(m) {
	this->actors = m.actors;
}

Movie::~Movie() {

}

Movie* Movie::clone() {
	return new Movie(this->name, this->actors, this->date, this->time, this->location, this->ava_places, this->sold_places);
}

vector<string> Movie::getActors() {
	return actors;
}

void Movie::setActors(vector<string>actors) {
	this->actors = actors;
}

Movie& Movie::operator=(const Movie& m) {
	Show::operator=(m);
	this->actors = m.actors;
	return *this;
}

bool Movie::operator==(const Movie& m) {
	return (Show::operator==(m))&&(this->actors == m.actors);
}

string Movie::convert_vector_to_string(vector<string>actors, string delim) {
	string s;
	for (string name : actors) {
		s += delim + name;
	}
	return s;
}

string Movie::toString(string delim) {
	return "M" + delim + Show::toString(delim) + convert_vector_to_string(actors, delim);
}

string Movie::getType() {
	return "M";
}
