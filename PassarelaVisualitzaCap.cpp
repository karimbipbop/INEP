#include "PassarelaVisualitzaCap.h"

PassarelaVisualitzaCap::PassarelaVisualitzaCap() {
	sobrenom = "";
	titolSerie = "";
	numTemporada = 0;
	numCapitol = 0;
	data = "";
	numVisualitzacions = 0;
}

PassarelaVisualitzaCap::PassarelaVisualitzaCap(sql::ResultSet* result) {
	sobrenom = result->getString("sobrenom_usuari");
	titolSerie = result->getString("titol_serie");
	numTemporada = result->getInt("num_temporada");
	numCapitol = result->getInt("num_capitol");
	data = result->getString("data");
	numVisualitzacions = result->getInt("num_visualitzacions");
}

PassarelaVisualitzaCap::PassarelaVisualitzaCap(string sobrenomC, string titolSerieC, int numTemporadaC, int numCapitolC, string dataC, int numVisualitzacionsC) {
	sobrenom = sobrenomC;
	titolSerie = titolSerieC;
	numTemporada = numTemporadaC;
	numCapitol = numCapitolC;
	data = dataC;
	numVisualitzacions = numVisualitzacionsC;
}

void PassarelaVisualitzaCap::insereix() {
	try {
		ConnexioBD& c = ConnexioBD::getInstance();
		std::string query = "INSERT INTO visualitzacio_capitol VALUES ('" +
			sobrenom + "', '" + titolSerie + "', '" + 
			std::to_string(numTemporada) + "', '" +
			std::to_string(numCapitol) + "', '" + data + "', '" +
			std::to_string(numVisualitzacions) + "')";
		c.execucio(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}

void PassarelaVisualitzaCap::modifica() {
	try {
		ConnexioBD& c = ConnexioBD::getInstance();
		std::string query = "UPDATE visualitzacio_capitol SET "
			"num_visualitzacions = '" + std::to_string(numVisualitzacions) + "' "
			"WHERE sobrenom_usuari = '" + sobrenom + "' AND titol_serie = '" + titolSerie + "' AND "
			+ "num_temporada = '" + std::to_string(numTemporada) + "' AND num_capitol = '" +
			std::to_string(numCapitol) + "'";
		c.execucio(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}

void PassarelaVisualitzaCap::esborra() {
	try {
		ConnexioBD& c = ConnexioBD::getInstance();
		std::string query = "DELETE FROM visualitzacio_capitol WHERE sobrenom_usuari = '" + sobrenom +
			"' AND titol_serie = '" + titolSerie + "' AND num_temporada = '" + std::to_string(numTemporada) +
			"' AND num_capitol = '" + std::to_string(numCapitol) + "'";
		c.execucio(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}


string PassarelaVisualitzaCap::obteSobrenom()
{
	return sobrenom;
}

string PassarelaVisualitzaCap::obteTitolSerie()
{
	return titolSerie;
}

int PassarelaVisualitzaCap::obteNumTemporada()
{
	return numTemporada;
}

int PassarelaVisualitzaCap::obteNumCapitol()
{
	return numCapitol;
}

string PassarelaVisualitzaCap::obteData()
{
	return data;
}

int PassarelaVisualitzaCap::obteNumVisualitzacions()
{
	return numVisualitzacions;
}

void PassarelaVisualitzaCap::augmentaNumVisualitzacions() {
	++numVisualitzacions;
}