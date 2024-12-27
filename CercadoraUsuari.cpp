#include "CercadoraUsuari.h"


CercadoraUsuari::CercadoraUsuari() {
    
}

PassarelaUsuari CercadoraUsuari::cercaUsuari(string sobrenomU) {
    try {
        ConnexioBD& db = ConnexioBD::getInstance(); // Get the singleton instance
        string query = "SELECT * FROM usuari WHERE sobrenom = '" + sobrenomU + "'";

        sql::ResultSet* result = db.consulta(query); // Execute query

        if (!result || !result->next()) { // Check if no rows were returned
            delete result; // Free memory
            throw(UsuariNoExisteix);
        }
        //cout << result->getString("contrasenya");
        // Pass data to PassarelaUsuari (assuming PassarelaUsuari constructor accepts a ResultSet)
        PassarelaUsuari pasUsu(result);

        delete result; // Free memory after use
        return pasUsu;
    }
    catch (const sql::SQLException& e) {
        cerr << "MySQL error: " << e.what() << endl;
        throw;
    }
}