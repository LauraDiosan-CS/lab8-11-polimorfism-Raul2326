#include <iostream>
#include "UI.h"
using namespace std;

UI::UI() {
}

UI::UI(Service& S) {
	this->S = S;
}

UI::~UI() {
}

//---------------------------------------------------MENU--------------------------------------------------------------

void UI::MenuLogin() {
	cout << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "     |   Login   |" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << endl;
	cout << "  0.  Exit" << endl;
	cout << "  1.  Login" << endl;
	cout << "  2.  Create account" << endl;
}

void UI::MenuApp() {
	cout << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "     |   MENU   |" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << endl;
	cout << "  0.  Logout" << endl;
	cout << "  1.  Show movies" << endl;
	cout << "  2.  Show artists" << endl;
	cout << "  3.  Add movie" << endl;
	cout << "  4.  Add artist" << endl;
	cout << "  5.  Update movie" << endl;
	cout << "  6.  Update artist" << endl;
	cout << "  7.  Delete movie" << endl;
	cout << "  8.  Delete artist" << endl;
	cout << "  9.  Find show by date" << endl;
	cout << "  10.  Buy ticket" << endl;
}

//--------------------------------------------------ACCOUNT-------------------------------------------------------------

void UI::CreateAccount() {
	string user;
	string password;
	string confirm_psw;
	cout << endl;
	cout << "Insert user name: ";
	cin >> user;
	cout << "Insert password: ";
	cin >> password;
	cout << "Confirm password: ";
	cin >> confirm_psw;
	if (password.compare(confirm_psw) != 0) {
		cout << "Passwords does not match!" << endl;
	}
	else {
		int r = S.CreateAccount(user, password);
		if (r == -1) {
			cout << endl;
			cout << "User name is not available!" << endl;
		}
		if (r == 0) {
			cout << endl;
			cout << "Account created!" << endl;
		}
	}
}

void UI::LogIn() {
	string user;
	string password;
	cout << endl;
	cout << "Insert user name: ";
	cin >> user;
	cout << "Insert password: ";
	cin >> password;
	int r = S.LogIn(user, password);
	if (r == -1) {
		cout << endl;
		cout << "User or password invalid!" << endl;
	}
	else {
		cout << endl;
		cout << "Login successful!" << endl;
		RunApp();
	}
}

//--------------------------------------------------CRUD-----------------------------------------------------------------

void UI::AddA() {
	string name, date, time, location;
	int ava_places, sold_places;
	cout << "Insert the name: ";
	cin >> name;
	cout << "Insert the date: ";
	cin >> date;
	cout << "Insert the time: ";
	cin >> time;
	cout << "Insert the location: ";
	cin >> location;
	cout << "Insert the number of available places: ";
	cin >> ava_places;
	cout << "Insert the number of sold places: ";
	cin >> sold_places;
	try {
		Artist* a = new Artist(name, date, time, location, ava_places, sold_places);
		S.Add(a);
		cout << endl;
		cout << "          |  Artist added!  | 		" << endl;
	}
	catch (Exceptions & exception) {
		cout << endl;
		cout << exception.getMessage() << endl;
	}
}

void UI::AddM() {
	string name, date, time, location;
	int ava_places, sold_places;
	vector<string>actors;
	int n;
	cout << "Insert the name: ";
	cin >> name;
	cout << "Insert the number of actors: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		string actor;
		cout << "Insert actor: ";
		cin >> actor;
		actors.push_back(actor);
	}
	cout << "Insert the date: ";
	cin >> date;
	cout << "Insert the time: ";
	cin >> time;
	cout << "Insert the location: ";
	cin >> location;
	cout << "Insert the number of available places: ";
	cin >> ava_places;
	cout << "Insert the number of sold places: ";
	cin >> sold_places;
	try {
		Movie* m = new Movie(name, actors, date, time, location, ava_places, sold_places);
		S.Add(m);
		cout << endl;
		cout << "          |  Movie added!  | 		" << endl;
	}
	catch (Exceptions & exception) {
		cout << endl;
		cout << exception.getMessage() << endl;
	}
}

