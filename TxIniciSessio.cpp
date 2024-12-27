#include "TxIniciSessio.h"

TxIniciSessio::TxIniciSessio(string sU, string cU) {
	inicialitza();
	sobrenom = sU;
	contrasenya = cU;
}

void TxIniciSessio::executar() {
	PassarelaUsuari pU = cercUsu.cercaUsuari(sobrenom);
	if (pU.obteContrasenya() != contrasenya)
		throw(ErrorContrasenya);
	//Iniciar sesion con usuario pU...
}