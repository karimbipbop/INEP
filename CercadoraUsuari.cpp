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
            throw(UsuariNoExisteix);
        }

        PassarelaUsuari pasUsu(result);

        delete result; // Free memory after use
        return pasUsu;
    }
    catch (const sql::SQLException& e) {
        cerr << "MySQL error: " << e.what() << endl;
        throw;
    }
}