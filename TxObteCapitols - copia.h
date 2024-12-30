#pragma once
#include "Transaccio.h"
#include "PassarelaContingut.h"
#include "PassarelaCapitol.h"

class TxObteCapitols : public Transaccio {
private:
	string titol_serie;
	int numeroTemporada;
	vector<DTOCapitol> res;
public:
	TxObteCapitols(string titol, int numT);
	void executar();
	vector<DTOCapitol> obteResultat();
};