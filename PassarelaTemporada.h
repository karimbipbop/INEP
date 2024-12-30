#pragma once
#include "ConnexioBD.h"

class PassarelaTemporada {
private:
    string titolSerie;
    int numero;

public:
    PassarelaTemporada();
    PassarelaTemporada(sql::ResultSet* result);
    PassarelaTemporada(string titolSerieT, int numeroT);

    string obteTitolSerie();
    int obteNumero();
};