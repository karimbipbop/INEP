#pragma once
#include "DTOUsuari.h"
#include "Transaccio.h"
#include <algorithm>

class TxConsultarPelicules : public Transaccio {
private:
    vector<string> resultat;

public:
    TxConsultarPelicules();
    void executar();
    vector<string> obteResultat();
};
