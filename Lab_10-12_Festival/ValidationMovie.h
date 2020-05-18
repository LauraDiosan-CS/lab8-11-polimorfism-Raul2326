#pragma once
#include "ValidationShow.h"
#include "Movie.h"

class ValidationMovie :public ValidationShow {
private:
	int errors;
	string message;
public:
	ValidationMovie();
	~ValidationMovie();

	int Validate(Show*);
};

