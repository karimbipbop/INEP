#pragma once
#include <iostream>
#include <string>
#include "PassarelaCapitol.h"
#include "ConnexioBD.h"

using namespace std;

class CercadoraCapitol {
public:
    CercadoraCapitol();
    PassarelaCapitol cercaCapitol(string titol_serie);
};