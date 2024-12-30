#pragma once
#include "Transaccio.h"

class TxInfoVisualitzacions : public Transaccio {
private:
	pair<int, int> resultat;
	vector<DTOPelicula> visP;
	vector<DTOCapitol> visC;

public:
	TxInfoVisualitzacions();
	void executar();
	pair<int, int> obteResultat();
	vector<DTOPelicula> obtePelVisu();
	vector<DTOCapitol> obteCapVisu();
};