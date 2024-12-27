#pragma once
#include "PassarelaUsuari.h"

class PetitFlix {
private:
	PassarelaUsuari usuari;
	PetitFlix();

public:
	PassarelaUsuari obteUsuari();
	void iniciaSessio(PassarelaUsuari u);
	void tancaSessio();
	static PetitFlix& getInstance();
};