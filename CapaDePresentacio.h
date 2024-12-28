//#include "PassarelaUsuari.h"
//#include "PassarelaVisualitzaPel.h"
//#include "PassarelaVisualitzaCap.h"
//#include "PassarelaContingut.h"
//#include "PassarelaPelicula.h"
//#include "PassarelaSerie.h"
//#include "PassarelaTemporada.h"
//#include "PassarelaCapitol.h"
//#include "PassarelaRelacionat.h"
//#include "PassarelaQualificacioEdat.h"
//#include "PassarelaModalitatSubscripcio.h"
#include "TxRegistraUsuari.h"
#include "TxIniciSessio.h"
#include "TxTancaSessio.h"
#include "TxConsultaUsuari.h"
#include "TxInfoVisualitzacions.h"
#include "TxEsborraUsuari.h"
#include "CtrlModificaUsuari.h"

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

	/*a partir de aqui son operaciones de las entregas del lab*/
	//void processarConsultaUsuari();
	//void processarModificaUsuari();
	//void processarGestioPelicules();
	//void processarGestioSeries();
	//void processarConsultaQualificacioEdat();
	//void processarUltimesNovetats();
	//void processarProximesEstrenes();
};
