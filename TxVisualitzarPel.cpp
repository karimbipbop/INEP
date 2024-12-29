#include "TxVisualitzarPel.h"

TxVisualitzarPel::TxVisualitzarPel(string sobrenom, string titol) {
	sU = sobrenom;
	titolP = titol;
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
			//PassarelaContingut pCon = cercCont.cercaContinguts();
			pVP = PassarelaVisualitzaPel(sU, titolP, data, 1);
		}
		catch (const sql::SQLException& e) {
			//No existeix la pelicula...
			throw;
		}
		
	}
}

PassarelaVisualitzaPel TxVisualitzarPel::obteResultat() {
	return pVP;
}