//
// Created by tomas on 19/1/2021.
//

#include "casilleroRojo.h"


casilleroRojo::casilleroRojo(int fila, int columna) : Casillero(fila, columna){

}

int casilleroRojo::obtenerPeso(Personaje *personaje) {
    if (personaje->obtenerElemento() == "Fuego")
        return 0;
    else if (personaje->obtenerElemento() == "Agua")
        return 2;
    else
        return 1;
}

casilleroRojo::~casilleroRojo(){

}
