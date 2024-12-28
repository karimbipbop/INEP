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
	if (contraU != "") usuari.posaContrasenya(nomU);
	if (correuU != "") usuari.posaCorreuElectronic(nomU);
	if (neixU != "") usuari.posaDataNaixement(nomU);
	if (modalitatU != "") usuari.posaSubscripcio(nomU);

	if (nomU != "" or contraU != "" or correuU != "" or neixU != "" or modalitatU != "") {
		usuari.modifica();
	}
}