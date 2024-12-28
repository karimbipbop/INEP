#pragma once
#include <string>

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
	int duracio;
	int visualitzacions;
};