#pragma once
#include "ConnexioBD.h"

class PassarelaSerie {
private:
    string titol, dataEstrena;

public:
    PassarelaSerie();
    PassarelaSerie(sql::ResultSet* result);
    PassarelaSerie(string titolS, string dataEstrenaS);

    string obteTitol();
    string obteDataEstrena();
};