void UI::UpdateA() {
	ShowArtists();
	cout << endl;
	string name, date, time, location, nname, ndate, ntime, nlocation;
	int ava_places, sold_places, nava_places, nsold_places;
	cout << "Insert the name: ";
	cin >> name;
	cout << "Insert the date: ";
	cin >> date;
	cout << "Insert the time: ";
	cin >> time;
	cout << "Insert the location: ";
	cin >> location;
	cout << "Insert the number of available places: ";
	cin >> ava_places;
	cout << "Insert the number of sold places: ";
	cin >> sold_places;
	cout << endl;
	cout << "Insert the new name: ";
	cin >> nname;
	cout << "Insert the new date: ";
	cin >> ndate;
	cout << "Insert the new time: ";
	cin >> ntime;
	cout << "Insert the new location: ";
	cin >> nlocation;
	cout << "Insert the new number of available places: ";
	cin >> nava_places;
	cout << "Insert the new number of sold places: ";
	cin >> nsold_places;
	try {
		Artist* oa = new Artist(name, date, time, location, ava_places, sold_places);
		Artist* na = new Artist(nname, ndate, ntime, nlocation, nava_places, nsold_places);
		S.Update(oa, na);
		cout << endl;
		cout << "          |  Artist updated!  | 		" << endl;
	}
	catch (Exceptions & exception) {
		cout << endl;
		cout << exception.getMessage() << endl;
	}
}

void UI::UpdateM() {
	ShowMovies();
	cout << endl;
	string name, date, time, location, nname, ndate, ntime, nlocation;
	int ava_places, sold_places, nava_places, nsold_places;
	vector<string>actors, nactors;
	int n, nn;
	cout << "Insert the name: ";
	cin >> name;
	cout << "Insert the number of actors: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		string actor;
		cout << "Insert actor: ";
		cin >> actor;
		actors.push_back(actor);
	}
	cout << "Insert the date: ";
	cin >> date;
	cout << "Insert the time: ";
	cin >> time;
	cout << "Insert the location: ";
	cin >> location;
	cout << "Insert the number of available places: ";
	cin >> ava_places;
	cout << "Insert the number of sold places: ";
	cin >> sold_places;
	cout << endl;

	cout << "Insert the new name: ";
	cin >> nname;
	cout << "Insert the new number of actors: ";
	cin >> nn;
	for (int i = 0; i < n; i++) {
		string nactor;
		cout << "Insert new actor: ";
		cin >> nactor;
		nactors.push_back(nactor);
	}
	cout << "Insert the new date: ";
	cin >> ndate;
	cout << "Insert the new time: ";
	cin >> ntime;
	cout << "Insert the new location: ";
	cin >> nlocation;
	cout << "Insert the new number of available places: ";
	cin >> nava_places;
	cout << "Insert the new number of sold places: ";
	cin >> nsold_places;
	try {
		Movie* om = new Movie(name, actors, date, time, location, ava_places, sold_places);
		Movie* nm = new Movie(nname, nactors, ndate, ntime, nlocation, nava_places, nsold_places);
		S.Update(om, nm);
		cout << endl;
		cout << "          |  Movie updated!  | 		" << endl;
	}
	catch (Exceptions & exception) {
		cout << endl;
		cout << exception.getMessage() << endl;
	}
}

void UI::DeleteA() {
	ShowArtists();
	cout << endl;
	string name, date, time, location;
	int ava_places, sold_places;
	cout << "Insert the name: ";
	cin >> name;
	cout << "Insert the date: ";
	cin >> date;
	cout << "Insert the time: ";
	cin >> time;
	cout << "Insert the location: ";
	cin >> location;
	cout << "Insert the number of available places: ";
	cin >> ava_places;
	cout << "Insert the number of sold places: ";
	cin >> sold_places;
	try {
		Artist* a = new Artist(name, date, time, location, ava_places, sold_places);
		S.Delete(a);
		cout << endl;
		cout << "          |  Artist deleted!  | 		" << endl;
	}
	catch (Exceptions & exception) {
		cout << endl;
		cout << exception.getMessage() << endl;
	}
}

