#pragma once
#include <exception>
#include <string>

using namespace std;

class ValidationException : public exception
{
private:
    string message;
public:
    ValidationException();
    ValidationException(string message);
    ~ValidationException();

    virtual string Reason() throw();
};
