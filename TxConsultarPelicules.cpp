#include "TxConsultarPelicules.h"

TxConsultarPelicules::TxConsultarPelicules() {
}

// funcio auxiliar per ordenar el vector de pel·lícules segons el nombre de visualitzacions
bool compare(const pair<string, int>& a, const pair<string, int>& b) {
	return a.second > b.second;
}

void TxConsultarPelicules::executar() {
	PetitFlix& pf = PetitFlix::getInstance();
	PassarelaUsuari u = pf.obteUsuari();

	vector<pair<string, int> > titolPels = cercCont.cercaPelicules();

	sort(titolPels.begin(), titolPels.end(), compare);
	for (int i = 0; i < titolPels.size(); ++i) {
		PassarelaContingut pelCon = cercCont.cercaContingutPerTitol(titolPels[i].first);
		PassarelaPelicula pel = cercPel.cercaPelicula(titolPels[i].first);
		string info = pel.obteTitol() + "; " + pelCon.obteQualificacio() + "; " + to_string(pel.obteDuracio()) + " min.; Visualitzacions: " + to_string(titolPels[i].second);

		try {
			PassarelaVisualitzaPel vis = cercVisP.cercaVisualitzaPel(u.obteSobrenom(), pel.obteTitol());
			string data = vis.obteData();
			formatDate(data);
			info += " [VISTA: " + data + "]";
		}
		catch (...) {
			// no s'ha visualitzat
		}

		resultat.push_back(info);
	}
}

vector<string> TxConsultarPelicules::obteResultat() {
	return resultat;
}