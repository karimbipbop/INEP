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
	catch (sql::SQLException& e) {
		//no existeix la pelicula.
		throw;
	}
}

DTOPelicula TxObteInfoPel::obteResultat() {
	return res;
}