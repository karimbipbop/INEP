#include "CercadoraCapitol.h"


CercadoraCapitol::CercadoraCapitol() {

}

vector<PassarelaCapitol> CercadoraCapitol::cercaCapitols(string titol_serie) {
    try {
        ConnexioBD& db = ConnexioBD::getInstance();
        string query = "SELECT * FROM capitol WHERE titol_serie = '" + titol_serie + "'";

        sql::ResultSet* result = db.consulta(query);

        if (!result) {
            delete result;
            throw;
            // No hi ha continguts llavors...
        }

        vector<PassarelaCapitol> vpasCap;
        while (result->next()) {
            PassarelaCapitol pasCap(result);
            vpasCap.push_back(pasCap);
        }

        delete result; // Free memory after use
        return vpasCap;
    }
    catch (const sql::SQLException& e) {
        cerr << "MySQL error: " << e.what() << endl;
        throw;
    }
}

vector<PassarelaCapitol> CercadoraCapitol::cercaCapitols(string titol_serie, int numT) {
    try {
        ConnexioBD& db = ConnexioBD::getInstance();
        string query = "SELECT * FROM capitol WHERE titol_serie = '" + titol_serie + "' AND numero_temporada = '"
            + to_string(numT) + "'";

        sql::ResultSet* result = db.consulta(query);

        if (!result) {
            delete result;
            throw;
            // No hi ha continguts llavors...
        }

        vector<PassarelaCapitol> vpasCap;
        while (result->next()) {
            PassarelaCapitol pasCap(result);
            vpasCap.push_back(pasCap);
        }

        delete result; // Free memory after use
        return vpasCap;
    }
    catch (const sql::SQLException& e) {
        cerr << "MySQL error: " << e.what() << endl;
        throw;
    }
}

PassarelaCapitol CercadoraCapitol::cercaCapitol(string titol_serie, int numT, int numC) {
    try {
        ConnexioBD& db = ConnexioBD::getInstance();
        string query = "SELECT * FROM capitol WHERE titol_serie = '" + titol_serie + "' AND"
            " numero_temporada = '" + to_string(numT) + "' AND numero = '" + to_string(numC) + "'";

        sql::ResultSet* result = db.consulta(query);

        if (!result->next()) {
            delete result;
            throw;
            // No hi ha continguts llavors...
        }

        PassarelaCapitol pasCap(result);
        delete result; // Free memory after use
        return pasCap;
    }
    catch (const sql::SQLException& e) {
        cerr << "MySQL error: " << e.what() << endl;
        throw;
    }
}