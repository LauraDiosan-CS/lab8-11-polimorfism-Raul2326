#include "Service.h"

Service::Service() {
	R = NULL;
	ValidateS = NULL;
}

Service::Service(Repo*R, ValidationShow* ValidateS) {
	this->R = R;
	this->ValidateS = ValidateS;
}

Service::~Service() {

}

void Service::Add(Show* s) {
	try {
		R->AddS(s);
	}
	catch (ValidationException & exception) {
		throw Exceptions("Add failed! " + exception.Reason());
	}
}

void Service::Update(Show* os, Show* ns) {
	try {
		R->UpdateS(os, ns);
	}
	catch (ValidationException & exception) {
		throw Exceptions("Update failed! " + exception.Reason());
	}
}

void Service::Delete(Show* s) {
	try {
		R->DeleteS(s);
	}
	catch (ValidationException & exception) {
		throw Exceptions("Delete failed! " + exception.Reason());
	}
}

int Service::CreateAccount(string user, string password) {
	vector<User*> users = R->getAllU();
	User* n = new User(user, password);
	for (User* u : users) {
		string name = u->getName();
		if (name.compare(user) == 0) {
			return -1;
		}
	}
	R->AddU(n);
	return 0;
}

int Service::LogIn(string user, string password) {
	vector<User*> users = R->getAllU();
	User* n = new User(user, password);
	for (User* u : users) {
		if (*u == *n) {
			return 0;
		}
	}
	return -1;
}

vector<Show*> Service::getShows() {
	return R->getAllS();
}

vector<Show*> Service::FindShowByDate(string date) {
	vector<Show*>all = getShows();
	vector<Show*>found;
	for (Show* s : all) {
		if (s->getDate().compare(date) == 0) {
			found.push_back(s);
		}
	}
	return found;
}

void Service::BuyTickets(string name, int tickets) {
	vector<Show*> shows = getShows();
	string type;
	for (Show* s : shows) {
		if (s->getName() == name) {
			type = s->getType();
			if (type == "M") {
				try {
					Movie* m = new Movie(name, s->getActors(), s->getDate(), s->getTime(), s->getLocation(), s->getAva_places(), tickets + s->getSold_places());
					R->UpdateS(s, m);
				}
				catch (ValidationException& exception) {
					throw Exceptions(" There are not enough places available! ");
				}
			}
			if (type == "A") {
				try {
					Artist* a = new Artist(name, s->getDate(), s->getTime(), s->getLocation(), s->getAva_places(), s->getSold_places() + tickets);
					R->UpdateS(s, a);
				}
				catch (ValidationException& exception) {
					throw Exceptions(" There are not enough places available! ");
				}
			}
		}
	}
}