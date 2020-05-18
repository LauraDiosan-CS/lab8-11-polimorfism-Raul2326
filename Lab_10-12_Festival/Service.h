#pragma once
#include "Repo.h"
#include "Artist.h"
#include "Movie.h"
#include "User.h"
#include "ValidationShow.h"
#include "ValidationException.h"
#include "Exceptions.h"

class Service {
private:
	Repo* R;
	ValidationShow* ValidateS;
public:
	Service();
	Service(Repo* R, ValidationShow* ValidateS);
	~Service();

	void Add(Show* s);
	void Update(Show* os, Show* ns);
	void Delete(Show* s);

	int CreateAccount(string user, string password);
	int LogIn(string user, string password);
	vector<Show*> FindShowByDate(string date);
	void BuyTickets(string name, int tickets);

	vector<Show*> getShows();
};

