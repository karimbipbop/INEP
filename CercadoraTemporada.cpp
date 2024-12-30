#include "CercadoraTemporada.h"


CercadoraTemporada::CercadoraTemporada() {

}

vector<PassarelaTemporada> CercadoraTemporada::cercaTemporades(string titol) {
    try {
        ConnexioBD& db = ConnexioBD::getInstance();
        string query = "SELECT * FROM temporada WHERE titol_serie = '" + titol + "'";

        sql::ResultSet* result = db.consulta(query);

        if (!result) {
            delete result;
            throw NoTrobat;
            // No hi ha continguts llavors...
        }
        vector<PassarelaTemporada> vPasTemp;
        while (result->next()) {
            PassarelaTemporada pasTemp(result);
            vPasTemp.push_back(pasTemp);
        }

        delete result; // Free memory after use
        return vPasTemp;
    }
    catch (const sql::SQLException& e) {
        throw e;
    }
}