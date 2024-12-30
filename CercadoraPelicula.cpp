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
            throw NoTrobat;
            // No hi ha continguts llavors...
        }
        if (result->next()) {
            PassarelaPelicula pasPel(result);
            delete result; // Free memory after use
            return pasPel;
        }
    }
    catch (const sql::SQLException& e) {
        throw e;
    }
}