//
// Created by tomas on 2/2/2021.
//

#ifndef TPALGORITMOS_VERTICE_H
#define TPALGORITMOS_VERTICE_H

#include "casillero.h"
#include "personaje.h"


class arista;


class vertice {
public:
    vertice *sig;
    arista *adyacente;
    Casillero* casillero;
    Personaje* ocupante;
    int numeroVertice;
    int fila;
    int columna;
    string ocupadoPor;

    vertice();

    //PRE: El casillero no esta ocupado por otro personaje
    //POS: Se le asigna un personaje ocupante y jugador ocupante al vertice
    void ubicarPersonaje(Personaje* personaje, string jugador);

    //PRE:
    //POS: Se quita al ocupante del vertice (si lo hubiera) y se lo deja vacio
    void reestablecerOcupante();

    //PRE:
    //POS: Devuelve true si el casillero esta ocupado, sino false
    bool estaOcupado();

    //PRE:
    //POS: Devuelve el numero de jugador que lo ocupa
    string obtenerJugadorOcupante();
};

class arista {
public:
    arista *sig;
    vertice *adyacente;
};


#endif //TPALGORITMOS_VERTICE_H
