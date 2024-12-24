#include "PassarelaRelacionat.h"

PassarelaRelacionat::PassarelaRelacionat()
{
    titolX = "";
    titolY = "";
}

PassarelaRelacionat::PassarelaRelacionat(sql::ResultSet* result)
{
    if (result->next()) {
        titolX = result->getString("titol_x");
        titolY = result->getString("titol_y");
    }
}

PassarelaRelacionat::PassarelaRelacionat(string titolXr, string titolYr)
{
    titolX = titolXr;
    titolY = titolYr;
}

void PassarelaRelacionat::insereix()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "INSERT INTO relacionat VALUES ('" +
            titolX + "', '" + titolY + "')";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void PassarelaRelacionat::modifica()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "UPDATE relacionat SET "
            "titol_x = '" + titolX + "', "
            "titol_y = '" + titolY + "' "
            "WHERE titol_x = '" + titolX +
            "' AND titol_y = '" + titolY + "'";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << endl;
    }
}

void PassarelaRelacionat::esborra()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "DELETE FROM relacionat WHERE titol_x = '" + titolX +
            "' AND titol_y = '" + titolY + "'";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

string PassarelaRelacionat::obteTitolX()
{
    return titolX;
}


string PassarelaRelacionat::obteTitolY()
{
    return titolY;
}
