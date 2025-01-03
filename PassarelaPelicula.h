#pragma once
#include "ConnexioBD.h"

class PassarelaPelicula {
private:
    string titol, dataEstrena;
    int duracio;

public:
    PassarelaPelicula();
    PassarelaPelicula(sql::ResultSet* result);
    PassarelaPelicula(string titolP, string dataEstrenaP, int duracioP);

    string obteTitol();
    string obteDataEstrena();
    int obteDuracio();
};