#include "TxEsborraUsuari.h"

TxEsborraUsuari::TxEsborraUsuari(string c) {
	inicialitza();
	contrassenya = c;
}

void TxEsborraUsuari::executar() {
	PetitFlix p = PetitFlix::getInstance();
	PassarelaUsuari u = p.obteUsuari();
	if (contrassenya != u.obteContrasenya()) throw(ErrorContrasenya);
	u.esborra();
}
