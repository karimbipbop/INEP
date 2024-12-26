#include "PassarelaSerie.h"

PassarelaSerie::PassarelaSerie()
{
    titol = "";
    dataEstrena = "";
}

PassarelaSerie::PassarelaSerie(sql::ResultSet* result)
{
    if (result->next()) {
        titol = result->getString("titol");
        dataEstrena = result->getString("data_estrena");
    }
}

PassarelaSerie::PassarelaSerie(string titolS, string dataEstrenaS)
{
    titol = titolS;
    dataEstrena = dataEstrenaS;
}

void PassarelaSerie::insereix()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "INSERT INTO serie VALUES ('" +
            titol + "', '" +
            dataEstrena + "')";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void PassarelaSerie::modifica()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "UPDATE serie SET "
            "titol = '" + titol + "', "
            "data_estrena = '" + dataEstrena + "' "
            "WHERE titol = '" + titol + "'";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << endl;
    }
}

void PassarelaSerie::esborra()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "DELETE FROM serie WHERE titol = '" + titol + "'";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

string PassarelaSerie::obteTitol()
{
    return titol;
}


string PassarelaSerie::obteDataEstrena()
{
    return dataEstrena;
}

//void PassarelaSerie::posaTitol(string titolS)
//{
//    titol = titolS;
//}
//
//void PassarelaSerie::posaDataEstrena(string dataEstrenaS)
//{
//    dataEstrena = dataEstrenaS;
//}
