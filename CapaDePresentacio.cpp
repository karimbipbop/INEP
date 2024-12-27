#include "CapaDePresentacio.h"


// Modifica la data que se li passa per canviar de DD/MM/YYYY a YYYY-MM-DD
bool formatDate(std::string& inputDate) {
	std::vector<std::string> parts;
	std::string part;

	// Parse the input string and split it into parts
	for (char ch : inputDate) {
		if (ch == '/' || ch == '-') {
			parts.push_back(part);
			part.clear();
		}
		else if (ch == ' ')
			break;
		else {
			part += ch;
		}
	}
	parts.push_back(part); // Add the last part

	// Validate that we have exactly three parts
	if (parts.size() != 3) {
		return false;
	}

	// Modify the input string to the formatted YYYY-MM-DD
	inputDate = parts[2] + "/" + parts[1] + "/" + parts[0];
	return true;
}

CapaDePresentacio::CapaDePresentacio() {

}

CapaDePresentacio& CapaDePresentacio::getInstance() {
	static CapaDePresentacio p;
	return p;
}

void CapaDePresentacio::processarRegistreUsuari()
{
	cout << "** Registrar usuari **" << endl;
	Usuari u;
	cout << "Nom complert: ";
	cin >> u.nom;
	cout << "Sobrenom: ";
	cin >> u.sobrenom;
	cout << "Contrassenya: ";
	cin >> u.contrassenya;
	cout << "Correu electronic: ";
	cin >> u.correuElectronic;
	cout << "Data naixement (DD/MM/AAAA): ";
	cin >> u.dataNaixament;
	if (!formatDate(u.dataNaixament)) {
		cout << "Error: data erronia\n";
		return;
	}
	cout << "Modalitats de subscripcio disponibles" << endl;
	cout << " > 1. Completa" << endl;
	cout << " > 2. Cinefil" << endl;
	cout << " > 3. Infantil" << endl;
	cout << "Escull modalitat: ";
	int n;
	cin >> n;
	if (n == 1) {
		u.subscripcio = "Completa";
	}
	else if (n == 2) {
		u.subscripcio = "Cinefil";
	}
	else if (n == 3) {
		u.subscripcio = "Infantil";
	}
	else {
		cout << "Error: Modalitat erronia" << endl;
		return;
	}
	try {
		TxRegistraUsuari treg(u);
		treg.executar();
		cout << "Nou usuari registrat correctament!" << endl;
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
		return;
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
		TxTancaSessio ttanc;
		ttanc.executar();
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
	formatDate(u.dataNaixament);
	TxInfoVisualitzacions tinfo;
	tinfo.executar();
	pair<int, int> nbVis = tinfo.obteResultat();
	cout << "** Consulta usuari **\n";
	cout << "Nom complet: " << u.nom << "\n";
	cout << "Sobrenom: " << u.sobrenom << "\n";
	cout << "Correu electronic: " << u.correuElectronic << "\n";
	cout << "Data naixement (DD/MM/AAAA): " << u.dataNaixament << "\n";
	cout << "Modalitat subscripcio: " << u.subscripcio << "\n\n";
	cout << nbVis.first << " pel.licules visualitzades\n";
	cout << nbVis.second << " capitols visualitzats\n";
}

void CapaDePresentacio::processarEsborraUsuari() {
	cout << "** Esborrar usuari **" << endl;
	cout << "Per confirmar l'esborrat, s'ha d'entrar la contrassenya" << endl;
	cout << "Contrassenya: ";
	string c;
	cin >> c;
	try {
		TxEsborraUsuari tesb(c);
		tesb.executar();
		cout << "Usuari esborrat correctament" << endl;
		TxTancaSessio ttanc;
		ttanc.executar();
	}
	catch (int exc) {
		cout << "La contrassenya es incorrecta." << endl;
		throw(ErrorContrasenya);
	}
}

/************************************************/
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