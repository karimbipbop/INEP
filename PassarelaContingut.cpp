#include "PassarelaContingut.h"

PassarelaContingut::PassarelaContingut()
{
    titol = "";
    descripcio = "";
    qualificacio = "";
    tipus = "";
}

PassarelaContingut::PassarelaContingut(sql::ResultSet* result)
{
    titol = result->getString("titol");
    descripcio = result->getString("descripcio");
    qualificacio = result->getString("qualificacio");
    tipus = result->getString("tipus");
}


PassarelaContingut::PassarelaContingut(string titolC, string descripcioC, string qualificacioC, string tipusC)
{
    titol = titolC;
    descripcio = descripcioC;
    qualificacio = qualificacioC;
    tipus = tipusC;
}

void PassarelaContingut::insereix()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "INSERT INTO contingut VALUES ('" +
            titol + "', '" +
            descripcio + "', '" +
            qualificacio + "', '" +
            tipus + "')";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void PassarelaContingut::modifica()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "UPDATE contingut SET "
            "titol = '" + titol + "', "
            "descripcio = '" + descripcio + "', "
            "qualificacio = '" + qualificacio + "', "
            "tipus = '" + tipus + "' "
            "WHERE titol = '" + titol + "'";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << endl;
    }
}

void PassarelaContingut::esborra()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "DELETE FROM contingut WHERE titol = '" + titol + "'";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

string PassarelaContingut::obteTitol()
{
    return titol;
}


string PassarelaContingut::obteDescripcio()
{
    return descripcio;
}

string PassarelaContingut::obteQualificacio()
{
    return qualificacio;
}

string PassarelaContingut::obteTipus()
{
    return tipus;
}

//void PassarelaContingut::posaTitol(string titolC)
//{
//    titol = titolC;
//}
//
//void PassarelaContingut::posaDescripcio(string descripcioC)
//{
//    descripcio = descripcioC;
//}
//
//void PassarelaContingut::posaQualificacio(string qualificacioC)
//{
//    qualificacio = qualificacioC;
//}
//
//void PassarelaContingut::posaTipus(string tipusC)
//{
//    tipus = tipusC;
//}