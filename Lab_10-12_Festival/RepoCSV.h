#pragma once
#include "Repo.h"
using namespace std;

class RepoCSV : public Repo {
public:
	RepoCSV();
	RepoCSV(string fileName, ValidationShow* ValidateS);
	~RepoCSV();
	void loadFromFile();
	void saveToFile();
};