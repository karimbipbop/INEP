#pragma once
#include "PassarelaUsuari.h"

class PetitFlix {
private:
	PassarelaUsuari usuari;
	PetitFlix();

public:
	static PetitFlix& getInstance();
	PassarelaUsuari obteUsuari();
	void iniciaSessio(PassarelaUsuari u);
	void tancaSessio();
};