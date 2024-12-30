#pragma once
#include "Transaccio.h"

class TxObteRelacionatsPel : public Transaccio {
private:
	vector<string> titolsRel;
	string titol;
public:
	TxObteRelacionatsPel(string titolC);
	void executar();
	vector<string> obteTitolsRel();
};