#pragma once
#include "Transaccio.h"
#include "PassarelaUsuari.h"

class TxRegistraUsuari : public Transaccio {
private:
    Usuari usuari;

public:
    TxRegistraUsuari();
    TxRegistraUsuari(string nU, string sU, string cU, string ceU, string dnU, string subU);
    void executar();
};