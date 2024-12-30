#include "PassarelaCapitol.h"

PassarelaCapitol::PassarelaCapitol()
{
    titolSerie = "";
    numeroTemporada = 0;
    numero = 0;
    titol = "";
    dataEstrena = "";
    qualificacio = "";
}

PassarelaCapitol::PassarelaCapitol(sql::ResultSet* result)
{
    titolSerie = result->getString("titol_serie");
    numeroTemporada = result->getInt("numero_temporada");
    numero = result->getInt("numero");
    titol = result->getString("titol");
    dataEstrena = result->getString("data_estrena");
    qualificacio = result->getString("qualificacio");
}

PassarelaCapitol::PassarelaCapitol(string titolSerieC, int numeroTemporadaC, int numeroC, string titolC, string dataEstrenaC, string qualificacioC)
{
    titolSerie = titolSerieC;
    numeroTemporada = numeroTemporadaC;
    numero = numeroC;
    titol = titolC;
    dataEstrena = dataEstrenaC;
    qualificacio = qualificacioC;
}

string PassarelaCapitol::obteTitolSerie()
{
    return titolSerie;
}


int PassarelaCapitol::obteNumeroTemporada()
{
    return numeroTemporada;
}

int PassarelaCapitol::obteNumero()
{
    return numero;
}

string PassarelaCapitol::obteTitol()
{
    return titol;
}

string PassarelaCapitol::obteDataEstrena()
{
    return dataEstrena;
}

string PassarelaCapitol::obteQualificacio()
{
    return qualificacio;
}