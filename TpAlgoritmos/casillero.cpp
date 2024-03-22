//
// Created by tomas on 17/1/2021.
//

#include "casillero.h"



Casillero::Casillero(int fila,int columna) {
    this -> ocupadoPor = "X";
    this -> ocupante = 0;
    this -> fila = fila;
    this -> columna = columna;
}

bool Casillero::estaOcupado() {
    if(ocupante != 0)
        return true;
    else
        return false;
}

dato Casillero::obtenerOcupante() {
    return ocupante;
}

Casillero::~Casillero() {

}


