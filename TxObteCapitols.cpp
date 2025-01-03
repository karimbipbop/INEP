#include "TxObteCapitols.h"

TxObteCapitols::TxObteCapitols(string titol, int numT) {
	titol_serie = titol;
	numeroTemporada = numT;
}

void TxObteCapitols::executar() {
	try {
		PassarelaContingut pCon = cercCont.cercaContingutPerTitol(titol_serie);
		vector<PassarelaCapitol> pCap = cercCap.cercaCapitols(titol_serie, numeroTemporada);
		for (auto& capitol : pCap) {
			DTOCapitol c;
			c.titolSerie = pCon.obteTitol();
			c.descripcio = pCon.obteDescripcio();
			c.qualificacio = pCon.obteQualificacio();
			c.dataEstrena = capitol.obteDataEstrena();
			c.titolCapitol = capitol.obteTitol();
			c.numero = capitol.obteNumero();
			c.numeroTemporada = capitol.obteNumeroTemporada();

			res.push_back(c);
		}
		sort(res.begin(), res.end(), [](const DTOCapitol& a, const DTOCapitol& b) {
			return a.numero < b.numero; // Ordenem de mes gran a mes petit
			});
	}
	catch (int exc) {
		//no existeix la pelicula.
		throw exc;
	}
	catch (sql::SQLException& e) {
		throw e;
	}
}

vector<DTOCapitol> TxObteCapitols::obteResultat() {
	return res;
}