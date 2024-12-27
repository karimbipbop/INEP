#pragma once
#include "Transaccio.h"
#include "PassarelaUsuari.h"

class TxRegistraUsuari : public Transaccio {
private:
    Usuari usuari;

public:
    TxRegistraUsuari();
    TxRegistraUsuari(Usuari u);
    void executar();
};