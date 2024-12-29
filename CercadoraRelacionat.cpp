#include "CercadoraRelacionat.h"


CercadoraRelacionat::CercadoraRelacionat() {

}

vector<PassarelaRelacionat> CercadoraRelacionat::cercaRelacionats(string titol) {
    try {
        ConnexioBD& db = ConnexioBD::getInstance();
        string query = "SELECT * FROM relacionat WHERE titol_x = '" + titol + "' OR"
            " titol_y = '" + titol + "'";
        sql::ResultSet* result = db.consulta(query);

        if (!result) {
            delete result;
            throw;
            // No hi ha continguts llavors...
        }

        vector<PassarelaRelacionat> vpasRel;
        while (result && result->next()) {
            PassarelaRelacionat pasRel(result);
            vpasRel.push_back(pasRel);
        }

        delete result; // Free memory after use
        return vpasRel;
    }
    catch (const sql::SQLException& e) {
        cerr << "MySQL error: " << e.what() << endl;
        throw;
    }
}