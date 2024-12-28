#include "TxProximesEstrenes.h"

TxProximesEstrenes::TxProximesEstrenes(string sub) {
	subscripcio = sub;
}

void TxProximesEstrenes::executar() {
	PetitFlix& pf = PetitFlix::getInstance();
	vector<pair<string, string>> continguts = cercCont.cercaContinguts();
	int n = continguts.size();
	vector<string> res;
	for (int i = 0; i < n; ++i) {
		if (continguts[i].second == "pelicula") {
			PassarelaPelicula p;
		}
		else {
			// es serie
		}
	}
	resultat = res;
}

vector<string> TxProximesEstrenes::obteResultat() {
	return resultat;
}

