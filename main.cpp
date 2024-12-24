#include "CapaDePresentacio.h"
//16.11
void gestioUsuari()
{
	cout << "----------------------" << endl;
	cout << "    Gestio Usuari" << endl;
	cout << "----------------------" << endl;
	cout << "1. Consulta usuari" << endl;
	cout << "3. Modifica usuari" << endl;
	cout << "3. Modifica constrasenya" << endl;
	cout << "4. Esborra usuari" << endl;
	cout << "5. Tornar" << endl;
	int i;
	cin >> i;
	CapaDePresentacio& p = CapaDePresentacio::getInstance();
	if (cin.fail()) {
		//L'entrada no és un número
		cin.clear(); //Esborra l'estat d'error.
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Esborra el buffer de cin fins a l'últim salt de línia.
	}
	else if (i == 1) {
		p.processarConsultaUsuari();
	}
	else if (i == 2) {
		p.processarModificaUsuari();
	}
	else if (i == 3) {
		//p.processarModificaContr();
	}
	else if (i == 4) {
		p.processarEsborraUsuari();
	}
}

void visualitzar() {
	cout << "----------------------" << endl;
	cout << "    Visualitzar" << endl;
	cout << "----------------------" << endl;
	cout << "1. Visualitzar continguts" << endl;
	cout << "2. Visualitzar llistes" << endl;
	cout << "3. Tornar" << endl;
	int i;
	cin >> i;
	CapaDePresentacio& p = CapaDePresentacio::getInstance();
	if (cin.fail()) {
		//L'entrada no és un número
		cin.clear(); //Esborra l'estat d'error.
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Esborra el buffer de cin fins a l'últim salt de línia.
	}
	else if (i == 1) {
		//p.gestioContinguts();
	}
	else if (i == 2) {
		//p.processarVisualitzarLlistes();
	}


}

void tancarSessio() {
	
}

void iniciarSessio() {

}

void registrarUsuari() {

}

void gestioContinguts()
{
	cout << "----------------------" << endl;
	cout << "    Gestio Usuari" << endl;
	cout << "----------------------" << endl;
	cout << "1. Gestio pel.licules" << endl;
	cout << "2. Gestio series" << endl;
	cout << "3. Tornar" << endl;
	int i;
	cin >> i;
	CapaDePresentacio& p = CapaDePresentacio::getInstance();
	if (cin.fail()) {
		//L'entrada no és un número
		cin.clear(); //Esborra l'estat d'error.
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Esborra el buffer de cin fins a l'últim salt de línia.
	}
	else if (i == 1) {
		p.processarGestioPelicules();
	}
	else if (i == 2) {
		p.processarGestioSeries();
	}
}

void consultes()
{
	cout << "1. Consulta per qualificacio d'edat" << endl;
	cout << "2. Ultimes novetats" << endl;
	cout << "3. Proximes estrenes" << endl;
	cout << "4. Tornar" << endl;
	int i;
	cin >> i;
	CapaDePresentacio& p = CapaDePresentacio::getInstance();
	if (cin.fail()) {
		//L'entrada no és un número
		cin.clear(); //Esborra l'estat d'error.
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Esborra el buffer de cin fins a l'últim salt de línia.
	}
	else if (i == 1) {
		p.processarConsultaQualificacioEdat();
	}
	else if (i == 2) {
		p.processarUltimesNovetats();
	}
	else if (i == 3) {
		p.processarProximesEstrenes();
	}
}

// Menu Sessió iniciada
void mostraMenuPrincipalS()
{
	cout << "*********************" << endl;
	cout << "   Menu Principal" << endl;
	cout << "*********************" << endl;
	cout << "1. Gestio usuaris" << endl;
	cout << "2. Visualitzar" << endl;
	cout << "3. Consultes" << endl;
	cout << "4. Tancar sessio" << endl;
	cout << "5. Sortir" << endl;
	cout << "Escriu opcio: ";
}

// Menu Sessió no iniciada
void mostraMenuPrincipalN()
{
	cout << "*********************" << endl;
	cout << "   Menu Principal" << endl;
	cout << "*********************" << endl;
	cout << "1. Iniciar sessio" << endl;
	cout << "2. Registrar Usuaris" << endl;
	cout << "3. Consultes" << endl;
	cout << "4. Sortir" << endl;
	cout << "Escriu opcio: ";
}

int main()
{
	bool run = true, log = false;
	int inp;
	mostraMenuPrincipalN();
	while (run and cin >> inp) {
		if (log) {
			//sessió iniciada
			switch (inp)
			{
			default:
				//L'entrada no és una opció vàlida.
				cin.clear(); //Esborra l'estat d'error.
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Esborra el buffer de cin fins a l'últim salt de línia.
				break;
			case 1:
				gestioUsuari();
				break;
			case 2:
				visualitzar();
				break;
			case 3:
				consultes();
				break;
			case 4:
				tancarSessio();
				log = false;
				break;
			case 5:
				run = false;
				break;
			}
		}
		else {
			//sessió no iniciada
			switch (inp)
			{
			default:
				//L'entrada no és una opció vàlida.
				cin.clear(); //Esborra l'estat d'error.
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Esborra el buffer de cin fins a l'últim salt de línia.
				break;
			case 1:
				iniciarSessio();
				log = true;
				break;
			case 2:
				registrarUsuari();
				break;
			case 3:
				consultes();
				break;
			case 4:
				run = false;
				break;
			}
		}
		if (run and !log) mostraMenuPrincipalN();
		else if (run and log) mostraMenuPrincipalS();
	}
}
