#pragma once
#include "Transaccio.h"

class TxEsCapitolVisualitzat : public Transaccio {
private:
	string sobrenom;
	string titol_serie;
	int num_temporada;
	int num_capitol;
	DTOCapitol res;

public:
	TxEsCapitolVisualitzat(string sobrenom, string titol_serie, int num_temporada, int num_capitol);
	void executar();
	DTOCapitol obteResultat();
};