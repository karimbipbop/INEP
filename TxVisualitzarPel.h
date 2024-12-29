#pragma once
#include "Transaccio.h"

class TxVisualitzarPel : public Transaccio {
private:
	PassarelaVisualitzaPel pVP;
	string sU, titolP;
public:
	TxVisualitzarPel(string sobrenom, string titol);
	void executar();
	PassarelaVisualitzaPel obteResultat();
};