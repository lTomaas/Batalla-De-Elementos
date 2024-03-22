//
// Created by tomas on 19/1/2021.
//

#include "casilleroVioleta.h"


casilleroVioleta::casilleroVioleta(int fila, int columna) : Casillero(fila, columna){

}

int casilleroVioleta::obtenerPeso(Personaje* personaje) {
    return 15;
}

casilleroVioleta::~casilleroVioleta(){

}