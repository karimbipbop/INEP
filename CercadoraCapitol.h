#pragma once
#include <iostream>
#include <string>
#include "PassarelaCapitol.h"
#include "ConnexioBD.h"

using namespace std;

class CercadoraCapitol {
public:
    CercadoraCapitol();
    vector<PassarelaCapitol> cercaCapitols(string titol_serie);
};