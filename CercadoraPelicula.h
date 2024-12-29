#pragma once
#include <iostream>
#include <string>
#include "PassarelaPelicula.h"
#include "ConnexioBD.h"

using namespace std;

class CercadoraPelicula {
public:
    CercadoraPelicula();
    PassarelaPelicula cercaPelicula(string titol);
};