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
	else if (i == 5) {
		
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

}

//hola canvi canvio
int main()
{
	/*
		Biel Lacasa Díaz
	*/
	cout << "1. Gestió usuari" << endl;
	cout << "2. Gestió continguts" << endl;
	cout << "3. Consultes" << endl;
	cout << "4. Sortir" << endl;
	int inp;
	cin >> inp;
	if (inp == 1) {
		gestioUsuari();
	}
	else if (inp == 2) {
		gestioContinguts();
	}
	else if (inp == 3) {
		consultes();
	}
	else if (inp == 4) {

	}
}