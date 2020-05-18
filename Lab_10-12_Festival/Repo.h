#pragma once
#include "Show.h"
#include "Movie.h"
#include "Artist.h"
#include "User.h"
#include <vector>
#include <algorithm>
#include <string>
#include "ValidationShow.h"
#include "ValidationArtist.h"
#include "ValidationMovie.h"
#include "ValidationException.h"

using namespace std;

class Repo {
protected:
	vector<Show*> shows;
	vector<User*> users;
	string fileName;
	ValidationShow* ValidateS;
public:
	Repo();
	Repo(string fileName, ValidationShow* ValidateS);
	~Repo();
	void setFileName(string fileName);

	vector<Show*> getAllS();
	vector<User*> getAllU();

	int getSizeS();
	int getSizeU();

	Show* getShow(int poz);
	User* getUser(int poz);

	void AddS(Show* s);
	void AddU(User* u);

	void UpdateS(Show* os, Show* ns);
	void UpdateU(User* ou, User* nu);

	void DeleteS(Show* s);
	void DeleteU(User* u);

	void emptyRepo();
	int Count_Number_Actors(string line, char delim);

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};


