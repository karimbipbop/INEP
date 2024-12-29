#pragma once
#include <iostream>
#include <string>
#include "PassarelaContingut.h"
#include "ConnexioBD.h"

using namespace std;

class CercadoraContinguts {
public:
    CercadoraContinguts();
    vector<PassarelaContingut>cercaContinguts();
    vector<PassarelaContingut>cercaContingutsPerQualificacio(vector<string> qualificacions);
    vector<PassarelaContingut>cercaContingutsPerTipus(string tipus);
};