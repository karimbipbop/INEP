#include "TxEsCapitolVisualitzat.h"

TxEsCapitolVisualitzat::TxEsCapitolVisualitzat(string sobrenom, string titol_serie, int num_temporada, int num_capitol) {
	this->sobrenom = sobrenom;
	this->titol_serie = titol_serie;
	this->num_temporada = num_temporada;
	this->num_capitol = num_capitol;
}

void TxEsCapitolVisualitzat::executar() {
	
}

bool TxEsCapitolVisualitzat::obteResultat() {
	return resultat;
}