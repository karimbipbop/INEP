#pragma once
#include <iostream>
#include <string>
#include "PassarelaUsuari.h"
#include "ConnexioBD.h"

using namespace std;

class CercadoraUsuari {
public:
    CercadoraUsuari();
    PassarelaUsuari cercaUsuari(string sobrenomU);
};