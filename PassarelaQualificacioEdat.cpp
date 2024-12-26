#include "PassarelaQualificacioEdat.h"

PassarelaQualificacioEdat::PassarelaQualificacioEdat()
{
    nom = "";
}

PassarelaQualificacioEdat::PassarelaQualificacioEdat(sql::ResultSet* result)
{
    if (result->next()) {
        nom = result->getString("nom");
    }
}

PassarelaQualificacioEdat::PassarelaQualificacioEdat(string nomQ)
{
    nom = nomQ;
}

void PassarelaQualificacioEdat::insereix()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "INSERT INTO qualificacio_edat VALUES ('" +
            nom + "')";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void PassarelaQualificacioEdat::modifica()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "UPDATE qualificacio_edat SET "
            "nom = '" + nom + "' WHERE nom = '" +
            nom + "'";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << endl;
    }
}

void PassarelaQualificacioEdat::esborra()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        std::string query = "DELETE FROM qualificio_edat WHERE nom = '"
            + nom + "'";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

string PassarelaQualificacioEdat::obteNom()
{
    return nom;
}