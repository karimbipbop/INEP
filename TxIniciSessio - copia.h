#pragma once
#include "Transaccio.h"
#include "CercadoraUsuari.h"
#include "PassarelaUsuari.h"

class TxIniciSessio : public Transaccio {
private:
	string sobrenom;
	string contrasenya;

public:
	TxIniciSessio(string sU, string cU);
	void executar();
};