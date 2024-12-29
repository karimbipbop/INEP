#include "CercadoraVisualitzaPel.h"


CercadoraVisualitzaPel::CercadoraVisualitzaPel() {

}

vector<PassarelaVisualitzaPel> CercadoraVisualitzaPel::cercaVisualitzaPel(string sobrenom) {
    try {
        vector<PassarelaVisualitzaPel> visualitzacions;
        ConnexioBD& db = ConnexioBD::getInstance(); // Get the singleton instance
        string query = "SELECT * FROM visualitzacio_pelicula WHERE sobrenom_usuari = '" + sobrenom + "'";

        sql::ResultSet* result = db.consulta(query); // Execute query

        // Pass data to PassarelaUsuari (assuming PassarelaUsuari constructor accepts a ResultSet)
        while (result && result->next()) {
            PassarelaVisualitzaPel pasVis(result);
            visualitzacions.push_back(pasVis);
        }

        delete result; // Free memory after use
        return visualitzacions;
    }
    catch (const sql::SQLException& e) {
        cerr << "MySQL error: " << e.what() << endl;
        throw;
    }
}

PassarelaVisualitzaPel CercadoraVisualitzaPel::cercaVisualitzaPel(string sobrenom, string titol) {
    try {
        PassarelaVisualitzaPel visualitzacio;
        ConnexioBD& db = ConnexioBD::getInstance(); // Get the singleton instance
        string query = "SELECT * FROM visualitzacio_pelicula WHERE sobrenom_usuari = '" + sobrenom + "' AND titol_pelicula = "
                        + titol + "'";

        sql::ResultSet* result = db.consulta(query); // Execute query

        // Pass data to PassarelaUsuari (assuming PassarelaUsuari constructor accepts a ResultSet)
        PassarelaVisualitzaPel pasVis(result);

        delete result; // Free memory after use
        return visualitzacio;
    }
    catch (const sql::SQLException& e) {
        throw;
    }
}