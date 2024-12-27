#include "TxTancaSessio.h"

TxTancaUsuari::TxTancaUsuari() {
	inicialitza();
}

void TxTancaUsuari::executar() {
	PassarelaUsuari pU = cercUsu.cercaUsuari(usuari.sobrenom);
	//Cerrar sesion con usuario pU...
	// PetitFlix.tancaSessio(); algo asi
}