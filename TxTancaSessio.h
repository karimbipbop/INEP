#pragma once
#include "Transaccio.h"
#include "PassarelaUsuari.h"

class TxTancaSessio : public Transaccio {
public:
    TxTancaSessio();
    void executar();
};