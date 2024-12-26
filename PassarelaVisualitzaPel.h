#include "ConnexioBD.h"

class PassarelaVisualitzaPel {
private:
    string sobrenom, titolPelicula, data;
    int numVisualitzacions;

public:
    PassarelaVisualitzaPel();
    PassarelaVisualitzaPel(sql::ResultSet* result);
    PassarelaVisualitzaPel(string sobrenomP, string titolPeliculaP, string dataP, int numVisualitzacionsP);
    void insereix();
    void modifica();
    void esborra();

    string obteSobrenom();
    string obteTitolPelicula();
    string obteData();
    int obteNumVisualitzacions();
};
