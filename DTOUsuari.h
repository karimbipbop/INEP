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

struct DTOTemporada {
	string titol_serie;
	int numero;
};

struct DTOContingut {
	string titol;
	string descripcio;
	string qualificacio;
	string tipus;
};