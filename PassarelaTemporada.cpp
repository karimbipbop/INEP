#include "PassarelaTemporada.h"

PassarelaTemporada::PassarelaTemporada()
{
    titolSerie = "";
    numero = 0;
}

PassarelaTemporada::PassarelaTemporada(sql::ResultSet* result)
{
    titolSerie = result->getString("titol_serie");
    numero = result->getInt("numero");
}

PassarelaTemporada::PassarelaTemporada(string titolSerieT, int numeroT)
{
    titolSerie = titolSerieT;
    numero = numeroT;
}

string PassarelaTemporada::obteTitolSerie()
{
    return titolSerie;
}


int PassarelaTemporada::obteNumero()
{
    return numero;
}