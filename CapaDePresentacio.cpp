#include "CapaDePresentacio.h"

bool run = true;
bool logg = false;


CapaDePresentacio::CapaDePresentacio() {

}

CapaDePresentacio& CapaDePresentacio::getInstance() {
	static CapaDePresentacio p;
	return p;
}

void CapaDePresentacio::processarRegistreUsuari()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "** Registrar usuari **" << endl;
	DTOUsuari u;
	cout << "Nom complert: ";
	getline(cin, u.nom);
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
	DTOUsuari u = tcon.obteResultat();
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

void CapaDePresentacio::processarModificaUsuari() {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	CtrlModificaUsuari cmu;
	DTOUsuari u = cmu.consultaUsuari();
	cout << "** Modificar usuari **" << endl;
	cout << "Nom complet: " << u.nom << "\n";
	cout << "Sobrenom: " << u.sobrenom << "\n";
	cout << "Correu electronic: " << u.correuElectronic << "\n";
	formatDate(u.dataNaixament);
	cout << "Data naixement (DD/MM/AAAA): " << u.dataNaixament << "\n";
	cout << "Modalitat subscripcio: " << u.subscripcio << "\n";

	cout << "Omplir la informacio  que es vol modificar ...\n";

	cout << "Nom complet: ";
	getline(cin, u.nom);
	cout << "Contrassenya: ";
	getline(cin, u.contrassenya);
	cout << "Correu electronic: ";
	getline(cin, u.correuElectronic);
	cout << "Data naixement (DD/MM/AAAA): ";
	getline(cin, u.dataNaixament);
	formatDate(u.dataNaixament);
	cout << "Modalitats de subscripcio: ";
	getline(cin, u.subscripcio);
	if (u.nom.empty() && u.contrassenya.empty() && u.correuElectronic.empty() && u.dataNaixament.empty() && u.subscripcio.empty()) {
		cout << "No s'ha entrat cap dada a modificar\n";
		return;
	}
	try {
		cmu.modificaUsuari(u.nom, u.contrassenya, u.correuElectronic, u.dataNaixament, u.subscripcio);
		u = cmu.consultaUsuari();
		cout << "** Dades usuari modificades **\n";
		cout << "Nom complet: " << u.nom << "\n";
		cout << "Sobrenom: " << u.sobrenom << "\n";
		cout << "Correu electronic: " << u.correuElectronic << "\n";
		formatDate(u.dataNaixament);
		cout << "Data naixement (DD/MM/AAAA): " << u.dataNaixament << "\n";
		cout << "Modalitat subscripcio: " << u.subscripcio << "\n";
	}
	catch (sql::SQLException& e) {
		throw(e);
	}
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
		throw(ErrorContrasenya);
	}
}

void CapaDePresentacio::processarVisualitzaPel() {
	cout << "** Visualitzar Pel.licula **\n";
	string nomP;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Titol: ";
	getline(cin, nomP);
	PetitFlix& pf = PetitFlix::getInstance();
	string sobrenom = pf.obteUsuari().obteSobrenom();
	string modalitat = pf.obteUsuari().obteSubscripcio();
	//transaccio mostra dades pelicula...

	
	try {
		TxObteInfoPel tinfp(nomP);
		tinfp.executar();
		DTOPelicula pel = tinfp.obteResultat();
		cout << "Informacio pel.licula... \n";
		cout << "Titol: " << pel.titol << "\n";
		cout << "Descripcio: " << pel.descripcio << "\n";
		cout << "Qualificacio: " << pel.qualificacio << "\n";
		formatDate(pel.dataEstrena);
		cout << "Data estrena: " << pel.dataEstrena << "\n";
		cout << "Duracio: " << pel.duracio << "\n";
	}
	catch (sql::SQLException& e) {
		//No existeix la pelicula
		cout << e.what();
	}

	cout << "Vols continuar amb la visualitzacio (S/N): ";
	char opt;
	cin >> opt;

	if (opt == 's' || opt == 'S') {
		try {
			TxVisualitzarPel tvisp(sobrenom, nomP, modalitat);
			tvisp.executar();
			string avui = today();
			formatDate(avui);
			cout << "Visualitzacio registrada: " << avui << "\n";
			cout << "Titols relacionats:\n";

		}
		catch (...) {
			cout << "ERROR\n";
			//todo if excepciones mensajes custom.
		}
	}
	else
		return;
	
}

void CapaDePresentacio::processarProximesEstrenes() {
	string modalitat;
	if (!logg) {
		cout << "Indica la modalitat de subscripcio: ";
		cin >> modalitat;
		if (modalitat != "Completa" and modalitat != "Cinèfil" and modalitat != "Cinefil" and modalitat != "Infantil") {
			cout << "La modalitat es incorrecta" << endl;
			return;
		}
	}
	else {
		TxConsultaUsuari tcon;
		tcon.executar();
		DTOUsuari u = tcon.obteResultat();
		modalitat = u.subscripcio;
	}

	cout << "** Properes estrenes **\n";
	cout << "Modalitat: " << modalitat << "\n\n";

	TxProximesEstrenes p(modalitat);
	p.executar();
	vector<string> estrenes = p.obteResultat();
	int n = estrenes.size();
	for (int i = 0; i < n; ++i) {
		cout << i << ".- " << estrenes[i] << endl;
	}
}

void CapaDePresentacio::processarConsultarPelicules() {
	

	cout << "** Pel.licules mes visualitzades **\n\n";
	for (int i = 1; i < 6; ++i) {
		cout << i << ".- " << "hola\n";
	}
}