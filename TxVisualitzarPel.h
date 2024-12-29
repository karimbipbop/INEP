#pragma once
#include "Transaccio.h"

class TxVisualitzarPel : public Transaccio {
private:
	PassarelaVisualitzaPel pVP;
	PassarelaPelicula pP;
	string sU, titolP, sSubscripcio;
public:
	TxVisualitzarPel(string sobrenom, string titol, string modalitat);
	void executar();
	PassarelaVisualitzaPel obteVisualitzacio();
};