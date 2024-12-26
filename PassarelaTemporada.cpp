#include "PassarelaTemporada.h"

PassarelaTemporada::PassarelaTemporada()
{
    titolSerie = "";
    numero = 0;
}

PassarelaTemporada::PassarelaTemporada(sql::ResultSet* result)
{
    if (result->next()) {
        titolSerie = result->getString("titol_serie");
        numero = result->getInt("numero");
    }
}

PassarelaTemporada::PassarelaTemporada(string titolSerieT, int numeroT)
{
    titolSerie = titolSerieT;
    numero = numeroT;
}

void PassarelaTemporada::insereix()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "INSERT INTO temporada VALUES ('" +
            titolSerie + "', '" +
            std::to_string(numero) + "')";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void PassarelaTemporada::modifica()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "UPDATE temporada SET "
            "titol_serie = '" + titolSerie + "', "
            "numero = '" + std::to_string(numero) + "' "
            "WHERE titol_serie = '" + titolSerie + 
            "' AND numero = '" + std::to_string(numero) + "'";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << endl;
    }
}

void PassarelaTemporada::esborra()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "DELETE FROM temporada WHERE titol_serie = '" + titolSerie +
                            "' AND numero = '" + std::to_string(numero) + "'";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

string PassarelaTemporada::obteTitolSerie()
{
    return titolSerie;
}


int PassarelaTemporada::obteNumero()
{
    return numero;
}

//void PassarelaTemporada::posaTitolSerie(string titolSerieT)
//{
//    titolSerie = titolSerieT;
//}
//
//void PassarelaTemporada::posaNumero(int numeroT)
//{
//    numero = numeroT;
//}