#pragma once
#include <iostream>
#include <string>
#include "PetitFlix.h"
#include "CercadoraUsuari.h"
#include "CercadoraVisualitzaCap.h"
#include "CercadoraVisualitzaPel.h"
#include "CercadoraContinguts.h"
#include "CercadoraPelicula.h"
#include "CercadoraCapitol.h"
#include "CercadoraRelacionat.h"

using namespace std;

// Modifica la data que se li passa per canviar de DD/MM/YYYY a YYYY/MM/DD o al reves
static bool formatDate(std::string& inputDate) {
	vector<std::string> parts;
	string part;

	// Parse the input string and split it into parts
	for (char ch : inputDate) {
		if (ch == '/' || ch == '-') {
			parts.push_back(part);
			part.clear();
		}
		else if (ch == ' ')
			break;
		else {
			part += ch;
		}
	}
	parts.push_back(part); // Add the last part

	// Validate that we have exactly three parts
	if (parts.size() != 3) {
		return false;
	}

	// Modify the input string to the formatted YYYY-MM-DD
	inputDate = parts[2] + "/" + parts[1] + "/" + parts[0];
	return true;
}

static string today() {
	time_t t = std::time(nullptr);
	tm* localTime = std::localtime(&t);
	char buffer[11];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", localTime);
	string dataAvui = buffer;
	return dataAvui;
}

const int ErrorContrasenya = 2;
const int NoTancaSessio = 5;

class Transaccio {
public:
    Transaccio();
    virtual void executar() = 0;
    ~Transaccio();

protected:
    CercadoraUsuari cercUsu;
    CercadoraVisualitzaPel cercVisP;
    CercadoraVisualitzaCap cercVisC;
    CercadoraContinguts cercCont;
	CercadoraPelicula cercPel;
	CercadoraCapitol cercCap;
	CercadoraRelacionat cercRel;
    void inicialitza();

};