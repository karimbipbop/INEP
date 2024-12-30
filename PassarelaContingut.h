#pragma once
#include "ConnexioBD.h"

class PassarelaContingut {
private:
    string titol, descripcio, qualificacio, tipus;

public:
    PassarelaContingut();
    PassarelaContingut(sql::ResultSet* result);
    PassarelaContingut(string titolC, string descripcioC, string qualificacioC, string tipusC);

    string obteTitol();
    string obteDescripcio();
    string obteQualificacio();
    string obteTipus();
};