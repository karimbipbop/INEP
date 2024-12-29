#include "CercadoraCapitol.h"


CercadoraCapitol::CercadoraCapitol() {

}

PassarelaCapitol CercadoraCapitol::cercaCapitol(string titol_serie) {
    try {
        ConnexioBD& db = ConnexioBD::getInstance();
        string query = "SELECT * FROM capitol WHERE titol_serie = '" + titol_serie + "'";

        sql::ResultSet* result = db.consulta(query);

        if (!result) {
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