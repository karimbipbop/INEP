#include "CtrlModificaUsuari.h"

CtrlModificaUsuari::CtrlModificaUsuari() {
	usuari = PassarelaUsuari();
}

DTOUsuari CtrlModificaUsuari::consultaUsuari() {

	TxConsultaUsuari tcon;
	tcon.executar();
	DTOUsuari u = tcon.obteResultat();
	usuari = tcon.obteUsuari();
	return u;
}

void CtrlModificaUsuari::modificaUsuari(string nomU, string contraU, string correuU, string neixU, string modalitatU) {
	if (nomU != "") usuari.posaNom(nomU);
	if (contraU != "") usuari.posaContrasenya(contraU);
	if (correuU != "") usuari.posaCorreuElectronic(correuU);
	if (neixU != "") usuari.posaDataNaixement(neixU);
	if (modalitatU != "") usuari.posaSubscripcio(modalitatU);

	try {
		usuari.modifica();
		PetitFlix& pf = PetitFlix::getInstance();
		pf.iniciaSessio(usuari);
	}
	catch (sql::SQLException& e) {
		throw(e);
	}
}