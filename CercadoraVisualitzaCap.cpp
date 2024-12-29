#include "CercadoraVisualitzaCap.h"


CercadoraVisualitzaCap::CercadoraVisualitzaCap() {

}

vector<PassarelaVisualitzaCap> CercadoraVisualitzaCap::cercaVisualitzaCap(string sobrenom) {
    try {
        vector<PassarelaVisualitzaCap> visualitzacions;
        ConnexioBD& db = ConnexioBD::getInstance(); // Get the singleton instance
        string query = "SELECT * FROM visualitzacio_capitol WHERE sobrenom_usuari = '" + sobrenom + "'";

        sql::ResultSet* result = db.consulta(query); // Execute query

        // Pass data to PassarelaUsuari (assuming PassarelaUsuari constructor accepts a ResultSet)
        while (result && result->next()) {
            PassarelaVisualitzaCap pasCap(result);
            visualitzacions.push_back(pasCap);
        }
        delete result; // Free memory after use
        return visualitzacions;
    }
    catch (const sql::SQLException& e) {
        cerr << "MySQL error: " << e.what() << endl;
        throw;
    }
}

PassarelaVisualitzaCap CercadoraVisualitzaCap::cercaVisualitzaCap(string sobrenom, string titol_serie, int num_temporada, int num_capitol) {
    try {
        ConnexioBD& db = ConnexioBD::getInstance(); // Get the singleton instance
        string query = "SELECT * FROM visualitzacio_capitol WHERE sobrenom_usuari = '" + sobrenom +
            "' AND titol_serie = '" + titol_serie + "' AND num_temporada = '" + to_string(num_temporada) +
            "' AND num_capitol = '" + to_string(num_capitol) + "'";

        sql::ResultSet* result = db.consulta(query); // Execute query

        // Pass data to PassarelaUsuari (assuming PassarelaUsuari constructor accepts a ResultSet)
        if (result->next()) {
            PassarelaVisualitzaCap pasCap(result);
            delete result; // Free memory after use
            return pasCap;
        }
    }
    catch (const sql::SQLException& e) {
        cerr << "MySQL error: " << e.what() << endl;
        throw;
    }
}