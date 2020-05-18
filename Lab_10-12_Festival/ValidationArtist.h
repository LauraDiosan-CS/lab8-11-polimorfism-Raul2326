#pragma once
#include "ValidationShow.h"
#include "Artist.h"

class ValidationArtist :public ValidationShow {
private:
	int errors;
	string message;
public:
	ValidationArtist();
	~ValidationArtist();

	int Validate(Show*);
};

