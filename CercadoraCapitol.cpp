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