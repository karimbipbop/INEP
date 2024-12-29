#pragma once
#include <iostream>
#include <string>
#include "PassarelaRelacionat.h"
#include "ConnexioBD.h"

using namespace std;

class CercadoraRelacionat {
public:
    CercadoraRelacionat();
    vector<PassarelaRelacionat> cercaRelacionats(string titol);
};