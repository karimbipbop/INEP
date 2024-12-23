#include "PassarelaVisualitzaPel.h"

PassarelaVisualitzaPel::PassarelaVisualitzaPel() {
	sobrenom = "";
	titolPelicula = "";
	data = "";
	numVisualitzacions = 0;
}

PassarelaVisualitzaPel::PassarelaVisualitzaPel(sql::ResultSet* result) {
	if (result->next()) {
		sobrenom = result->getString("sobrenom");
		titolPelicula = result->getString("titol_pelicula");
		data = result->getString("data");
		numVisualitzacions = result->getInt("num_visualitzacions");
	}
}

PassarelaVisualitzaPel::PassarelaVisualitzaPel(string sobrenomP, string titolPeliculaP, string dataP, int numVisualitzacionsP) {
	sobrenom = sobrenomP;
	titolPelicula = titolPeliculaP;
	data = dataP;
	numVisualitzacions = numVisualitzacionsP;
}

void PassarelaVisualitzaPel::insereix() {
	try {
		ConnexioBD& c = ConnexioBD::getInstance();
		std::string query = "INSERT INTO visualitzacio_pelicula VALUES ('" +
			sobrenom + "', '" +
			titolPelicula + "', '" +
			data + "', '" +
			std::to_string(numVisualitzacions) + "')";
		c.execucio(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}

void PassarelaVisualitzaPel::modifica() {
	try {
		ConnexioBD& c = ConnexioBD::getInstance();
		std::string query = "UPDATE visualitzacio_pelicula SET "
			"num_visualitzacions = '" + std::to_string(numVisualitzacions) + "' "
			"WHERE sobrenom = '" + sobrenom + "' AND titol_pelicula = '" + titolPelicula + "' AND data = '" + data + "'";
		c.execucio(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}

void PassarelaVisualitzaPel::esborra() {
	try {
		ConnexioBD& c = ConnexioBD::getInstance();
		std::string query = "DELETE FROM visualitzacio_pelicula WHERE sobrenom = '" + sobrenom + "' AND titol_pelicula = '" + titolPelicula + "' AND data = '" + data + "'";
		c.execucio(query);
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}


string PassarelaVisualitzaPel::obteSobrenom()
{
	return sobrenom;
}

string PassarelaVisualitzaPel::obteTitolPelicula()
{
	return titolPelicula;
}

string PassarelaVisualitzaPel::obteData()
{
	return data;
}

int PassarelaVisualitzaPel::obteNumVisualitzacions()
{
	return numVisualitzacions;
}