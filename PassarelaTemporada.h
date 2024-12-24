#include "ConnexioBD.h"

class PassarelaTemporada {
private:
    string titolSerie;
    int numero;

public:
    PassarelaTemporada();
    PassarelaTemporada(sql::ResultSet* result);
    PassarelaTemporada(string titolSerieT, int numeroT);
    void insereix();
    void modifica();
    void esborra();

    string obteTitolSerie();
    int obteNumero();
    //void posaTitolSerie(string titolSerieT);
    //void posaNumero(int numeroT);
};