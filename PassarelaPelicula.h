#include "ConnexioBD.h"

class PassarelaPelicula {
private:
    string titol, dataEstrena;
    int duracio;

public:
    PassarelaPelicula();
    PassarelaPelicula(sql::ResultSet* result);
    PassarelaPelicula(string titolP, string dataEstrenaP, int duracioP);
    void insereix();
    void modifica();
    void esborra();

    string obteTitol();
    string obteDataEstrena();
    int obteDuracio();
    //void posaTitol(string titolP);
    //void posaDataEstrena(string dataEstrenaP);
    //void posaDuracio(int duracioP);
};