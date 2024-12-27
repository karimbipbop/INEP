#pragma once
#include <iostream>
#include <string>
#include "PetitFlix.h"
#include "CercadoraUsuari.h"

using namespace std;

const int ErrorContrasenya = 2;

class Transaccio {
public:


    Transaccio();
    virtual void executar() = 0;
    ~Transaccio();



protected:
    CercadoraUsuari cercUsu;
    void inicialitza();

};