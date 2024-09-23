// INEP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

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
		
	}
	else if (i == 2) {

	}
	else if (i == 3) {

	}
	else if (i == 4) {

	}
}

void gestioContinguts()
{
	cout << "1. Gestió pel·lícules" << endl;
	cout << "2. Gestió sèries" << endl;
	cout << "3. Tornar" << endl;
	int i;
	cin >> i;
	if (i == 1) {

	}
	else if (i == 2) {

	}
	else if (i == 3) {

	}
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

	}
	else if (i == 2) {

	}
	else if (i == 3) {
		
	}
	else if (i == 4) {

	}
}

void mostraMenuPrincipal()
{
	cout << "1. Gestió usuari" << endl;
	cout << "2. Gestió continguts" << endl;
	cout << "3. Consultes" << endl;
	cout << "4. Sortir" << endl;
}

//canvios otro canvio va y otro venga
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