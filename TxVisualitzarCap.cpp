#include "TxVisualitzarCap.h"

TxVisualitzarCap::TxVisualitzarCap(string sobrenom, string titolS, int numT, int numC) {
	sU = sobrenom;
	titolSerie = titolS;
	numeroT = numT;
	numeroC = numC;
}

void TxVisualitzarCap::executar() {
	try {
		//Existeix una visualitzacio d'aquest usuari per aquesta pel.licula, augmenta en 1 numVisualitzacions.
		PassarelaVisualitzaCap visC = cercVisC.cercaVisualitzaCap(sU, titolSerie, numeroT, numeroC);
		visC.augmentaNumVisualitzacions();
		visC.modifica();
	}
	catch (int exc) {
		//No existeix una visualitzacio d'aquest usuari per aquesta pel.licula.
		try {
			PassarelaCapitol cap = cercCap.cercaCapitol(titolSerie, numeroT, numeroC);
			string data = today();
			if (cap.obteDataEstrena() > data) {
				throw NoEstrenat; //no estrenada.
			}
			pVC = PassarelaVisualitzaCap(sU, titolSerie, numeroT, numeroC, data, 1);
			pVC.insereix();
		}
		catch (int exc) {
			//No existeix...
			throw exc;
		}

	}
}

PassarelaVisualitzaCap TxVisualitzarCap::obteVisualitzacio() {
	return pVC;
}