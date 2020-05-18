#pragma once
#include <Windows.h>
#include <cwchar>
#include <vector>
#include <string>
#include "Service.h"
#include "Movie.h"
#include "Artist.h"
#include "User.h"
#include "ValidationShow.h"
#include "Exceptions.h"
using namespace std;

class UI {
private:
	Service S;

	void MenuLogin();
	void MenuApp();

	void CreateAccount();
	void LogIn();

	void AddM();
	void AddA();
	void UpdateM();
	void UpdateA();
	void DeleteM();
	void DeleteA();

	void FindShowByDate();
	void BuyTicket();
	void ShowMovies();
	void ShowArtists();

	void RunApp();
public:
	UI();
	UI(Service& S);
	~UI();
	void RunLogin();
};

