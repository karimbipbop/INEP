#pragma once
#include "Transaccio.h"
#include "PassarelaContingut.h"
#include "PassarelaCapitol.h"

class TxObteCapitols : public Transaccio {
private:
	string titol_serie;
	vector<DTOCapitol> res;
public:
	TxObteCapitols(string titol);
	void executar();
	vector<DTOCapitol> obteResultat();
};