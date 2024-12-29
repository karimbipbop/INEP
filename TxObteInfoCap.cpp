#include "TxObteInfoCap.h"

TxObteInfoCap::TxObteInfoCap(string titolSerie, int numeroT, int numeroC) {
	titol = titolSerie;
	numT = numeroT;
	numC = numeroC;
}

void TxObteInfoCap::executar() {
	try {
		PassarelaCapitol cap = cercCap.cercaCapitol(titol, numT, numC);
		PassarelaContingut pCon = cercCont.cercaContingutPerTitol(titol);
		res.titolSerie = cap.obteTitolSerie();
		res.qualificacio = pCon.obteQualificacio();
		res.numeroTemporada = cap.obteNumeroTemporada();
		res.numero = cap.obteNumero();
	}
	catch (sql::SQLException& e) {
		//no existeix la pelicula.
		throw;
	}
}

DTOCapitol TxObteInfoCap::obteResultat() {
	return res;
}