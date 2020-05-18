#pragma once
#include "Repo.h"
using namespace std;

class RepoTXT : public Repo {
public:
	RepoTXT();
	RepoTXT(string fileName, ValidationShow* ValidateS);
	~RepoTXT();
	void loadFromFile();
	void saveToFile();
};