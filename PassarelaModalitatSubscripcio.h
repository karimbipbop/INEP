#include "ConnexioBD.h"
// 16.41
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