#include "ValidationMovie.h"

ValidationMovie::ValidationMovie() : ValidationShow() {
	errors = 0;
}

ValidationMovie::~ValidationMovie() {

}

int ValidationMovie::Validate(Show* s) {
	Movie* m = (Movie*)s;
	errors = ValidationShow::Validate(m);
	if (m->getActors().size() == 0) {
		ValidationShow::errors++;
		ValidationShow::message += " Actor list can not be empty! ";
	}
	return errors;
}
