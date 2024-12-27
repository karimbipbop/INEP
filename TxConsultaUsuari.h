#include "Transaccio.h"
#include "PassarelaUsuari.h"

class TxConsultaUsuari: public Transaccio {
private:
    Usuari usuari;

public:
    TxConsultaUsuari();
    void executar();
	Usuari obteResultat();
};