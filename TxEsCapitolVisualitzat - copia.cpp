#include "TxEsCapitolVisualitzat.h"

TxEsCapitolVisualitzat::TxEsCapitolVisualitzat(string sobrenom, string titol_serie, int num_temporada, int num_capitol) {
	this->sobrenom = sobrenom;
	this->titol_serie = titol_serie;
	this->num_temporada = num_temporada;
	this->num_capitol = num_capitol;
}

void TxEsCapitolVisualitzat::executar() {
	try {
		PassarelaVisualitzaCap pVC = cercVisC.cercaVisualitzaCap(sobrenom, titol_serie, num_temporada, num_capitol);
		res.dataV = pVC.obteData();
		res.visualitzacions = pVC.obteNumVisualitzacions();
	}
	catch (sql::SQLException& e) {
		//no trobat visualitzacio
		throw e;
	}
}

DTOCapitol TxEsCapitolVisualitzat::obteResultat() {
	return res;
}