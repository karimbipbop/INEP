#pragma once
#include "TxRegistraUsuari.h"
#include "TxIniciSessio.h"
#include "TxTancaSessio.h"
#include "TxConsultaUsuari.h"
#include "TxInfoVisualitzacions.h"
#include "TxEsborraUsuari.h"
#include "CtrlModificaUsuari.h"
#include "TxVisualitzarPel.h"
#include "TxObteInfoPel.h"
#include "TxObteContingut.h"
#include "TxObteCapitols.h"
#include "TxObteTemporades.h"
#include "TxObteRelacionatsPel.h"
#include "TxObteInfoCap.h"
#include "TxProximesEstrenes.h"
#include "TxUltimesNovetats.h"
#include "TxConsultarPelicules.h"


//Variables globals per manejar el menu.
extern bool run;
extern bool logg;

class CapaDePresentacio {
private:
	CapaDePresentacio();

public:

	static CapaDePresentacio& getInstance();
	void processarRegistreUsuari();
	void processarIniciSessio();
	void processarTancaSessio();
	void processarConsultaUsuari();
	void processarModificaUsuari();
	void processarEsborraUsuari();

	void processarVisualitzaPel();
	void processarVisualitzaCap();
	void processarConsultarVisualitzacions();
	void processarProximesEstrenes();
	void processarUltimesNovetats();
	void processarConsultarPelicules();
};
