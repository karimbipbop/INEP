#pragma once
#include "ConnexioBD.h"

class PassarelaCapitol {
private:
    string titolSerie, titol, dataEstrena, qualificacio;
    int numeroTemporada, numero;

public:
    PassarelaCapitol();
    PassarelaCapitol(sql::ResultSet* result);
    PassarelaCapitol(string titolSerieC, int numeroTemporadaC, int numeroC, string titolC, string dataEstrenaC, string qualificacioC);
    void insereix();
    void modifica();
    void esborra();

    string obteTitolSerie();
    int obteNumeroTemporada();
    int obteNumero();
    string obteTitol();
    string obteDataEstrena();
    string obteQualificacio();
};
