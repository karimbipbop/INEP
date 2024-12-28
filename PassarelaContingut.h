#pragma once
#include "ConnexioBD.h"

class PassarelaContingut {
private:
    string titol, descripcio, qualificacio, tipus;

public:
    PassarelaContingut();
    PassarelaContingut(sql::ResultSet* result);
    PassarelaContingut(string titolC, string descripcioC, string qualificacioC, string tipusC);
    void insereix();
    void modifica();
    void esborra();

    string obteTitol();
    string obteDescripcio();
    string obteQualificacio();
    string obteTipus();
    //void posaTitol(string titolC);
    //void posaDescripcio(string descripcioC);
    //void posaQualificacio(string qualificacioC);
    //void posaTipus(string tipusC);
};