#pragma once
#include "Transaccio.h"

class TxVisualitzarCap : public Transaccio {
private:
	PassarelaVisualitzaCap pVC;
	PassarelaPelicula pC;
	string sU, titolSerie;
	int numeroT, numeroC;
public:
	TxVisualitzarCap(string sobrenom, string titolS, int numT, int numC);
	void executar();
	PassarelaVisualitzaCap obteVisualitzacio();
};