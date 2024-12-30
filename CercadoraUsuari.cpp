#include "CercadoraUsuari.h"


CercadoraUsuari::CercadoraUsuari() {
    
}

PassarelaUsuari CercadoraUsuari::cercaUsuari(string sobrenomU) {
    try {
        ConnexioBD& db = ConnexioBD::getInstance();
        string query = "SELECT * FROM usuari WHERE sobrenom = '" + sobrenomU + "'";

        sql::ResultSet* result = db.consulta(query);

        if (!result || !result->next()) {
            delete result;
            throw NoTrobat;
        }

        PassarelaUsuari pasUsu(result);

        delete result; // Free memory after use
        return pasUsu;
    }
    catch (const sql::SQLException& e) {
        throw e;
    }
}

PassarelaUsuari CercadoraUsuari::cercaUsuariPerCorreu(string correuU) {
    try {
        ConnexioBD& db = ConnexioBD::getInstance();
        string query = "SELECT * FROM usuari WHERE correu_electronic = '" + correuU + "'";

        sql::ResultSet* result = db.consulta(query);

        if (!result || !result->next()) {
            delete result;
            throw NoTrobat;
        }

        PassarelaUsuari pasUsu(result);

        delete result; // Free memory after use
        return pasUsu;
    }
    catch (const sql::SQLException& e) {
        throw e;
    }
}