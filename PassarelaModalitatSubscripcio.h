#pragma once
#include "ConnexioBD.h"

class PassarelaModalitatSubscripcio {
private:
	string nom;

public:

	PassarelaModalitatSubscripcio();
	PassarelaModalitatSubscripcio(sql::ResultSet* result);
	PassarelaModalitatSubscripcio(string nomQ);
	void insereix();
	void modifica();
	void esborra();

	string obteNom();
};