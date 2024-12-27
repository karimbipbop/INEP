#include "Transaccio.h"
#include "PassarelaUsuari.h"

class TxTancaUsuari : public Transaccio {
private:
    Usuari usuari;

public:
    TxTancaUsuari();
    void executar();
};