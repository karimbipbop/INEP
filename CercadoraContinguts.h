#pragma once
#include <iostream>
#include <string>
#include "PassarelaContingut.h"
#include "ConnexioBD.h"

using namespace std;

class CercadoraContinguts {
public:
    CercadoraContinguts();
    vector<pair<string, string>>cercaContinguts();
};