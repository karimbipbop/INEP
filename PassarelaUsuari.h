#include "ConnexioBD.h"

using namespace std;

const int SobrenomExisteix = 3;
const int CorreuExisteix = 4;

class PassarelaUsuari {
public:
    PassarelaUsuari(sql::ResultSet* result);
    PassarelaUsuari();
    PassarelaUsuari(string nomU, string sobrenomU, string contrasenyaU, string correuElectronicU, string dataNaixementU, string subscripcioU);
    void insereix();
    void modifica();
    void esborra();

    string obteContrasenya();
    string obteNom();
    string obteSobrenom();
    string obteCorreuElectronic();
    string obteDataNaixement();
    void posaContrasenya(string contraU);
    void posaNom(string nomU);
    void posaCorreuElectronic(string correuU);
    void posaDataNaixement(string neixU);

private:
    string nom, sobrenom, contrasenya, correuElectronic, dataNaixement, subscripcio;
};