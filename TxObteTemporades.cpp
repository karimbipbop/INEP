#include "TxObteTemporades.h"

TxObteTemporades::TxObteTemporades(string titolP) {
	titol = titolP;
}

void TxObteTemporades::executar() {
	try {
		vPasTemp = cercTemp.cercaTemporades(titol);
		int n = vPasTemp.size();
		for (int i = 0; i < n; ++i) {
			DTOTemporada t;
			t.numero = vPasTemp[i].obteNumero();
			t.titol_serie = titol;
			res.push_back(t);
		}
	}
	catch (sql::SQLException& e) {
		//no existeix la pelicula.
		throw;
	}
}

vector<DTOTemporada> TxObteTemporades::obteResultat() {
	return res;
}