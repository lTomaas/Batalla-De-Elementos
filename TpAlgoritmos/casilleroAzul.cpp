//
// Created by tomas on 19/1/2021.
//

#include "casilleroAzul.h"

casilleroAzul::casilleroAzul(int fila, int columna) : Casillero(fila, columna) {

}

int casilleroAzul::obtenerPeso(Personaje* personaje) {
    if (personaje->obtenerElemento() == "Agua")
        return 0;
    else if (personaje->obtenerElemento() == "Fuego")
        return 2;
    else
        return 1;
}

casilleroAzul::~casilleroAzul(){

}
