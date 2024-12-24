#include "PassarelaModalitatSubscripcio.h"

PassarelaModalitatSubscripcio::PassarelaModalitatSubscripcio() {
	nom = "";
}

PassarelaModalitatSubscripcio::PassarelaModalitatSubscripcio(sql::ResultSet* result) {
	if (result->next()) {
		nom = result->getString("nom");
	}
}

PassarelaModalitatSubscripcio::PassarelaModalitatSubscripcio(string nomQ) {
	nom = nomQ;
}

void PassarelaModalitatSubscripcio::insereix() {
	try {
		ConnexioBD& c = ConnexioBD::getInstance();
		std::string query = "INSERT INTO modalitat_subscripcio VALUES ('" +
			nom + "')";
		c.execucio(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}

void PassarelaModalitatSubscripcio::modifica() {
	try {
		ConnexioBD& c = ConnexioBD::getInstance();
		std::string query = "UPDATE modalitat_subscripcio SET "
			"nom = '" + nom + "' WHERE nom = '" +
			nom + "'";
		c.execucio(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << endl;
	}
}

void PassarelaModalitatSubscripcio::esborra() {
	try {
		ConnexioBD& c = ConnexioBD::getInstance();
		std::string query = "DELETE FROM modalitat_subscripcio WHERE nom = '"
			+ nom + "'";
		c.execucio(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}

string obteNom() {
	return nom;
}