#include "ValidationShow.h"

ValidationShow::ValidationShow()
{
	errors = 0;
}

ValidationShow::~ValidationShow()
{
}

int ValidationShow::Validate(Show* s)
{
	errors = 0;
	if (s->getName()== "") {
		errors++;
		message += " Name can not be null! ";
	}
	if (s->getDate() == "") {
		errors++;
		message += " Date can not be null! ";
	}
	if (s->getTime() == "") {
		errors++;
		message += " Time can not be null! ";
	}
	if (s->getLocation() == "") {
		errors++;
		message += " Location can not be null! ";
	}
	if (s->getAva_places() <= 0) {
		errors++;
		message += " The number of available places can not be 0 or smaller! ";
	}
	if (s->getSold_places() < 0) {
		errors++;
		message += " The number of sold places can not be below 0! ";
	}
	if (s->getAva_places() < s->getSold_places()) {
		errors++;
		message += " The number of sold places can not be bigger then the number of available places! ";
	}
	return errors;
}

string ValidationShow::toString() {
	return message;
}