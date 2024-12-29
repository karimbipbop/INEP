#pragma once
#include "Transaccio.h"
#include "PassarelaTemporada.h"

class TxObteTemporades : public Transaccio {
private:
	vector<PassarelaTemporada> vPasTemp;
	string titol;
	vector<DTOTemporada> res;

public:
	TxObteTemporades(string titolP);
	void executar();
	vector<DTOTemporada> obteResultat();
};