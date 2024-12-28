#pragma once
#include "PetitFlix.h"
#include "TxConsultaUsuari.h"

class CtrlModificaUsuari {
private:
	PassarelaUsuari usuari;

public:
	CtrlModificaUsuari();
	DTOUsuari consultaUsuari();
	void modificaUsuari(string nomU, string contraU, string correuU, string neixU, string modalitatU);
};