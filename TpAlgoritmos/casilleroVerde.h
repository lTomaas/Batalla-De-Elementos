//
// Created by tomas on 19/1/2021.
//

#ifndef TPALGORITMOS_CASILLEROVERDE_H
#define TPALGORITMOS_CASILLEROVERDE_H

#include "casillero.h"


class casilleroVerde : public Casillero{
private:

public:
    casilleroVerde(int fila, int columna);

    int obtenerPeso(Personaje* personaje);

    ~casilleroVerde();



};


#endif //TPALGORITMOS_CASILLEROVERDE_H
