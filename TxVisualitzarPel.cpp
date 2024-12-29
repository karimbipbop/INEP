#include "TxVisualitzarPel.h"

TxVisualitzarPel::TxVisualitzarPel(string sobrenom, string titol, string modalitat) {
	sU = sobrenom;
	titolP = titol;
	sSubscripcio = modalitat;
}

void TxVisualitzarPel::executar() {
	try {
		//Existeix una visualitzacio d'aquest usuari per aquesta pel.licula, augmenta en 1 numVisualitzacions.
		PassarelaVisualitzaPel visP = cercVisP.cercaVisualitzaPel(sU, titolP);
		visP.augmentaNumVisualitzacions();
		visP.modifica();
	}
	catch (const sql::SQLException& e) {
		//No existeix una visualitzacio d'aquest usuari per aquesta pel.licula.
		try {
			PassarelaPelicula pel = cercPel.cercaPelicula(titolP);
			string data = today();
			if (pel.obteDataEstrena() > data)
				throw; //Pel.licula no estrenada.
			PassarelaContingut pCon = cercCont.cercaContingutPerTitol(titolP);
			string qual = pCon.obteQualificacio();
			if (sSubscripcio == "Infantil" && (qual == "16+" || qual == "18+"))
				throw; //Pel.licula no apta.
			pVP = PassarelaVisualitzaPel(sU, titolP, data, 1);
			pVP.insereix();
		}
		catch (const sql::SQLException& e) {
			//No existeix la pelicula...
			throw;
		}
		
	}
}

PassarelaVisualitzaPel TxVisualitzarPel::obteVisualitzacio() {
	return pVP;
}