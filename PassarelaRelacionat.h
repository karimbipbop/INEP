#pragma once
#include "ConnexioBD.h"

class PassarelaRelacionat {
private:
    string titolX, titolY;

public:
    PassarelaRelacionat();
    PassarelaRelacionat(sql::ResultSet* result);
    PassarelaRelacionat(string titolXr, string titolYr);
    void insereix();
    void modifica();
    void esborra();

    string obteTitolX();
    string obteTitolY();
};