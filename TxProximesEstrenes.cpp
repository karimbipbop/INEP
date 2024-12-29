#include "TxProximesEstrenes.h"

TxProximesEstrenes::TxProximesEstrenes(string sub) {
	subscripcio = sub;
}

void TxProximesEstrenes::executar() {
	PetitFlix& pf = PetitFlix::getInstance();
	
	string dataAvui = today();

	vector<PassarelaContingut> continguts;
	if (subscripcio == "Infantil") {
		continguts = cercCont.cercaContingutsPerQualificacio({ "TP", "+7", "+12"});
	}
	else if (subscripcio == "Completa") {
		continguts = cercCont.cercaContinguts();
	}
	else {
		// Cinèfil
		continguts = cercCont.cercaContingutsPerTipus("pelicula");
	}

	int n = continguts.size();
	vector<string> res; 
	vector<string> resData;
	for (int i = 0; i < n; ++i) {
		string dataEstrena;
		string infoContingut;
		if (continguts[i].obteTipus() == "pelicula") {
			PassarelaPelicula p = cercPel.cercaPelicula(continguts[i].obteTitol());
			dataEstrena = p.obteDataEstrena();
			string dataArreglada = dataEstrena;
			formatDate(dataArreglada);
			infoContingut = dataArreglada + " [Pel·lícula]: " + p.obteTitol() + "; " +
				continguts[i].obteQualificacio() + "; " + to_string(p.obteDuracio()) + " min.";
		}
		else {
			PassarelaCapitol c = cercCap.cercaCapitol(continguts[i].obteTitol());
			dataEstrena = c.obteDataEstrena();
			string dataArreglada = dataEstrena;
			formatDate(dataArreglada);
			infoContingut = dataArreglada + " [Sèrie]: " + c.obteTitolSerie() + "; " +
				continguts[i].obteQualificacio() + "; Temporada " + to_string(c.obteNumeroTemporada()) + '.';
		}
		if (dataEstrena > dataAvui) {
			auto it = lower_bound(resData.begin(), resData.end(), dataEstrena);
			resData.insert(it, dataEstrena);
			res.insert(res.begin() + (it - resData.begin()), infoContingut);

			if (res.size() > 10) { // Borrem per nomes mostrar les 10 noves estrenes
				res.pop_back();
				resData.pop_back();
			}
		}
	}
	resultat = res;
}

vector<string> TxProximesEstrenes::obteResultat() {
	return resultat;
}

