#include "PetitFlix.h"

PetitFlix::PetitFlix() {
	usuari = PassarelaUsuari();
}

PetitFlix& PetitFlix::getInstance() {
	static PetitFlix p;
	return p;
}

PassarelaUsuari PetitFlix::obteUsuari() {
	return usuari;
}

void PetitFlix::iniciaSessio(PassarelaUsuari u) {
	usuari = u;
}

void PetitFlix::tancaSessio() {
	usuari = PassarelaUsuari();
}