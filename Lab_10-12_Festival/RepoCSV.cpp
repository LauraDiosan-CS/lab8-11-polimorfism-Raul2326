#include "RepoCSV.h"
#include <fstream>

RepoCSV::RepoCSV() : Repo() {

}

RepoCSV::RepoCSV(string fileName, ValidationShow* ValidateS) : Repo(fileName, ValidateS) {
	loadFromFile();
}

RepoCSV::~RepoCSV() {

}

void RepoCSV::loadFromFile() {
	ifstream f(this->fileName);
	if (f.is_open()) {
		this->emptyRepo();
		string line;
		string delim = ",";
		while (getline(f, line)) {
			if (line.substr(0, 1) == "M") {

				line = line.erase(0, 2);

				int pos = line.find(delim);
				string name = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				string date = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				string time = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				string location = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				int ava_places = stoi(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				int sold_places = stoi(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				int number_actors = Repo::Count_Number_Actors(line, ',');
				vector<string>actors;
				for (int i = 0; i <= number_actors; i++) {
					pos = line.find(delim);
					string n = line.substr(0, pos);
					line = line.erase(0, pos + 1);
					actors.push_back(n);
				}
				Movie* m = new Movie(name, actors, date, time, location, ava_places, sold_places);
				this->shows.push_back(m);
			}
			else if (line.substr(0, 1) == "A")
			{
				line = line.erase(0, 2);

				int pos = line.find(delim);
				string name = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				string date = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				string time = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				string location = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				int ava_places = stoi(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				int sold_places = stoi(line.substr(0, pos));

				Artist* a = new Artist(name, date, time, location, ava_places, sold_places);
				this->shows.push_back(a);
			}
			else if (line.substr(0, 1) == "U") {

				line = line.erase(0, 2);

				int pos = line.find(delim);
				string name = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				string password = line.substr(0, pos);

				User* u = new User(name, password);
				this->users.push_back(u);
			}
		}
		f.close();
	}
}

void RepoCSV::saveToFile() {
	ofstream f(this->fileName);
	if (f.is_open()) {
		for (Show* s : this->shows) {
			f << s->toString(",") << endl;
		}
		for (User* u : this->users) {
			f << u->toString(",") << endl;
		}
	}
}
