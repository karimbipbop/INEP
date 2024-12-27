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
    u.insereix();
}