#include "PassarelaSerie.h"

PassarelaSerie::PassarelaSerie()
{
    titol = "";
    dataEstrena = "";
}

PassarelaSerie::PassarelaSerie(sql::ResultSet* result)
{
    titol = result->getString("titol");
    dataEstrena = result->getString("data_estrena");
}

PassarelaSerie::PassarelaSerie(string titolS, string dataEstrenaS)
{
    titol = titolS;
    dataEstrena = dataEstrenaS;
}

string PassarelaSerie::obteTitol()
{
    return titol;
}


string PassarelaSerie::obteDataEstrena()
{
    return dataEstrena;
}
