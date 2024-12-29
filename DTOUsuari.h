#pragma once
#include <string>
using namespace std;

struct DTOUsuari {
	string nom;
	string sobrenom;
	string contrassenya;
	string correuElectronic;
	string dataNaixament;
	string subscripcio;
};

struct DTOPelicula {
	string titol;
	string dataEstrena;
	string qualificacio;
	string descripcio;
	int duracio;
	int visualitzacions;
};