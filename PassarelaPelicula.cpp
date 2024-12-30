#include "PassarelaPelicula.h"

PassarelaPelicula::PassarelaPelicula()
{
    titol = "";
    dataEstrena = "";
    duracio = 0;
}

PassarelaPelicula::PassarelaPelicula(sql::ResultSet* result)
{
    titol = result->getString("titol");
    dataEstrena = result->getString("data_estrena");
    duracio = result->getInt("duracio");
}


PassarelaPelicula::PassarelaPelicula(string titolP, string dataEstrenaP, int duracioP)
{
    titol = titolP;
    dataEstrena = dataEstrenaP;
    duracio = duracioP;
}

string PassarelaPelicula::obteTitol()
{
    return titol;
}


string PassarelaPelicula::obteDataEstrena()
{
    return dataEstrena;
}

int PassarelaPelicula::obteDuracio()
{
    return duracio;
}