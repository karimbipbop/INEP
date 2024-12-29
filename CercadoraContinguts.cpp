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
            return {};
            // No hi ha continguts llavors...
        }
        vector<PassarelaContingut> vpasCon;
        while (result->next()) {
            PassarelaContingut pasCon(result);
            vpasCon.push_back(pasCon);
        }

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

        while (result->next()) {
            PassarelaContingut pasCon(result);
            vpasCon.push_back(pasCon);
        }

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

        while (result->next()) {
            PassarelaContingut pasCon(result);
            vpasCon.push_back(pasCon);
        }

        delete result; // Free memory after use
        return vpasCon;
    }
    catch (const sql::SQLException& e) {
        cerr << "MySQL error: " << e.what() << endl;
        throw;
    }
}

PassarelaContingut CercadoraContinguts::cercaContingutPerTitol(string titol) {
    try {
        ConnexioBD& db = ConnexioBD::getInstance();
        string query = "SELECT * FROM contingut WHERE titol = '" + titol + "'";

        sql::ResultSet* result = db.consulta(query);

        if (!result) {
            delete result;
            throw;
            // No hi ha continguts llavors...
        }
        PassarelaContingut pasCon(result);

        delete result; // Free memory after use
        return pasCon;
    }
    catch (const sql::SQLException& e) {
        cerr << "MySQL error: " << e.what() << endl;
        throw;
    }
}