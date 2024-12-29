#include "TxUltimesNovetats.h"

TxUltimesNovetats::TxUltimesNovetats(string sub) {
	subscripcio = sub;
}

void TxUltimesNovetats::executar() {
	PetitFlix& pf = PetitFlix::getInstance();

	string dataAvui = today();

	vector<PassarelaContingut> continguts;
	if (subscripcio == "Infantil") {
		continguts = cercCont.cercaContingutsPerQualificacio({ "TP", "7+", "12+" });
	}
	else if (subscripcio == "Completa") {
		continguts = cercCont.cercaContinguts();
	}
	else {
		// Cinèfil
		continguts = cercCont.cercaContingutsPerTipus("pelicula");
	}

	int n = continguts.size();
	vector<string> pelicules;
	vector<string> capitols;
	vector<string> dataPelicules;
	vector<string> dataCapitols;
	for (auto& cont : continguts) {
		vector<string> dataEstrena;
		vector<string> infoContingut;
		if (cont.obteTipus() == "pelicula") {
			PassarelaPelicula p = cercPel.cercaPelicula(cont.obteTitol());
			dataEstrena.push_back(p.obteDataEstrena());
			string dataArreglada = dataEstrena[0];
			formatDate(dataArreglada);
			infoContingut.push_back(dataArreglada + ": " + p.obteTitol() + "; " +
				cont.obteQualificacio() + "; " + to_string(p.obteDuracio()) + " min.");
		}
		else {
			vector<PassarelaCapitol> capitols = cercCap.cercaCapitols(cont.obteTitol());
			for (auto& c : capitols) {
				dataEstrena.push_back(c.obteDataEstrena());
				string dataArreglada = c.obteDataEstrena();
				formatDate(dataArreglada);
				infoContingut.push_back(dataArreglada + ": " + c.obteTitolSerie() + "; " +
					cont.obteQualificacio() + "; Temporada " + to_string(c.obteNumeroTemporada()) + 
					"; Capitol " + to_string(c.obteNumero()) + '.');
			}
		}
		int n = infoContingut.size();
		if (cont.obteTipus() == "pelicula") {
			if (dataEstrena[0] < dataAvui) {
				auto it = lower_bound(dataPelicules.begin(), dataPelicules.end(), dataEstrena[0], std::greater<>());
				size_t index = distance(dataPelicules.begin(), it);
				dataPelicules.insert(it, dataEstrena[0]);
				pelicules.insert(pelicules.begin() + index, infoContingut[0]);
				if (pelicules.size() > 10) { // Borrem per nomes mostrar les 10 noves estrenes
					pelicules.pop_back();
					dataPelicules.pop_back();
				}
			}
		}
		else {
			for (int i = 0; i < n; ++i) {
				if (dataEstrena[i] < dataAvui) {
					auto it = lower_bound(dataCapitols.begin(), dataCapitols.end(), dataEstrena[i], std::greater<>());
					size_t index = distance(dataCapitols.begin(), it);
					dataCapitols.insert(it, dataEstrena[i]);
					capitols.insert(capitols.begin() + index, infoContingut[i]);
					if (capitols.size() > 10) { // Borrem per nomes mostrar les 10 noves estrenes
						capitols.pop_back();
						dataCapitols.pop_back();
					}
				}
			}
		}
	}
	resultat = make_pair(pelicules, capitols);
}

pair<vector<string>, vector<string>> TxUltimesNovetats::obteResultat() {
	return resultat;
}

