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
	}
	for (unsigned int i = 0; i < pVisC.size(); ++i) {
		resultat.second += pVisC[i].obteNumVisualitzacions();
	}
}

pair<int, int> TxInfoVisualitzacions::obteResultat() {
	return resultat;
}