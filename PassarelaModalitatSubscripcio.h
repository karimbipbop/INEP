#include "ConnexioBD.h"
// 16.34
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