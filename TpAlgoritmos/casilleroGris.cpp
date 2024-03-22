//
// Created by tomas on 18/1/2021.
//

#include "casilleroGris.h"

casilleroGris::casilleroGris(int fila, int columna) : Casillero(fila, columna){
}

int casilleroGris::obtenerPeso(Personaje *personaje) {
    if (personaje->obtenerElemento() == "Aire")
        return 0;
    else if (personaje->obtenerElemento() == "Tierra")
        return 2;
    else
        return 1;
}


casilleroGris::~casilleroGris(){

}

