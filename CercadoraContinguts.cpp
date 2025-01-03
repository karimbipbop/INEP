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
        throw e;
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
            throw NoTrobat;
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
        throw e;
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

        if (!result->next()) {
            delete result;
            throw NoTrobat;
            // No hi ha continguts llavors...
        }
        PassarelaContingut pasCon(result);

        delete result;
        return pasCon;
    }
    catch (const sql::SQLException& e) {
        cerr << "MySQL error: " << e.what() << endl;
        throw;
    }
}

vector<pair<string, int> > CercadoraContinguts::cercaPelicules() {
	try {
		ConnexioBD& db = ConnexioBD::getInstance();
		string query = "SELECT sobrenom_usuari, titol_pelicula, data, SUM(num_visualitzacions) AS total  FROM visualitzacio_pelicula  GROUP BY titol_pelicula  ORDER BY num_visualitzacions DESC  LIMIT 5";

		sql::ResultSet* result = db.consulta(query);

		if (!result) {
			delete result;
			throw;
		}
		vector<pair<string, int> > vpasCon;

		while (result->next()) {
			pair<string, int> aux = make_pair(result->getString("titol_pelicula"), result->getInt("total"));
			vpasCon.push_back(aux);
		}

		delete result;
		return vpasCon;
	}
	catch (const sql::SQLException& e) {
		cerr << "MySQL error: " << e.what() << endl;
		throw;
	}
}