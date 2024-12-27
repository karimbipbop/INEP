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
	resultat.first = pVisP.size();
	resultat.second = pVisC.size();
}

pair<int, int> TxInfoVisualitzacions::obteResultat() {
	return resultat;
}