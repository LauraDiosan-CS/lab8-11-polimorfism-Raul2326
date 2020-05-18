#pragma once
#include "Show.h"
#include <exception>
#include <string>

using namespace std;

class ValidationShow {
protected:
    int errors;
    string message;
public:
    ValidationShow();
    ~ValidationShow();

    virtual int Validate(Show*);
    string toString();
};