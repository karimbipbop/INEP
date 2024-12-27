#include "Transaccio.h"
#include "PassarelaUsuari.h"

class TxTancaSessio : public Transaccio {
private:
    Usuari usuari;

public:
    TxTancaSessio();
    void executar();
};