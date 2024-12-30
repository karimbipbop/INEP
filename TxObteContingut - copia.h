#pragma once
#include "Transaccio.h"
#include "PassarelaContingut.h"

class TxObteContingut : public Transaccio {
private:
	string titol;
	DTOContingut res;
public:
	TxObteContingut(string titolC);
	void executar();
	DTOContingut obteResultat();
};