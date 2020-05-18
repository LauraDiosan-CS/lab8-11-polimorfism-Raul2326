#include "ValidationArtist.h"

ValidationArtist::ValidationArtist() : ValidationShow() {
	errors = 0;
}

ValidationArtist::~ValidationArtist() {

}

int ValidationArtist::Validate(Show* s) {
	Artist* a = (Artist*)s;
	errors = ValidationShow::Validate(a);
	return errors;
}
