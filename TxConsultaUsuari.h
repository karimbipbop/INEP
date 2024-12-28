#include "Transaccio.h"
#include "PassarelaUsuari.h"

class TxConsultaUsuari: public Transaccio {
private:
    PassarelaUsuari usuari;
    DTOUsuari resultat;

public:
    TxConsultaUsuari();
    void executar();
	DTOUsuari obteResultat();
	PassarelaUsuari obteUsuari();
};