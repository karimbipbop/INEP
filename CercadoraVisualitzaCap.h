#pragma once
#include "PassarelaVisualitzaCap.h"
#include "ConnexioBD.h"

using namespace std;

class CercadoraVisualitzaCap {
public:
    CercadoraVisualitzaCap();
    vector<PassarelaVisualitzaCap> cercaVisualitzaCap(string sobrenom);
    PassarelaVisualitzaCap cercaVisualitzaCap(string sobrenom, string titol_serie, int num_temporada, int num_capitol);
};