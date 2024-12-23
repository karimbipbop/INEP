#include "PassarelaUsuari.h"

class CapaDePresentacio {
private:
	CapaDePresentacio();

public:

	static CapaDePresentacio& getInstance() {
		static CapaDePresentacio p;
		return p;
	}

	void processarRegistreUsuari();
	void processarConsultaUsuari();
	void processarModificaUsuari();
	void processarEsborraUsuari();
	void processarGestioPelicules();
	void processarGestioSeries();
	void processarConsultaQualificacioEdat();
	void processarUltimesNovetats();
	void processarProximesEstrenes();
};
