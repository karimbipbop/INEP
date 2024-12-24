#include "ConnexioBD.h"

class PassarelaQualificacioEdat {
private:
    string nom;

public:
    PassarelaQualificacioEdat();
    PassarelaQualificacioEdat(sql::ResultSet* result);
    PassarelaQualificacioEdat(string nomQ);
    void insereix();
    void modifica();
    void esborra();

    string obteNom();
};