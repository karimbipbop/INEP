#include "TxRegistraUsuari.h"

TxRegistraUsuari::TxRegistraUsuari() {
    inicialitza();
}

TxRegistraUsuari::TxRegistraUsuari(Usuari u) {
    inicialitza();
    usuari = u;
}

void TxRegistraUsuari::executar() {
    PassarelaUsuari u(usuari.nom, usuari.sobrenom, usuari.contrassenya, usuari.correuElectronic, usuari.dataNaixament, usuari.subscripcio);
    try {
        u.insereix();
    }
    catch (sql::SQLException& e) {
        //error en el format d'inserció
        throw(e);
    }
}