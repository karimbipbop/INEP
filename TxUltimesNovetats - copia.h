#pragma once
#include "Transaccio.h"
#include "PassarelaPelicula.h"
#include "PassarelaCapitol.h"

class TxUltimesNovetats : public Transaccio {
private:
    string subscripcio;
    pair<vector<string>, vector<string>> resultat;

public:
    TxUltimesNovetats(string sub);
    void executar();
    pair<vector<string>, vector<string>> obteResultat();
};