#pragma once
#include "Transaccio.h"

class TxObteInfoPel : public Transaccio {
private:
	PassarelaPelicula pP;
	string titol;
	DTOPelicula res;
public:
	TxObteInfoPel(string titolP);
	void executar();
	DTOPelicula obteResultat();
};