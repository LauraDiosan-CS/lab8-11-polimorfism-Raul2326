#include "Repo.h"

Repo::Repo() {
	this->ValidateS = new ValidationShow();
}

Repo::Repo(string fileName, ValidationShow* ValidateS) {
	this->fileName = fileName;
	this->ValidateS = ValidateS;
}

Repo::~Repo() {

}

void Repo::setFileName(string fileName) {
	this->fileName = fileName;
}

vector<Show*> Repo::getAllS() {
	return this->shows;
}

vector<User*> Repo::getAllU() {
	return this->users;
}

int Repo::getSizeS() {
	return this->shows.size();
}

int Repo::getSizeU() {
	return this->users.size();
}

Show* Repo::getShow(int poz) {
	if (poz >= 0 && poz < this->getSizeS()) {
		return this->shows[poz]->clone();
	}
	return new Movie();
}

User* Repo::getUser(int poz) {
	if (poz >= 0 && poz < this->getSizeU()) {
		return this->users[poz]->clone();
	}
	return new User();
}

void Repo::AddS(Show* s) {
	string type = s->getType();
	if (type == "M") {
		this->ValidateS = new ValidationMovie();
		if (((ValidationMovie*)ValidateS)->Validate(s) == 0) {
			this->shows.push_back(s->clone());
			this->saveToFile();
		}
		else {
			throw ValidationException(this->ValidateS->toString());
		}
	}
	if (type == "A") {
		this->ValidateS = new ValidationArtist();
		if (((ValidationArtist*)ValidateS)->Validate(s) == 0) {
			this->shows.push_back(s->clone());
			this->saveToFile();
		}
		else {
			throw ValidationException(this->ValidateS->toString());
		}
	}

}

void Repo::AddU(User* u) {
	this->users.push_back(u->clone());
	this->saveToFile();
}

void Repo::UpdateS(Show* os, Show* ns) {
	if (os->getType() == ns->getType()) {
		if (ns->getType() == "M") {
			this->ValidateS = new ValidationMovie();
			if (((ValidationMovie*)ValidateS)->Validate(ns) == 0) {
				for (int i = 0; i < this->shows.size(); i++) {
					if (*(this->getShow(i)) == *os) {
						delete this->shows[i];
						this->shows[i] = ns->clone();
						this->saveToFile();
					}
				}
			}
			else {
				throw ValidationException(this->ValidateS->toString());
			}
		}
		if (ns->getType() == "A") {
			this->ValidateS = new ValidationArtist();
			if (((ValidationArtist*)ValidateS)->Validate(ns) == 0) {
				for (int i = 0; i < this->shows.size(); i++) {
					if (*(this->getShow(i)) == *os) {
						delete this->shows[i];
						this->shows[i] = ns->clone();
						this->saveToFile();
					}
				}
			}
			else {
				throw ValidationException(this->ValidateS->toString());
			}
		}
	}
}

void Repo::UpdateU(User* ou, User* nu) {
	for (int i = 0; i < this->users.size(); i++) {
		if (*(this->getUser(i)) == *ou) {
			delete this->users[i];
			this->users[i] = nu->clone();
			this->saveToFile();
			return;
		}
	}
}

void Repo::DeleteS(Show* s) {
	for (int i = 0; i < this->shows.size(); i++) {
		if (**(this->shows.begin() + i) == *s) {
			delete this->shows[i];
			this->shows.erase(this->shows.begin() + i);
			this->saveToFile();
			return;
		}
	}
}

void Repo::DeleteU(User* u) {
	for (int i = 0; i < this->users.size(); i++) {
		if (**(this->users.begin() + i) == *u) {
			delete this->users[i];
			this->users.erase(this->users.begin() + i);
			this->saveToFile();
			return;
		}
	}
}

int Repo::Count_Number_Actors(string line, char delim) {
	int count = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == delim) {
			count++;
		}
	}
	return count;
}

void Repo::emptyRepo() {
	for (int i = 0; i < this->getSizeS(); i++) {
		delete this->shows[i];
	}
	this->shows.clear();
	for (int i = 0; i < this->getSizeU(); i++) {
		delete this->users[i];
	}
	this->users.clear();
}

