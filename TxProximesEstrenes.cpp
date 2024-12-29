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
		for (int i = 0; i < continguts.size(); ++i) {
			cout << continguts[i].obteTitol() << endl;
		}
	}
	else {
		// Cin�fil
		continguts = cercCont.cercaContingutsPerTipus("pelicula");
	}

	int n = continguts.size();
	vector<string> res; 
	vector<string> resData;
	for (auto&cont : continguts) {
		vector<string> dataEstrena;
		vector<string> infoContingut;
		cout << "TIpus: " << cont.obteTipus() << endl;
		if (cont.obteTipus() == "pelicula") {
			PassarelaPelicula p = cercPel.cercaPelicula(cont.obteTitol());
			dataEstrena.push_back(p.obteDataEstrena());
			string dataArreglada = dataEstrena[0];
			formatDate(dataArreglada);
			cout << dataArreglada << endl;
			infoContingut.push_back(dataArreglada + " [Pel.licula]: " + p.obteTitol() + "; " +
				cont.obteQualificacio() + "; " + to_string(p.obteDuracio()) + " min.");
		}
		else {
			vector<PassarelaCapitol> capitols = cercCap.cercaCapitols(cont.obteTitol());
			for (auto&c : capitols) {
				dataEstrena.push_back(c.obteDataEstrena());
				string dataArreglada = c.obteDataEstrena();
				formatDate(dataArreglada);
				infoContingut.push_back(dataArreglada + " [Serie]: " + c.obteTitolSerie() + "; " +
					cont.obteQualificacio() + "; Temporada " + to_string(c.obteNumeroTemporada()) + '.');

			}
		}
		int n = infoContingut.size();
		for (int i = 0; i < n; ++i) {
			if (dataEstrena[i] > dataAvui) {
				auto it = lower_bound(resData.begin(), resData.end(), dataEstrena[i]);
				size_t index = distance(resData.begin(), it);
				resData.insert(it, dataEstrena[i]);
				res.insert(res.begin() + index, infoContingut[i]);

				cout << continguts[i].obteTitol() << endl;
				if (res.size() > 10) { // Borrem per nomes mostrar les 10 noves estrenes
					res.pop_back();
					resData.pop_back();
				}
			}
		}
		
	}
	resultat = res;
}

vector<string> TxProximesEstrenes::obteResultat() {
	return resultat;
}

