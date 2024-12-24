#include "PassarelaUsuari.h"
#include "PassarelaVisualitzaPel.h"
#include "PassarelaVisualitzaCap.h"
#include "PassarelaContingut.h"
#include "PassarelaPelicula.h"
#include "PassarelaSerie.h"
#include "PassarelaTemporada.h"
#include "PassarelaCapitol.h"
#include "PassarelaRelacionat.h"

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
