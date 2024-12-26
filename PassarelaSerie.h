#include "ConnexioBD.h"

class PassarelaSerie {
private:
    string titol, dataEstrena;

public:
    PassarelaSerie();
    PassarelaSerie(sql::ResultSet* result);
    PassarelaSerie(string titolS, string dataEstrenaS);
    void insereix();
    void modifica();
    void esborra();

    string obteTitol();
    string obteDataEstrena();
    //void posaTitol(string titolS);
    //void posaDataEstrena(string dataEstrenaS);
};