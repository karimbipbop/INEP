#pragma once
#include "Transaccio.h"
#include "PassarelaPelicula.h"
#include "PassarelaCapitol.h"

class TxProximesEstrenes : public Transaccio {
private:
    string subscripcio;
    vector<string> resultat;

public:
    TxProximesEstrenes(string sub);
    void executar();
    vector<string> obteResultat();
};