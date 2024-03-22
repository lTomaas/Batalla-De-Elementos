//
// Created by tomas on 17/1/2021.
//

#ifndef TPALGORITMOS_CASILLERO_H
#define TPALGORITMOS_CASILLERO_H

#include <iostream>
#include "ABB.h"
#include "casillero.h"

using namespace std;

class Casillero {
protected:
    string ocupadoPor;
    dato ocupante;
    int fila;
    int columna;
public:
    Casillero(int fila, int columna);

    //PRE:
    //POS: Devuelve true si hay un personaje en ese casillero, sino false
    bool estaOcupado();

    //PRE: el casillero esta ocupado por un personaje
    //POS: Devuelve el personaje que ocupa el casillero
    dato obtenerOcupante();

    ~Casillero();

    //PRE:
    //POS: Devuelve el costo de energia de pasar por ese casillero para el personaje
    virtual int obtenerPeso(Personaje* personaje) = 0;

};


#endif //TPALGORITMOS_CASILLERO_H
