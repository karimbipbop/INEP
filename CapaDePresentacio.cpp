#include "CapaDePresentacio.h"

CapaDePresentacio::CapaDePresentacio() {

}

void CapaDePresentacio::processarRegistreUsuari()
{
	try {
		ConnexioBD& c = ConnexioBD::getInstance();
		// Sentència SQL per obtenir totes les files de la taula usuari
		Usuari n;
		cout << "Insereix el teu sobrenom, nom i correu elecotronic respectivament" << endl;
		cin >> n.sobrenom;
		string sql = "SELECT COUNT(*) AS count FROM Usuari WHERE sobrenom = '" + n.sobrenom + "'";
		sql::ResultSet* res = c.consulta(sql);
		res->next();
		if (res->getInt("count") != 0) {
			cout << "ERROR: Ja existeix l'usuari '" << n.sobrenom << "' a la base de dades.\n";
		}
		else {
			cin >> n.nom >> n.correu;
			string sql = "INSERT INTO Usuari (sobrenom, nom, correu_electronic) VALUES ('" + n.sobrenom + "', '" + n.nom + "', '" + n.correu + "')";
			c.execucio(sql);
			cout << "L'Usuari " << n.sobrenom << " s'ha registrat correctament!" << endl;
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}

void CapaDePresentacio::processarConsultaUsuari()
{
	try {
		ConnexioBD& c = ConnexioBD::getInstance();
		// Sentència SQL per obtenir totes les files de la taula usuari
		string sobrenom;
		cout << "Entra el teu sobrenom" << endl;
		cin >> sobrenom;
		string sql = "SELECT * FROM Usuari WHERE sobrenom='" + sobrenom + "'";
		sql::ResultSet* res = c.consulta(sql);
		if (res->next()) {
			cout << "Sobrenom: " << res->getString("sobrenom") << endl;
			cout << "Nom: " << res->getString("nom") << endl;
			cout << "Correu: " << res->getString("correu_electronic") << endl;
		}
		else {
			cout << "No s'ha trobat l'usuari '" << sobrenom << "' a la base de dades.\n";
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}

void CapaDePresentacio::processarModificaUsuari()
{
	try {
		ConnexioBD& c = ConnexioBD::getInstance();
		// Sentència SQL per obtenir totes les files de la taula usuari
		Usuari n;
		cout << "Insereix el teu sobrenom" << endl;
		cin >> n.sobrenom;
		string sql = "SELECT COUNT(*) AS count FROM Usuari WHERE sobrenom = '" + n.sobrenom + "'";
		sql::ResultSet* res = c.consulta(sql);
		res->next();
		if (res->getInt("count") == 0) {
			cout << "ERROR: No existeix l'usuari '" << n.sobrenom << "' a la base de dades.\n";
		}
		else {
			cout << "Insereix el teu nou nom i el teu nou correu electronic" << endl;
			cin >> n.nom >> n.correu;
			sql = "UPDATE Usuari SET nom = '" + n.nom + "', correu_electronic = '" + n.correu + "' WHERE sobrenom = '" + n.sobrenom + "'";
			c.execucio(sql);
			cout << "L'Usuari " << n.sobrenom << " s'ha modificat correctament!" << endl;
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}

void CapaDePresentacio::processarEsborraUsuari()
{
	try {
		ConnexioBD& c = ConnexioBD::getInstance();
		// Sentència SQL per obtenir totes les files de la taula usuari
		Usuari n;
		cout << "Insereix el teu sobrenom" << endl;
		cin >> n.sobrenom;
		string sql = "SELECT COUNT(*) AS count FROM Usuari WHERE sobrenom = '" + n.sobrenom + "'";
		sql::ResultSet* res = c.consulta(sql);
		res->next();
		if (res->getInt("count") == 0) {
			cout << "ERROR: No existeix l'usuari '" << n.sobrenom << "' a la base de dades.\n";
		}
		else {
			string sql = "DELETE FROM Usuari WHERE sobrenom='" + n.sobrenom + "'";
			c.execucio(sql);
			cout << "L'Usuari " << n.sobrenom << " s'ha esborrat correctament!" << endl;
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}

void CapaDePresentacio::processarGestioPelicules()
{
	cout << "S'ha processat l'opcio Gestio pel.licules" << endl;
}

void CapaDePresentacio::processarGestioSeries()
{
	cout << "S'ha processat l'opcio Gestio series" << endl;
}

void CapaDePresentacio::processarConsultaQualificacioEdat()
{
	cout << "S'ha processat l'opcio Consulta per qualificacio d'edat" << endl;
}

void CapaDePresentacio::processarUltimesNovetats()
{
	cout << "S'ha processat l'opcio Ultimes novetats" << endl;
}

void CapaDePresentacio::processarProximesEstrenes()
{
	cout << "S'ha processat l'opcio Proximes estrenes" << endl;
}