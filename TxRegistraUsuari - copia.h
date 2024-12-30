#pragma once
#include "Transaccio.h"
#include "PassarelaUsuari.h"

class TxRegistraUsuari : public Transaccio {
private:
    DTOUsuari usuari;

public:
    TxRegistraUsuari();
    TxRegistraUsuari(DTOUsuari u);
    void executar();
};