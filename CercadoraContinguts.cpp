#include "CercadoraContinguts.h"


CercadoraContinguts::CercadoraContinguts() {

}

vector<PassarelaContingut> CercadoraContinguts::cercaContinguts() {
    try {
        ConnexioBD& db = ConnexioBD::getInstance();
        string query = "SELECT * FROM contingut";

        sql::ResultSet* result = db.consulta(query);

        if (!result) {
            delete result;
            throw;
            // No hi ha continguts llavors...
        }
        vector<PassarelaContingut> vpasCon;

        do {
            PassarelaContingut pasCon(result);
            vpasCon.push_back(pasCon);
        } while (result->next());

        delete result; // Free memory after use
        return vpasCon;
    }
    catch (const sql::SQLException& e) {
        cerr << "MySQL error: " << e.what() << endl;
        throw;
    }
}

vector<PassarelaContingut> CercadoraContinguts::cercaContingutsPerQualificacio(vector<string> qualificacions) {
    try {
        ConnexioBD& db = ConnexioBD::getInstance();
        string query = "SELECT * FROM contingut WHERE qualificacio IN (";

        int n = qualificacions.size();
        for (int i = 0; i < n; ++i) {
            query += "'" + qualificacions[i] + "'";
            if (i < n - 1) {
                query += ", ";
            }
        }

        query += ')';

        sql::ResultSet* result = db.consulta(query);

        if (!result) {
            delete result;
            throw;
            // No hi ha continguts llavors...
        }
        vector<PassarelaContingut> vpasCon;

        do {
            PassarelaContingut pasCon(result);
            vpasCon.push_back(pasCon);
        } while (result->next());

        delete result; // Free memory after use
        return vpasCon;
    }
    catch (const sql::SQLException& e) {
        cerr << "MySQL error: " << e.what() << endl;
        throw;
    }
}

vector<PassarelaContingut> CercadoraContinguts::cercaContingutsPerTipus(string tipus) {
    try {
        ConnexioBD& db = ConnexioBD::getInstance();
        string query = "SELECT * FROM contingut WHERE tipus = '" + tipus + "'";

        sql::ResultSet* result = db.consulta(query);

        if (!result) {
            delete result;
            throw;
            // No hi ha continguts llavors...
        }
        vector<PassarelaContingut> vpasCon;

        do {
            PassarelaContingut pasCon(result);
            vpasCon.push_back(pasCon);
        } while (result->next());

        delete result; // Free memory after use
        return vpasCon;
    }
    catch (const sql::SQLException& e) {
        cerr << "MySQL error: " << e.what() << endl;
        throw;
    }
}