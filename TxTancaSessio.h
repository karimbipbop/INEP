#pragma once
#include "Transaccio.h"
#include "PassarelaUsuari.h"

class TxTancaSessio : public Transaccio {
private:
    DTOUsuari usuari;

public:
    TxTancaSessio();
    void executar();
};