void UI::DeleteM() {
	ShowMovies();
	cout << endl;
	string name, date, time, location;
	int ava_places, sold_places;
	vector<string>actors;
	int n;
	cout << "Insert the name: ";
	cin >> name;
	cout << "Insert the number of actors: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		string actor;
		cout << "Insert actor: ";
		cin >> actor;
		actors.push_back(actor);
	}
	cout << "Insert the date: ";
	cin >> date;
	cout << "Insert the time: ";
	cin >> time;
	cout << "Insert the location: ";
	cin >> location;
	cout << "Insert the number of available places: ";
	cin >> ava_places;
	cout << "Insert the number of sold places: ";
	cin >> sold_places;
	try {
		Movie* m = new Movie(name, actors, date, time, location, ava_places, sold_places);
		S.Delete(m);
		cout << endl;
		cout << "          |  Movie Deleted!  | 		" << endl;
	}
	catch (Exceptions & exception) {
		cout << endl;
		cout << exception.getMessage() << endl;
	}
}

//----------------------------------------------FUNCTIONALITIES----------------------------------------------------------

void UI::ShowMovies() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (Show* s : S.getShows()) {
		if ((s->getSold_places() == s->getAva_places()) && (s->getType() == "M")) {
			SetConsoleTextAttribute(h, 12);
			cout << endl;
			cout << "___________________________________________________" << endl;
			cout << " | ~MOVIE~       |   " << s->getName() << "   |" << endl;
			cout << " | " << endl;
			cout << " | Main actor: " << s->getActors()[0] << endl;
			cout << " | Date: " << s->getDate() << endl;
			cout << " | Time: " << s->getTime() << endl;
			cout << " | Location: " << s->getLocation() << endl;
			cout << " | Places available: " << s->getAva_places() << endl;
			cout << " | Places sold: " << s->getSold_places() << endl;
			cout << "_|_________________________________________________" << endl;
			SetConsoleTextAttribute(h, 15);
		}
		if ((s->getSold_places() != s->getAva_places()) && (s->getType() == "M")) {
			cout << endl;
			cout << "___________________________________________________" << endl;
			cout << " | ~MOVIE~       |   " << s->getName() << "   |" << endl;
			cout << " | " << endl;
			cout << " | Main actor: " << s->getActors()[0] << endl;
			cout << " | Date: " << s->getDate() << endl;
			cout << " | Time: " << s->getTime() << endl;
			cout << " | Location: " << s->getLocation() << endl;
			cout << " | Places available: " << s->getAva_places() << endl;
			cout << " | Places sold: " << s->getSold_places() << endl;
			cout << "_|_________________________________________________" << endl;

		}
	}
}

void UI::ShowArtists() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (Show* s : S.getShows()) {
		if ((s->getSold_places() == s->getAva_places()) && (s->getType() == "A")) {
			SetConsoleTextAttribute(h, 12);
			cout << endl;
			cout << "_________________________________________________________" << endl;
			cout << " | ~ARTIST~       {+}   " << s->getName() << "   {-}     " << endl;
			cout << " | " << endl;
			cout << " | Date: " << s->getDate() << endl;
			cout << " | Time: " << s->getTime() << endl;
			cout << " | Location: " << s->getLocation() << endl;
			cout << " | Places available: " << s->getAva_places() << endl;
			cout << " | Places sold: " << s->getSold_places() << endl;
			cout << "_________________________________________________________" << endl;
			SetConsoleTextAttribute(h, 15);
		}
		if ((s->getSold_places() != s->getAva_places()) && (s->getType() == "A")) {
			cout << endl;
			cout << "_________________________________________________________" << endl;
			cout << " | ~ARTIST~       {+}   " << s->getName() << "   {-}     " << endl;
			cout << " | " << endl;
			cout << " | Date: " << s->getDate() << endl;
			cout << " | Time: " << s->getTime() << endl;
			cout << " | Location: " << s->getLocation() << endl;
			cout << " | Places available: " << s->getAva_places() << endl;
			cout << " | Places sold: " << s->getSold_places() << endl;
			cout << "_________________________________________________________" << endl;

		}
	}
}

