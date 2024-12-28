#pragma once
#include "DTOUsuari.h"
#include "Transaccio.h"
#include "PassarelaPelicula.h"

class TxConsultarPelicules : public Transaccio {
private:
    vector<DTOPelicula> resultat;

public:
    TxConsultarPelicules();
    void executar();
    vector<DTOPelicula> obteResultat();
};