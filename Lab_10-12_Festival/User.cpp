#include "User.h"
#include <ostream>
#include <iostream>

User::User(){
	this->name = "";
	this->password = "";
}

User::User(string name, string password){
	this->name = name;
	this->password = password;
}

User::User(const User& u){
	this->name = u.name;
	this->password = u.password;
}

User::~User(){

}


string User::getName(){
	return this->name;
}

string User::getPassword(){
	return this->password;
}

void User::setName(string name){
	this->name = name;
}

void User::setPassword(string password){
	this->password = password;
}

User& User::operator=(const User& u){
	this->setName(u.name);
	this->setPassword(u.password);
	return *this;
}

bool User::operator==(const User& user){
	return (name == user.name);
}

User* User::clone() {
	return new User(this->name, this->password);
}

string User::toString(string delim) {
	return "U" + delim + this->name + delim + this->password;
}

