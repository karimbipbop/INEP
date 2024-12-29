#pragma once
#include <iostream>
#include <string>
#include "PetitFlix.h"
#include "CercadoraUsuari.h"
#include "CercadoraVisualitzaCap.h"
#include "CercadoraVisualitzaPel.h"
#include "CercadoraContinguts.h"
#include "CercadoraPelicula.h"

using namespace std;

const int ErrorContrasenya = 2;
const int NoTancaSessio = 5;

class Transaccio {
public:
    Transaccio();
    virtual void executar() = 0;
    ~Transaccio();

protected:
    CercadoraUsuari cercUsu;
    CercadoraVisualitzaPel cercVisP;
    CercadoraVisualitzaCap cercVisC;
    CercadoraContinguts cercCont;
    CercadoraPelicula cercPel;
    void inicialitza();

};