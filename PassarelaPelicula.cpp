#include "PassarelaPelicula.h"

PassarelaPelicula::PassarelaPelicula()
{
    titol = "";
    dataEstrena = "";
    duracio = 0;
}

PassarelaPelicula::PassarelaPelicula(sql::ResultSet* result)
{
    if (result->next()) {
        titol = result->getString("titol");
        dataEstrena = result->getString("data_estrena");
        duracio = result->getInt("duracio");
    }
}


PassarelaPelicula::PassarelaPelicula(string titolP, string dataEstrenaP, int duracioP)
{
    titol = titolP;
    dataEstrena = dataEstrenaP;
    duracio = duracioP;
}

void PassarelaPelicula::insereix()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "INSERT INTO pelicula VALUES ('" +
            titol + "', '" +
            dataEstrena + "', '" +
            std::to_string(duracio) + "')";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void PassarelaPelicula::modifica()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "UPDATE pelicula SET "
            "titol = '" + titol + "', "
            "data_estrena = '" + dataEstrena + "', "
            "duracio = '" + std::to_string(duracio) + "' "
            "WHERE titol = '" + titol + "'";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << endl;
    }
}

void PassarelaPelicula::esborra()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "DELETE FROM pelicula WHERE titol = '" + titol + "'";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
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

//void PassarelaPelicula::posaTitol(string titolC)
//{
//    titol = titolC;
//}
//
//void PassarelaPelicula::posaDataEstrena(string dataEstrenaP)
//{
//    dataEstrena = dataEstrenaP;
//}
//
//void PassarelaPelicula::posaDuracio(string duracioP)
//{
//    duracio = duracioP;
//}