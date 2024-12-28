#pragma once
#include "PassarelaUsuari.h"

PassarelaUsuari::PassarelaUsuari()
{
    nom = "";
    sobrenom = "";
    contrasenya = "";
    correuElectronic = "";
    dataNaixement = "";
    subscripcio = "";
}

PassarelaUsuari::PassarelaUsuari(sql::ResultSet* result)
{
    sobrenom = result->getString("sobrenom");
    nom = result->getString("nom");
    contrasenya = result->getString("contrasenya");
    correuElectronic = result->getString("correu_electronic");
    dataNaixement = result->getString("data_naixement");
    subscripcio = result->getString("subscripcio");
}


PassarelaUsuari::PassarelaUsuari(string nomU, string sobrenomU, string contrasenyaU, string correuElectronicU, string dataNaixementU, string subscripcioU)
{
    nom = nomU;
    sobrenom = sobrenomU;
    contrasenya = contrasenyaU;
    correuElectronic = correuElectronicU;
    dataNaixement = dataNaixementU;
    subscripcio = subscripcioU;
}

void PassarelaUsuari::insereix()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        string query = "INSERT INTO usuari VALUES ('" + 
                            sobrenom + "', '" + 
                            nom + "', '" + 
                            contrasenya + "', '" + 
                            correuElectronic + "', '" + 
                            dataNaixement + "', '" + subscripcio +"')";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
        throw(e);
	}
}

void PassarelaUsuari::modifica()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        string query = "UPDATE usuari SET "
                        "nom = '" + nom + "', "
                        "contrasenya = '" + contrasenya + "', "
                        "correu_electronic = '" + correuElectronic + "', "
                        "data_naixement = '" + dataNaixement + "' "
                        "WHERE sobrenom = '" + sobrenom + "'";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
		cerr << "SQL Error: " << e.what() << endl;
	}
}

void PassarelaUsuari::esborra()
{
    try {
        ConnexioBD& c = ConnexioBD::getInstance();
        string query = "DELETE FROM usuari WHERE sobrenom = '" + sobrenom + "'";
        c.execucio(query);
    }
    catch (sql::SQLException& e) {
		cerr << "SQL Error: " << e.what() << std::endl;
	}
}

string PassarelaUsuari::obteContrasenya()
{
    return contrasenya;
}


string PassarelaUsuari::obteNom()
{
    return nom;
}

string PassarelaUsuari::obteSobrenom()
{
    return sobrenom;
}

string PassarelaUsuari::obteCorreuElectronic()
{
    return correuElectronic;
}

string PassarelaUsuari::obteDataNaixement()
{
    return dataNaixement;
}

string PassarelaUsuari::obteSubscripcio()
{
    return subscripcio;
}

void PassarelaUsuari::posaNom(string nomU)
{
    nom = nomU;

}

void PassarelaUsuari::posaContrasenya(string contrasenyaU)
{
    contrasenya = contrasenyaU;
}

void PassarelaUsuari::posaCorreuElectronic(string correuU)
{
    correuElectronic = correuU;

}

void PassarelaUsuari::posaDataNaixement(string neixU)
{
    dataNaixement = neixU;
}

void PassarelaUsuari::posaSubscripcio(string subscripcioU)
{
    subscripcio = subscripcioU;
}