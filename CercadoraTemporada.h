#pragma once
#include <iostream>
#include <string>
#include "PassarelaTemporada.h"
#include "ConnexioBD.h"

using namespace std;

class CercadoraTemporada {
public:
    CercadoraTemporada();
    vector<PassarelaTemporada> cercaTemporades(string titol_serie);
};