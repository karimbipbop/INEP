#include "TxObteInfoPel.h"

TxObteInfoPel::TxObteInfoPel(string titolP) {
	titol = titolP;
}

void TxObteInfoPel::executar() {
	try {
		pP = cercPel.cercaPelicula(titol);
		PassarelaContingut pCon = cercCont.cercaContingutPerTitol(titol);
		res.titol = pP.obteTitol();
		res.dataEstrena = pP.obteDataEstrena();
		res.duracio = pP.obteDuracio();
		res.descripcio = pCon.obteDescripcio();
		res.qualificacio = pCon.obteQualificacio();
	}
	catch (int exc) {
		//no existeix la pelicula.
		throw exc;
	}
	catch (sql::SQLException& e) {
		throw e;
	}
}

DTOPelicula TxObteInfoPel::obteResultat() {
	return res;
}