#include "TxTancaSessio.h"

TxTancaSessio::TxTancaSessio() {
	inicialitza();
}

void TxTancaSessio::executar() {
	PetitFlix& pf = pf.getInstance();
	pf.tancaSessio();
}