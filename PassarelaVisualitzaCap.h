#pragma once
#include "ConnexioBD.h"

class PassarelaVisualitzaCap {
private:
    string sobrenom, titolSerie, data;
    int numTemporada, numCapitol, numVisualitzacions;

public:
    PassarelaVisualitzaCap();
    PassarelaVisualitzaCap(sql::ResultSet* result);
    PassarelaVisualitzaCap(string sobrenomC, string titolSerieC, int numTemporadaC, int numCapitolC, string dataC, int numVisualitzacionsC);
    void insereix();
    void modifica();
    void esborra();

    string obteSobrenom();
    string obteTitolSerie();
    int obteNumTemporada();
    int obteNumCapitol();
    string obteData();
    int obteNumVisualitzacions();
};