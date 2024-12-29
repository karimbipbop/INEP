#include "TxObteCapitols.h"

TxObteCapitols::TxObteCapitols(string titol) {
	titol_serie = titol;
}

void TxObteCapitols::executar() {
	try {
		PassarelaContingut pCon = cercCont.cercaContingutPerTitol(titol_serie);
		vector<PassarelaCapitol> pCap = cercCap.cercaCapitols(titol_serie);
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
	catch (sql::SQLException& e) {
		//no existeix la pelicula.
		throw;
	}
}

vector<DTOCapitol> TxObteCapitols::obteResultat() {
	return res;
}