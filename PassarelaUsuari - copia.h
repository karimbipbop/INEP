#pragma once
#include "ConnexioBD.h"
#include "DTOs.h"

const int SobrenomExisteix = 3;
const int CorreuExisteix = 4;

class PassarelaUsuari {
private:
    string nom, sobrenom, contrasenya, correuElectronic, dataNaixement, subscripcio;

public:
    PassarelaUsuari();
    PassarelaUsuari(sql::ResultSet* result);
    PassarelaUsuari(string nomU, string sobrenomU, string contrasenyaU, string correuElectronicU, string dataNaixementU, string subscripcioU);
    void insereix();
    void modifica();
    void esborra();
 
    string obteNom();
    string obteSobrenom();
    string obteContrasenya();
    string obteCorreuElectronic();
    string obteDataNaixement();
    string obteSubscripcio();
    void posaNom(string nomU);
    void posaContrasenya(string contraU);
    void posaCorreuElectronic(string correuU);
    void posaDataNaixement(string neixU);
    void posaSubscripcio(string subscripcioU);
};
