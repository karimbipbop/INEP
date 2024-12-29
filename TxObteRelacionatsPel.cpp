#include "TxObteRelacionatsPel.h"

TxObteRelacionatsPel::TxObteRelacionatsPel(string titolC) {
	titol = titolC;
}

void TxObteRelacionatsPel::executar() {
	vector<PassarelaRelacionat> relacionats = cercRel.cercaRelacionats(titol);
	for (unsigned int i = 0; i < relacionats.size(); ++i) {
		if (relacionats[i].obteTitolX() == titol)
			titolsRel.push_back(relacionats[i].obteTitolY());
		else
			titolsRel.push_back(relacionats[i].obteTitolX());
	}
}

vector<string> TxObteRelacionatsPel::obteTitolsRel() {
	return titolsRel;
}