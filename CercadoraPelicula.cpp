#include "CercadoraPelicula.h"


CercadoraPelicula::CercadoraPelicula() {

}

PassarelaPelicula CercadoraPelicula::cercaPelicula(string titol) {
    try {
        ConnexioBD& db = ConnexioBD::getInstance();
        string query = "SELECT * FROM pelicula WHERE titol = '" + titol + "'";

        sql::ResultSet* result = db.consulta(query);

        if (!result) {
            delete result;
            throw;
            // No hi ha continguts llavors...
        }
        PassarelaPelicula pasPel(result);

        delete result; // Free memory after use
        return pasPel;
    }
    catch (const sql::SQLException& e) {
        cerr << "MySQL error: " << e.what() << endl;
        throw;
    }
}