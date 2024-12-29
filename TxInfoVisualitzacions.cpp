#include "TxInfoVisualitzacions.h"

TxInfoVisualitzacions::TxInfoVisualitzacions() {
	resultat.first = 0;
	resultat.second = 0;
}

void TxInfoVisualitzacions::executar() {
	PetitFlix& pf = PetitFlix::getInstance();
	string sobrenom = pf.obteUsuari().obteSobrenom();
	vector<PassarelaVisualitzaPel> pVisP = cercVisP.cercaVisualitzaPel(sobrenom);
	vector<PassarelaVisualitzaCap> pVisC = cercVisC.cercaVisualitzaCap(sobrenom);
	for (unsigned int i = 0; i < pVisP.size(); ++i) {
		resultat.first += pVisP[i].obteNumVisualitzacions();
		DTOPelicula aux;
		aux.titol = pVisP[i].obteTitolPelicula();
		aux.dataV = pVisP[i].obteData();
		formatDate(aux.dataV);
		aux.visualitzacions = pVisP[i].obteNumVisualitzacions();
		visP.push_back(aux);
	}
	for (unsigned int i = 0; i < pVisC.size(); ++i) {
		resultat.second += pVisC[i].obteNumVisualitzacions();
		DTOCapitol aux;
		aux.titolSerie = pVisC[i].obteTitolSerie();
		aux.numeroTemporada = pVisC[i].obteNumTemporada();
		aux.numero = pVisC[i].obteNumCapitol();
		aux.dataV = pVisC[i].obteData();
		aux.visualitzacions = pVisC[i].obteNumVisualitzacions();
		visC.push_back(aux);
	}
}

pair<int, int> TxInfoVisualitzacions::obteResultat() {
	return resultat;
}

vector<DTOPelicula> TxInfoVisualitzacions::obtePelVisu() {
	return visP;
}

vector<DTOCapitol> TxInfoVisualitzacions::obteCapVisu() {
	return visC;
}