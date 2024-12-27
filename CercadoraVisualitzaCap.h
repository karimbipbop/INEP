#pragma once
#include "PassarelaVisualitzaCap.h"
#include "ConnexioBD.h"

using namespace std;

class CercadoraVisualitzaCap {
public:
    CercadoraVisualitzaCap();
    vector<PassarelaVisualitzaCap> cercaVisualitzaCap(string sobrenom);
};