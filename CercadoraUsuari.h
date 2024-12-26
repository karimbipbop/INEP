#pragma once
#include <iostream>
#include <string>
#include "PassarelaUsuari.h"
#include "ConnexioBD.h"


const int UsuariNoExisteix = 1;

using namespace std;

class CercadoraUsuari {
public:
    CercadoraUsuari();
    PassarelaUsuari cercaUsuari(string sobrenomU);
};