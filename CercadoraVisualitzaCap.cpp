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