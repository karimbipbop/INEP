#include "TxObteContingut.h"

TxObteContingut::TxObteContingut(string titolC) {
	titol = titolC;
}

void TxObteContingut::executar() {
	try {
		PassarelaContingut pCon = cercCont.cercaContingutPerTitol(titol);
		res.titol = pCon.obteTitol();
		res.descripcio = pCon.obteDescripcio();
		res.qualificacio = pCon.obteQualificacio();
		res.tipus = pCon.obteTipus();
	}
	catch (sql::SQLException& e) {
		//no existeix la pelicula.
		throw;
	}
}

DTOContingut TxObteContingut::obteResultat() {
	return res;
}