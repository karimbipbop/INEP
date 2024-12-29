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
			TxObteRelacionatsPel torp(nomP);
			torp.executar();
			vector<string> relacionats = torp.obteTitolsRel();
			for (unsigned int i = 0; i < relacionats.size(); ++i) {
				TxObteInfoPel tinfp(relacionats[i]);
				tinfp.executar();
				DTOPelicula aux = tinfp.obteResultat();
				formatDate(aux.dataEstrena);
				cout << "- " << aux.titol << "; " << aux.descripcio << "; " << aux.qualificacio;
				cout << "; " << aux.duracio << " min; " << aux.dataEstrena << "\n";
			}
		}
		catch (...) {
			cout << "ERROR\n";
			//todo if excepciones mensajes custom.
		}
	}
	else
		return;
	
}

void CapaDePresentacio::processarConsultarVisualitzacions() {
	cout << "** Consultar visualitzacions **\n\n";
	TxInfoVisualitzacions tinf;
	tinf.executar();
	vector<DTOPelicula> pels = tinf.obtePelVisu();
	if (pels.size() > 0) {
		cout << "** Pel.licules visualitzades **\n";
		cout << "*******************************\n";
		for (unsigned int i = 0; i < pels.size(); ++i) {
			TxObteInfoPel tinfp(pels[i].titol);
			tinfp.executar();
			DTOPelicula aux = tinfp.obteResultat();
			cout << pels[i].dataV << ": " << aux.titol << "; " << aux.descripcio << "; ";
			cout << aux.qualificacio << "; nombre de visualitzacions " << pels[i].visualitzacions << "\n";
		}
	}
	vector<DTOCapitol> caps = tinf.obteCapVisu();
	if (caps.size() > 0) {
		cout << "\n** Series visualitzades **\n";
		cout << "**************************\n";
		for (unsigned int i = 0; i < caps.size(); ++i) {
			TxObteInfoCap tinfc(caps[i].titolSerie, caps[i].numeroTemporada, caps[i].numero);
			tinfc.executar();
			DTOCapitol aux = tinfc.obteResultat();
			formatDate(caps[i].dataV);
			cout << caps[i].dataV << ": " << aux.titolSerie << "; " << aux.qualificacio << "; Temporada ";
			cout << aux.numeroTemporada << "; Capitol " << aux.numero << "; nombre de visualitzacions " << caps[i].visualitzacions << "\n";
		}
	}
	if (pels.size() == 0 && caps.size() == 0)
		cout << "No hi ha cap titol visualitzat\n";
}

void CapaDePresentacio::processarVisualitzaCap() {
	cout << "** Visualitzar Capitol **\n";
	string nomS;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Nom de la serie: ";
	getline(cin, nomS);
	PetitFlix& pf = PetitFlix::getInstance();
	string sobrenom = pf.obteUsuari().obteSobrenom();
	string modalitat = pf.obteUsuari().obteSubscripcio();
	try {
		TxObteContingut tcont(nomS);
		tcont.executar();
		DTOContingut contingut = tcont.obteResultat();
		if (modalitat == "Infantil" and (contingut.qualificacio == "16+" or contingut.qualificacio == "18+")) {
			cout << "La serie no es apropiada per l'edat de l'usuari" << endl;
			return;
		}
		TxObteTemporades tinft(nomS);
		tinft.executar();
		vector<DTOTemporada> temporades = tinft.obteResultat();
		cout << "La serie te " << temporades.size() << " temporades." << endl;
		cout << "Escull temporada: ";
		int temp;
		cin >> temp;
		TxObteCapitols tcaps(nomS);
		tcaps.executar();
		vector<DTOCapitol> capitols = tcaps.obteResultat();
		cout << "Llista capitols:\n";
		for (auto& cap : capitols) {
			bool esVisualitzat;
			cout << cap.numero << ". " << cap.titolCapitol << "; " << cap.dataEstrena << "; ";
		}
	}
	catch (sql::SQLException& e) {
		cout << e.what();
	}
}

void CapaDePresentacio::processarProximesEstrenes() {
	string modalitat;
	if (!logg) {
		cout << "Indica la modalitat de subscripcio: ";
		cin >> modalitat;
		if (modalitat != "Completa" and modalitat != "Cin�fil" and modalitat != "Cinefil" and modalitat != "Infantil") {
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
		cout << i+1 << ".- " << estrenes[i] << endl;
	}
}

void CapaDePresentacio::processarUltimesNovetats() {
	string modalitat;
	if (!logg) {
		cout << "Indica la modalitat de subscripcio: ";
		cin >> modalitat;
		if (modalitat != "Completa" and modalitat != "Cin�fil" and modalitat != "Cinefil" and modalitat != "Infantil") {
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

	cout << "** Novetats **\n";
	cout << "Modalitat: " << modalitat << "\n\n";
	TxUltimesNovetats u(modalitat);
	u.executar();
	pair<vector<string>, vector<string>> novetats = u.obteResultat();
	int n_pel = novetats.first.size();
	cout << "** Novetats pel.licules **\n";
	cout << "***************************\n";
	for (int i = 0; i < n_pel; ++i) {
		cout << i+1 << ".- " << novetats.first[i] << endl;
	}
	if (modalitat != "Cinefil" and modalitat != "Cin�fil") {
		// Si es cinefil no mostrem les series
		int n_cap = novetats.second.size();
		cout << "** Novetats series **\n";
		cout << "***************************\n";
		for (int i = 0; i < n_cap; ++i) {
			cout << i + 1 << ".- " << novetats.second[i] << endl;
		}
	}
	
}

void CapaDePresentacio::processarConsultarPelicules() {
	

	cout << "** Pel.licules mes visualitzades **\n\n";
	for (int i = 1; i < 6; ++i) {
		cout << i << ".- " << "hola\n";
	}
}