//
// Created by tomas on 2/2/2021.
//

#include "vertice.h"


vertice::vertice(){
    this -> ocupadoPor = "X";
    this -> ocupante = 0;
}

void vertice::ubicarPersonaje(Personaje* personaje, string jugador) {
    this -> ocupante = personaje;
    this -> ocupadoPor = jugador;
}

void vertice::reestablecerOcupante(){
    this -> ocupante = 0;
    this -> ocupadoPor = "X";
}

bool vertice::estaOcupado() {
    if(ocupante == 0)
        return false;
    else
        return true;
}

string vertice::obtenerJugadorOcupante(){
    return ocupadoPor;
}