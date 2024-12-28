#include "CercadoraContinguts.h"


CercadoraContinguts::CercadoraContinguts() {

}

vector<pair<string, string>> CercadoraContinguts::cercaContinguts() {
    try {
        ConnexioBD& db = ConnexioBD::getInstance();
        string query = "SELECT * FROM contingut";

        sql::ResultSet* result = db.consulta(query);

        if (!result) {
            delete result;
            throw;
            // No hi ha continguts llavors...
        }
        vector<pair<string, string>> vpasCon;
        
        do {
            PassarelaContingut pasCon(result);
            pair<string, string> p = make_pair(pasCon.obteTitol(), pasCon.obteTipus());
            vpasCon.push_back(p);
        } while (result->next());

        delete result; // Free memory after use
        return vpasCon;
    }
    catch (const sql::SQLException& e) {
        cerr << "MySQL error: " << e.what() << endl;
        throw;
    }
}