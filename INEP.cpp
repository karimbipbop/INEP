// INEP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

struct usuari {
	string nomComplet;
	string sobrenom;
};

void procesarRegistreUsuari()
{
	usuari act;
	cout << "Ingresa el teu nom complet i sobrenom" << endl;
	cin >> act.nomComplet >> act.sobrenom;
	if (act.nomComplet == "" or act.sobrenom == "") cout << "Error al registrar usuari" << endl;
	else cout << "El registre de l'usuari " << act.nomComplet << " (" << act.sobrenom << ") s'ha processat correctament" << endl;
}

void procesarConsultaUsuari()
{
	usuari act;
	cout << "El teu usuari es " << act.nomComplet << " (" << act.sobrenom << ")" << endl;
}

void procesarModificaUsuari()
{
	usuari act;
	cout << "Escriu un nou sobrenom:" << endl;
	cin >> act.sobrenom;
	if (act.sobrenom != "") cout << "La modificació s'ha processat correctament";
	else cout << "Sobrenom no vàlid" << endl;
}

void procesarEsborraUsuari()
{
	cout << "Usuari esborrat" << endl;
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
