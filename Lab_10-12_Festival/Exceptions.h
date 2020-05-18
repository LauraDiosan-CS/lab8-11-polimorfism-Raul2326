#pragma once
#include <string>
#include <iostream>
#include <exception>

using namespace std;

class Exceptions : public exception {
private:
    string message;
public:
    Exceptions(string message);

    string getMessage();
};
