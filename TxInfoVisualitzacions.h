#pragma once
#include "Transaccio.h"

class TxInfoVisualitzacions : public Transaccio {
private:
	pair<int, int> resultat;

public:
	TxInfoVisualitzacions();
	void executar();
	pair<int, int> obteResultat();
};