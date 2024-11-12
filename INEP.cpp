// INEP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>

using namespace std;

struct usuari {
	string sobrenom;
	string nom;
	string correu;
};

void procesarRegistreUsuari()
{
	sql::mysql::MySQL_Driver* driver = NULL;
	sql::Connection* con = NULL;
	sql::Statement* stmt = NULL;
	try {
		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep10", "iyohthe7wiiFie");
		con->setSchema("inep10");
		stmt = con->createStatement();
		// Sentència SQL per obtenir totes les files de la taula usuari
		usuari n;
		cout << "Insereix el teu sobrenom, nom i correu elecotrónic respectivament" << endl;
		cin >> n.sobrenom >> n.nom >> n.correu;
		string sql = "INSERT INTO Usuari (sobrenom, nom, correu_electronic) VALUES ('" + n.sobrenom + "', '" + n.nom + "', '" + n.correu + "')";
		stmt->execute(sql);
		cout << "L'Usuari " << n.sobrenom << " s'ha registrat correctament!" << endl;
		con->close();
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
		// si hi ha un error es tanca la connexió (si esta oberta)
		if (con != NULL) con->close();
	}
}

void procesarConsultaUsuari()
{
	sql::mysql::MySQL_Driver* driver = NULL;
	sql::Connection* con = NULL;
	sql::Statement* stmt = NULL;
	try {
		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep10", "iyohthe7wiiFie");
		con->setSchema("inep10");
		stmt = con->createStatement();
		// Sentència SQL per obtenir totes les files de la taula usuari
		string sobrenom;
		cout << "Entra el teu sobrenom" << endl;
		cin >> sobrenom;
		string sql = "SELECT * FROM Usuari WHERE sobrenom='" + sobrenom + "";
		sql::ResultSet* res = stmt->executeQuery(sql);
		// Bucle per recórrer les dades retornades mostrant les dades de cada fila
		while (res->next()) {
			// a la funció getString fem servir el nom de la columna de la taula
			cout << "Sobrenom: " << res->getString("sobrenom") << endl;
			cout << "Nom: " << res->getString("nom") << endl;
			cout << "Correu: " << res->getString("correu_electronic") << endl;
		}
		con->close();
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
		// si hi ha un error es tanca la connexió (si esta oberta)
		if (con != NULL) con->close();
	}
}

void procesarModificaUsuari()
{
	sql::mysql::MySQL_Driver* driver = NULL;
	sql::Connection* con = NULL;
	sql::Statement* stmt = NULL;
	try {
		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep10", "iyohthe7wiiFie");
		con->setSchema("inep10");
		stmt = con->createStatement();
		// Sentència SQL per obtenir totes les files de la taula usuari
		usuari n;
		cout << "Insereix el teu sobrenom" << endl;
		cin >> n.sobrenom;
		cout << "Insereix el teu nou nom i el teu nou correu electronic" << endl;
		cin >> n.nom >> n.correu;
		string sq Usuari SET nom = '" + n.nom + "', correu_electronic = '" + n.correu + "' WHERE sobrenom='" + n.sobrenom + "'";
		stmt->executeUpdate(sql);
		cout << "L'Usuari " << n.sobrenom << " s'ha registrat correctament!" << endl;
		con->close();
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
		// si hi ha un error es tanca la connexió (si esta oberta)
		if (con != NULL) con->close();
	}
}

void procesarEsborraUsuari()
{
	sql::mysql::MySQL_Driver* driver = NULL;
	sql::Connection* con = NULL;
	sql::Statement* stmt = NULL;
	try {
		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep10", "iyohthe7wiiFie");
		con->setSchema("inep10");
		stmt = con->createStatement();
		// Sentència SQL per obtenir totes les files de la taula usuari
		usuari n;
		cout << "Insereix el teu sobrenom" << endl;
		cin >> n.sobrenom;
		string sql = "DELETE FROM Usuari WHERE sobrenom='" + n.sobrenom + "'";
		stmt->execute(sql);
		cout << "L'Usuari " << n.sobrenom << " s'ha esborrat correctament!" << endl;
		con->close();
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
		// si hi ha un error es tanca la connexió (si esta oberta)
		if (con != NULL) con->close();
	}
}

void gestioUsuari()
{
	cout << "1. Registre usuari" << endl;
	cout << "2. Consulta usuari" << endl;
	cout << "3. Modifica usuari" << endl;
	cout << "4. Esborra usuari" << endl;
	cout << "5. Tornar" << endl;
	int i;
	cin >> i;
	if (i == 1) {
		procesarRegistreUsuari();
	}
	else if (i == 2) {
		procesarConsultaUsuari();
	}
	else if (i == 3) {
		procesarModificaUsuari();
	}
	else if (i == 4) {
		procesarEsborraUsuari();
	}
}

void procesarGestioPelicules()
{
	cout << "S'ha processat l'opció Gestió  pel·lícules" << endl;
}

void procesarGestioSeries()
{
	cout << "S'ha processat l'opció Gestió series" << endl;
}

void gestioContinguts()
{
	cout << "1. Gestió pel·lícules" << endl;
	cout << "2. Gestió sèries" << endl;
	cout << "3. Tornar" << endl;
	int i;
	cin >> i;
	if (i == 1) {
		procesarGestioPelicules();
	}
	else if (i == 2) {
		procesarGestioSeries();
	}
}

void procesarConsultaQualificacioEdat()
{
	cout << "S'ha processat l'opció Consulta per qualificació d'edat" << endl;
}

void procesarUltimesNovetats()
{
	cout << "S'ha processat l'opció Ultimes novetats" << endl;
}

void procesarProximesEstrenes()
{
	cout << "S'ha processat l'opció Pròximes estrenes" << endl;
}

void consultes()
{
	cout << "1. Consulta per qualificació d'edat" << endl;
	cout << "2. Últimes novetats" << endl;
	cout << "3. Pròximes estrenes" << endl;
	cout << "4. Tornar" << endl;
	int i;
	cin >> i;
	if (i == 1) {
		procesarConsultaQualificacioEdat();
	}
	else if (i == 2) {
		procesarUltimesNovetats();
	}
	else if (i == 3) {
		procesarProximesEstrenes();
	}
}

void mostraMenuPrincipal()
{
	cout << "1. Gestió usuari" << endl;
	cout << "2. Gestió continguts" << endl;
	cout << "3. Consultes" << endl;
	cout << "4. Sortir" << endl;
}


int main()
{
	/*
		Biel Lacasa Díaz

		Adrià Querol Catalán
	*/

	mostraMenuPrincipal();
	int inp;
	cin >> inp;
	while (inp != 4) {
		if (inp == 1) {
			gestioUsuari();
		}
		else if (inp == 2) {
			gestioContinguts();
		}
		else if (inp == 3) {
			consultes();
		}
		mostraMenuPrincipal();
		cin >> inp;
	}
}
