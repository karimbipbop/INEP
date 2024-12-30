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
	catch (int exc) {
		//no existeix la pelicula.
		throw exc;
	}
	catch (sql::SQLException& e) {
		throw e;
	}
}

DTOContingut TxObteContingut::obteResultat() {
	return res;
}