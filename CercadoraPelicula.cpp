#include "CercadoraPelicula.h"


CercadoraPelicula::CercadoraPelicula() {

}

PassarelaPelicula CercadoraPelicula::cercaPelicula(string titol) {
    try {
        ConnexioBD& db = ConnexioBD::getInstance();
        string query = "SELECT * FROM pelicula WHERE titol = '" + titol + "'";

        sql::ResultSet* result = db.consulta(query);

        if (result->next()) {
            PassarelaPelicula pasPel(result);
            delete result; // Free memory after use
            return pasPel;
        }
        else {
            delete result;
            throw NoTrobat;
        }
    }
    catch (const sql::SQLException& e) {
        throw e;
    }
}