#pragma once
#include "ConnexioBD.h"

class PassarelaRelacionat {
private:
    string titolX, titolY;

public:
    PassarelaRelacionat();
    PassarelaRelacionat(sql::ResultSet* result);
    PassarelaRelacionat(string titolXr, string titolYr);

    string obteTitolX();
    string obteTitolY();
};