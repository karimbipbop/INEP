#include "TxRegistraUsuari.h"

TxRegistraUsuari::TxRegistraUsuari() {
    inicialitza();
}

TxRegistraUsuari::TxRegistraUsuari(string nU, string sU, string cU, string ceU, string dnU, string subU) {
    inicialitza();
    usuari.nom = nU;
    usuari.sobrenom = sU;
    usuari.contrassenya = cU;
    usuari.correuElectronic = ceU;
    usuari.dataNaixament = dnU;
    usuari.subscripcio = subU;
}

void TxRegistraUsuari::executar() {
    PassarelaUsuari u(usuari.nom, usuari.sobrenom, usuari.contrassenya, usuari.correuElectronic, usuari.dataNaixament, usuari.subscripcio);
    u.insereix();
}