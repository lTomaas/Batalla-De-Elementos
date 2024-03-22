//
// Created by tomas on 19/1/2021.
//

#ifndef TPALGORITMOS_CASILLEROROJO_H
#define TPALGORITMOS_CASILLEROROJO_H

#include "casillero.h"


class casilleroRojo : public Casillero{
private:

public:
    casilleroRojo(int fila, int columna);

    int obtenerPeso(Personaje* personaje);

    ~casilleroRojo();

};


#endif //TPALGORITMOS_CASILLEROROJO_H
