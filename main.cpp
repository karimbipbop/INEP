#include "CapaDePresentacio.h"


//Menu Sessió no iniciada
void mostraMenuPrincipalN()
{
	cout << "*********************" << endl;
	cout << "   Menu Principal" << endl;
	cout << "*********************" << endl;
	cout << "1. Iniciar sessio" << endl;
	cout << "2. Registrar usuari" << endl;
	cout << "3. Consultes" << endl;
	cout << "4. Sortir" << endl;
	cout << "Escriu opcio: ";
}

//Menu Sessió iniciada
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

//Menu gestió usuari
void gestioUsuari()
{
	cout << "----------------------" << endl;
	cout << "    Gestio Usuari" << endl;
	cout << "----------------------" << endl;
	cout << "1. Consulta usuari" << endl;
	cout << "2. Modifica usuari" << endl;
	cout << "3. Esborra usuari" << endl;
	cout << "4. Tornar" << endl;
	cout << "Escriu opcio: ";

	int i;
	cin >> i;
	CapaDePresentacio& p = CapaDePresentacio::getInstance();
	switch (i) {
	default:
		//L'entrada no és vàlida.
		cin.clear(); //Esborra l'estat d'error.
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Esborra el buffer de cin fins a l'últim salt de línia.
		break;
	case 1:
		p.processarConsultaUsuari();
		break;
	case 2:
		p.processarModificaUsuari();
		break;
	case 3:
		try {
			p.processarEsborraUsuari();
			logg = false;
			break;
		}
		catch (int exc) {
			cout << "La contrassenya es incorrecta." << endl;
			break;
		}
	case 4:
		break;
	}
	if (i != 4 && logg) gestioUsuari(); //No torna, segueix a aquest submenú.
}

//Menu visualitzar
void visualitzar() {
	cout << "----------------------" << endl;
	cout << "    Visualitzar" << endl;
	cout << "----------------------" << endl;
	cout << "1. Visualitzar pel.licula" << endl;
	cout << "2. Visualitzar capitol" << endl;
	cout << "3. Consulta visualitzacions" << endl;
	cout << "4. Tornar" << endl;
	cout << "Escriu opcio: ";
	int i;
	cin >> i;
	CapaDePresentacio& p = CapaDePresentacio::getInstance();
	switch (i)
	{
	default:
		//L'entrada no és vàlida.
		cin.clear(); //Esborra l'estat d'error.
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Esborra el buffer de cin fins a l'últim salt de línia.
		break;
	case 1:
		p.processarVisualitzaPel();
		break;
	case 2:
		p.processarVisualitzaCap();
		break;
	case 3:
		cout << "CONSULTAR VISUALITZACIONS\n";
		break;
	case 4:
		break;
	}
	if (i != 4) visualitzar(); //No torna, segueix a aquest submenú.
}

//Menu consultes
void consultes()
{
	cout << "----------------------" << endl;
	cout << "    Consultes" << endl;
	cout << "----------------------" << endl;
	cout << "1. Properes estrenes" << endl;
	cout << "2. Ultimes novetats" << endl;
	cout << "3. Pel.licules mes vistes" << endl;
	cout << "4. Tornar" << endl;
	cout << "Escriu opcio: ";
	int i;
	cin >> i;
	CapaDePresentacio& p = CapaDePresentacio::getInstance();
	switch (i)
	{
	default:
		//L'entrada no és vàlida.
		cin.clear(); //Esborra l'estat d'error.
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Esborra el buffer de cin fins a l'últim salt de línia.
		break;
	case 1:
		p.processarProximesEstrenes();
		break;
	case 2:
		p.processarUltimesNovetats();
		break;
	case 3:
		p.processarConsultarPelicules();
		break;
	case 4:
		break;
	}
	if (i != 4) consultes(); //No torna, segueix a aquest submenú.
}

int main()
{
	CapaDePresentacio& p = p.getInstance();
	int inp;
	mostraMenuPrincipalN();
	while (run) {
		cin >> inp;
		if (logg) {
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
				try {
					p.processarTancaSessio();
					logg = false;
				}
				catch (int exc) {
					//Error al tancar la sessió
				}
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
				try {
					p.processarIniciSessio();
					logg = true;
				}
				catch (int exc) {
					//Error al iniciar la sessió
				}
				break;
			case 2:
				p.processarRegistreUsuari();
				break;
			case 3:
				consultes();
				break;
			case 4:
				run = false;
				break;
			}
		}
		if (run and !logg) mostraMenuPrincipalN();
		else if (run and logg) mostraMenuPrincipalS();
	}
}