void UI::FindShowByDate() {
	string date;
	cout << endl;
	cout << "Insert the date: ";
	cin >> date;
	vector<Show*> found = S.FindShowByDate(date);
	if (found.size() == 0) {
		cout << endl;
		cout << "There are no shows on that date!" << endl;
	}
	else {
		cout << endl;
		for (Show* s : found) {
			if (s->getType() == "M") {
				cout << endl;
				cout << "___________________________________________________" << endl;
				cout << " | ~MOVIE~       |   " << s->getName() << "   |" << endl;
				cout << " | " << endl;
				cout << " | Main actor: " << s->getActors()[0] << endl;
				cout << " | Date: " << s->getDate() << endl;
				cout << " | Time: " << s->getTime() << endl;
				cout << " | Location: " << s->getLocation() << endl;
				cout << " | Places available: " << s->getAva_places() << endl;
				cout << " | Places sold: " << s->getSold_places() << endl;
				cout << "_|_________________________________________________" << endl;
			}
			if (s->getType() == "A") {
				cout << "___________________________________________________" << endl;
				cout << " | ~ARTIST~       {+}   " << s->getName() << "   {-}     " << endl;
				cout << " | " << endl;
				cout << " | Date: " << s->getDate() << endl;
				cout << " | Time: " << s->getTime() << endl;
				cout << " | Location: " << s->getLocation() << endl;
				cout << " | Places available: " << s->getAva_places() << endl;
				cout << " | Places sold: " << s->getSold_places() << endl;
				cout << "_|_________________________________________________" << endl;
			}
		}
	}
}

void UI::BuyTicket() {
	string buyer;
	string name;
	int tickets;
	cout << endl;
	cout << "Insert name of the show: ";
	cin >> name;
	cout << "Insert how many tickets do you want to buy: ";
	cin >> tickets;
	cout << "Insert your name: ";
	cin >> buyer;
	try {
		S.BuyTickets(name, tickets);
		for (int i = 0; i < tickets; i++) {
			cout << endl;
			cout << " |=========================================================" << endl;
			cout << " |                 <<-  " << name << "  ->>" << endl;
			cout << " |                 *********************** " << endl;
			cout << " | " << endl;
			cout << " |    | Owner | " << buyer << endl;
			cout << " |                                     ~VIP~TICKET~   " << endl;
			cout << " |=========================================================" << endl;
		}
	}
	catch (Exceptions & exception) {
		cout << endl;
		cout << exception.getMessage() << endl;
	}
}

//---------------------------------------------------RUN-----------------------------------------------------------

void UI::RunLogin()
{
	bool ok = false;
	while (!ok) {
		MenuLogin();
		int cmd;
		cout << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "  Insert your option: ";
		cin >> cmd;
		cout << "----------------------------------------------------------" << endl;
		switch (cmd)
		{
		case(0): { ok = true; break; }
		case(2): { CreateAccount(); break; }
		case(1): { LogIn(); break; }
		default:
			cout << endl;
			cout << "	|   Invalid option!   |" << endl;
		}
	}
}

void UI::RunApp() {
	bool ok = false;
	ShowArtists();
	ShowMovies();
	while (!ok) {
		MenuApp();
		int cmd;
		cout << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "  Insert your option: ";
		cin >> cmd;
		cout << "----------------------------------------------------------" << endl;
		switch (cmd)
		{
		case(0): { ok = true; break; }
		case(1): { ShowMovies(); break; }
		case(2): { ShowArtists(); break; }
		case(3): {AddM(); break; }
		case(4): {AddA(); break; }
		case(5): {UpdateM(); break; }
		case(6): {UpdateA(); break; }
		case(7): {DeleteM(); break; }
		case(8): {DeleteA(); break; }
		case(9): { FindShowByDate(); break; }
		case(10): {BuyTicket(); break; }
		default:
			cout << endl;
			cout << "	|   Invalid option!   |" << endl;
		}
	}
}