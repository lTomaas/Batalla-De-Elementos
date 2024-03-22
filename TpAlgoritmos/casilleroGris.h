//
// Created by tomas on 18/1/2021.
//

#ifndef TPALGORITMOS_CASILLEROGRIS_H
#define TPALGORITMOS_CASILLEROGRIS_H

#include "casillero.h"


class casilleroGris : public Casillero {
private:

public:
    casilleroGris(int fila, int columna);

    int obtenerPeso(Personaje* personaje);

    ~casilleroGris();








    void nose();

};


#endif //TPALGORITMOS_CASILLEROGRIS_H
