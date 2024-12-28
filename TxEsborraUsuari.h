#pragma once
#include "Transaccio.h"

class TxEsborraUsuari : public Transaccio {
private:
    string contrassenya;

public:
    TxEsborraUsuari(string c);
    void executar();
};