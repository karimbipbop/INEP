#include "ConnexioBD.h"

using namespace std;

struct usuari {
	string sobrenom;
	string nom;
	string correu;
};

void procesarRegistreUsuari()
{
	try {
		ConnexioBD& c = ConnexioBD::getInstance();
		// Sentència SQL per obtenir totes les files de la taula usuari
		usuari n;
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

void procesarConsultaUsuari()
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

void procesarModificaUsuari()
{
	try {
		ConnexioBD& c = ConnexioBD::getInstance();
		// Sentència SQL per obtenir totes les files de la taula usuari
		usuari n;
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

void procesarEsborraUsuari()
{
	try {
		ConnexioBD& c = ConnexioBD::getInstance();
		// Sentència SQL per obtenir totes les files de la taula usuari
		usuari n;
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

void gestioUsuari()
{
	cout << "1. Registre usuari" << endl;
	cout << "2. Consulta usuari" << endl;
	cout << "3. Modifica usuari" << endl;
	cout << "4. Esborra usuari" << endl;
	cout << "5. Tornar" << endl;
	int i;
	cin >> i;
	if (cin.fail()) {
		//L'entrada no és un número
		cin.clear(); //Esborra l'estat d'error.
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Esborra el buffer de cin fins a l'últim salt de línia.
	}
	else if (i == 1) {
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
	cout << "S'ha processat l'opcio Gestio pel.licules" << endl;
}

void procesarGestioSeries()
{
	cout << "S'ha processat l'opcio Gestio series" << endl;
}

void gestioContinguts()
{
	cout << "1. Gestio pel.licules" << endl;
	cout << "2. Gestio series" << endl;
	cout << "3. Tornar" << endl;
	int i;
	cin >> i;
	if (cin.fail()) {
		//L'entrada no és un número
		cin.clear(); //Esborra l'estat d'error.
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Esborra el buffer de cin fins a l'últim salt de línia.
	}
	else if (i == 1) {
		procesarGestioPelicules();
	}
	else if (i == 2) {
		procesarGestioSeries();
	}
}

void procesarConsultaQualificacioEdat()
{
	cout << "S'ha processat l'opcio Consulta per qualificacio d'edat" << endl;
}

void procesarUltimesNovetats()
{
	cout << "S'ha processat l'opcio Ultimes novetats" << endl;
}

void procesarProximesEstrenes()
{
	cout << "S'ha processat l'opcio Proximes estrenes" << endl;
}

void consultes()
{
	cout << "1. Consulta per qualificacio d'edat" << endl;
	cout << "2. Ultimes novetats" << endl;
	cout << "3. Proximes estrenes" << endl;
	cout << "4. Tornar" << endl;
	int i;
	cin >> i;
	if (cin.fail()) {
		//L'entrada no és un número
		cin.clear(); //Esborra l'estat d'error.
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Esborra el buffer de cin fins a l'últim salt de línia.
	}
	else if (i == 1) {
		procesarConsultaQualificacioEdat();
	}
	else if (i == 2) {
		procesarUltimesNovetats();
	}
	else if (i == 3) {
		procesarProximesEstrenes();
	}
}

void mostraMenuPrincipalNL()
{
	cout << "*********************" << endl;
	cout << "   Menu Principal" << endl;
	cout << "*********************" << endl;
	cout << "1. Gestio usuaris" << endl;
	cout << "2. Visualitzar" << endl;
	cout << "3. Consultes" << endl;
	cout << "4. Tancar sessio" << endl;
	cout << "5. Sortir" << endl;
}

void mostraMenuPrincipalL()
{
	cout << "*********************" << endl;
	cout << "   Menu Principal" << endl;
	cout << "*********************" << endl;
	cout << "1. Iniciar sessio" << endl;
	cout << "2. Registrar Usuaris" << endl;
	cout << "3. Consultes" << endl;
	cout << "4. Sortir" << endl;
}

int main()
{

	mostraMenuPrincipalL();
	int inp;
	cin >> inp;
	while (inp != 4) {
		if (cin.fail()) {
			//L'entrada no és un número
			cin.clear(); //Esborra l'estat d'error.
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Esborra el buffer de cin fins a l'últim salt de línia.
		}

		else if (inp == 1) {
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