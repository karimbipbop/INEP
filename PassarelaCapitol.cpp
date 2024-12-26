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
    if (result->next()) {
        titolSerie = result->getString("titol_serie");
        numeroTemporada = result->getInt("numero_temporada");
        numero = result->getInt("numero");
        titol = result->getString("titol");
        dataEstrena = result->getString("data_estrena");
        qualificacio = result->getString("qualificacio");
    }
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

void PassarelaCapitol::insereix()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "INSERT INTO capitol VALUES ('" +
            titolSerie + "', '" + std::to_string(numeroTemporada) +
            "', '" + std::to_string(numero) + "', '" + titol + "', '" +
            dataEstrena + "', '" + qualificacio + "')";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void PassarelaCapitol::modifica()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "UPDATE capitol SET "
            "titol_serie = '" + titolSerie + "', "
            "numero_temporada = '" + std::to_string(numeroTemporada) + "', "
            "numero = '" + std::to_string(numero) + "', "
            "titol = '" + titol + "', " + "data_estrena = '" + dataEstrena
            + "', qualificacio = '" + qualificacio + "' "
            "WHERE titol_serie = '" + titolSerie +
            "' AND numero_temporada = '" + std::to_string(numeroTemporada) +
            "' AND numero = '" + std::to_string(numero) + "'";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << endl;
    }
}

void PassarelaCapitol::esborra()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "DELETE FROM capitol WHERE titol_serie = '" + titolSerie +
            "' AND numero_temporada = '" + std::to_string(numeroTemporada) + "' AND" +
            " numero = '" + std::to_string(numero) + "'";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
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