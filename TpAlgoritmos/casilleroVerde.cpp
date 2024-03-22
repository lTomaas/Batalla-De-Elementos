//
// Created by tomas on 19/1/2021.
//

#include "casilleroVerde.h"


casilleroVerde::casilleroVerde(int fila, int columna) : Casillero(fila, columna){

}

int casilleroVerde::obtenerPeso(Personaje *personaje) {
    if (personaje->obtenerElemento() == "Tierra")
        return 0;
    else if (personaje->obtenerElemento() == "Aire")
        return 2;
    else
        return 1;
}

casilleroVerde::~casilleroVerde(){

}
