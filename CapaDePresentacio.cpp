#include "CapaDePresentacio.h"

CapaDePresentacio::CapaDePresentacio() {

}

CapaDePresentacio& CapaDePresentacio::getInstance() {
	static CapaDePresentacio p;
	return p;
}

void CapaDePresentacio::processarRegistreUsuari()
{
	/*
	cout << "** Registrar usuari **" << endl;
	string nU, sU, cU, correuU, dU, subU;
	cout << "Nom complert: ";
	cin >> nU;
	cout << endl << "Sobrenom: ";
	cin >> sU;
	cout << endl << "Contrassenya: ";
	cin >> cU;
	cout << endl << "Correu electronic: ";
	cin >> correuU;
	cout << endl << "Data naixement (DD/MM/AAAA): ";
	cin >> dU;
	cout << endl << "Modalitats de subscripció disponibles" << endl;
	cout << " > 1. Completa" << endl;
	cout << " > 2. Cinèfil" << endl;
	cout << " > 3. Infantil" << endl;
	cout << "Escull modalitat: ";
	int n;
	cin >> n;
	if (n == 1) {
		subU = "Completa";
	}
	else if (n == 2) {
		subU = "Cinèfil";
	}
	else if (n == 3) {
		subU = "Infantil";
	}
	else {
		cout << "Error: Modalitat errònia";
		// S'hauria d'acabar el cas d'us
	}
	*/

	cout << "*********************" << endl;
	cout << "1. Iniciar sessio" << endl;
	cout << "2. Registrar Usuaris" << endl;
	cout << "3. Consultes" << endl;
	cout << "4. Sortir" << endl;
	cout << "Escriu opcio: ";
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
			cin >> n.nom >> n.correuElectronic;
			string sql = "INSERT INTO Usuari (sobrenom, nom, correu_electronic) VALUES ('" + n.sobrenom + "', '" + n.nom + "', '" + n.correuElectronic + "')";
			c.execucio(sql);
			cout << "L'Usuari " << n.sobrenom << " s'ha registrat correctament!" << endl;
		}
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}

void CapaDePresentacio::processarIniciSessio() {
	cout << "** Inici sessio **\n";
	string sU, cU;
	cout << "Sobrenom: ";
	cin >> sU;
	cout << "Contrasenya: ";
	cin >> cU;
	try {
		TxIniciSessio tini(sU, cU);
		tini.executar();
		cout << "Sessio iniciada correctament!\n";
	}
	catch(int exc) {
		cout << "Alguna credencial no es correcta.\n";
		throw(ErrorContrasenya);
	}
}

void CapaDePresentacio::processarTancaSessio() {
	cout << "** Tancar sessio **\n";
	cout << "Vols tancar la sessio (S/N): ";
	char op;
	cin >> op;
	if (op == 'S' || op == 's') {
		// PetitFlix.tancaSessio();
		cout << "Sessio tancada correctament!\n";
	}
	else {
		throw(NoTancaSessio);
	}
}

void CapaDePresentacio::processarConsultaUsuari() {
	TxConsultaUsuari tcon;
	tcon.executar();
	Usuari u = tcon.obteResultat();

	//TxVisualitzaUsuari tvis(u);
	//tvis.executar();
	//InfoVisualitzacio infovis = tvis.obteResultat();
	//COUT INFORMACIO VISUALITZACIO
}

/************************************************/

//void CapaDePresentacio::processarConsultaUsuari()
//{
//	try {
//		ConnexioBD& c = ConnexioBD::getInstance();
//		// Sentència SQL per obtenir totes les files de la taula usuari
//		string sobrenom;
//		cout << "Entra el teu sobrenom" << endl;
//		cin >> sobrenom;
//		string sql = "SELECT * FROM Usuari WHERE sobrenom='" + sobrenom + "'";
//		sql::ResultSet* res = c.consulta(sql);
//		if (res->next()) {
//			cout << "Sobrenom: " << res->getString("sobrenom") << endl;
//			cout << "Nom: " << res->getString("nom") << endl;
//			cout << "Correu: " << res->getString("correu_electronic") << endl;
//		}
//		else {
//			cout << "No s'ha trobat l'usuari '" << sobrenom << "' a la base de dades.\n";
//		}
//	}
//	catch (sql::SQLException& e) {
//		std::cerr << "SQL Error: " << e.what() << std::endl;
//	}
//}
//
//void CapaDePresentacio::processarModificaUsuari()
//{
//	try {
//		ConnexioBD& c = ConnexioBD::getInstance();
//		// Sentència SQL per obtenir totes les files de la taula usuari
//		Usuari n;
//		cout << "Insereix el teu sobrenom" << endl;
//		cin >> n.sobrenom;
//		string sql = "SELECT COUNT(*) AS count FROM Usuari WHERE sobrenom = '" + n.sobrenom + "'";
//		sql::ResultSet* res = c.consulta(sql);
//		res->next();
//		if (res->getInt("count") == 0) {
//			cout << "ERROR: No existeix l'usuari '" << n.sobrenom << "' a la base de dades.\n";
//		}
//		else {
//			cout << "Insereix el teu nou nom i el teu nou correu electronic" << endl;
//			cin >> n.nom >> n.correuElectronic;
//			sql = "UPDATE Usuari SET nom = '" + n.nom + "', correu_electronic = '" + n.correuElectronic + "' WHERE sobrenom = '" + n.sobrenom + "'";
//			c.execucio(sql);
//			cout << "L'Usuari " << n.sobrenom << " s'ha modificat correctament!" << endl;
//		}
//	}
//	catch (sql::SQLException& e) {
//		std::cerr << "SQL Error: " << e.what() << std::endl;
//	}
//}
//
//void CapaDePresentacio::processarEsborraUsuari()
//{
//	try {
//		ConnexioBD& c = ConnexioBD::getInstance();
//		// Sentència SQL per obtenir totes les files de la taula usuari
//		Usuari n;
//		cout << "Insereix el teu sobrenom" << endl;
//		cin >> n.sobrenom;
//		string sql = "SELECT COUNT(*) AS count FROM Usuari WHERE sobrenom = '" + n.sobrenom + "'";
//		sql::ResultSet* res = c.consulta(sql);
//		res->next();
//		if (res->getInt("count") == 0) {
//			cout << "ERROR: No existeix l'usuari '" << n.sobrenom << "' a la base de dades.\n";
//		}
//		else {
//			string sql = "DELETE FROM Usuari WHERE sobrenom='" + n.sobrenom + "'";
//			c.execucio(sql);
//			cout << "L'Usuari " << n.sobrenom << " s'ha esborrat correctament!" << endl;
//		}
//	}
//	catch (sql::SQLException& e) {
//		std::cerr << "SQL Error: " << e.what() << std::endl;
//	}
//}
//
//void CapaDePresentacio::processarGestioPelicules()
//{
//	cout << "S'ha processat l'opcio Gestio pel.licules" << endl;
//}
//
//void CapaDePresentacio::processarGestioSeries()
//{
//	cout << "S'ha processat l'opcio Gestio series" << endl;
//}
//
//void CapaDePresentacio::processarConsultaQualificacioEdat()
//{
//	cout << "S'ha processat l'opcio Consulta per qualificacio d'edat" << endl;
//}
//
//void CapaDePresentacio::processarUltimesNovetats()
//{
//	cout << "S'ha processat l'opcio Ultimes novetats" << endl;
//}
//
//void CapaDePresentacio::processarProximesEstrenes()
//{
//	cout << "S'ha processat l'opcio Proximes estrenes" << endl;
//}