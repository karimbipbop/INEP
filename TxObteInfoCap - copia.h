#pragma once
#include "Transaccio.h"

class TxObteInfoCap : public Transaccio {
private:
	PassarelaCapitol pC;
	DTOCapitol res;
	string titol;
	int numT;
	int numC;

public:
	TxObteInfoCap(string titolSerie, int numT, int numC);
	void executar();
	DTOCapitol obteResultat();
};