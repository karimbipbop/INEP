#pragma once
#include "PassarelaVisualitzaPel.h"
#include "ConnexioBD.h"

using namespace std;

class CercadoraVisualitzaPel {
public:
    CercadoraVisualitzaPel();
    vector<PassarelaVisualitzaPel> cercaVisualitzaPel(string sobrenom);
    PassarelaVisualitzaPel cercaVisualitzaPel(string sobrenom, string titol);
};