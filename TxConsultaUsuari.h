#include "Transaccio.h"
#include "PassarelaUsuari.h"

class TxConsultaUsuari: public Transaccio {
private:
    PassarelaUsuari usuari;
    Usuari resultat;

public:
    TxConsultaUsuari();
    void executar();
	Usuari obteResultat();
};