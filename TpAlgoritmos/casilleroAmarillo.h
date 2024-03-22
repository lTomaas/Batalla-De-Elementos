//
// Created by tomas on 19/1/2021.
//

#ifndef TPALGORITMOS_CASILLEROAMARILLO_H
#define TPALGORITMOS_CASILLEROAMARILLO_H

#include "casillero.h"


class casilleroAmarillo : public Casillero{
private:

public:
    casilleroAmarillo(int fila, int columna);

    int obtenerPeso(Personaje* personaje);

    ~casilleroAmarillo();

};


#endif //TPALGORITMOS_CASILLEROAMARILLO_H
