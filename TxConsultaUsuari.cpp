#include "TxConsultaUsuari.h"

TxConsultaUsuari::TxConsultaUsuari() {
}

void TxConsultaUsuari::executar() {
	PetitFlix& pf = PetitFlix::getInstance();
	usuari = pf.obteUsuari();
	resultat.sobrenom = usuari.obteSobrenom();
	resultat.nom = usuari.obteNom();
	resultat.correuElectronic = usuari.obteCorreuElectronic();
	resultat.dataNaixament = usuari.obteDataNaixement();
	resultat.subscripcio = usuari.obteSubscripcio();
}

Usuari TxConsultaUsuari::obteResultat() {
	return resultat;
}

