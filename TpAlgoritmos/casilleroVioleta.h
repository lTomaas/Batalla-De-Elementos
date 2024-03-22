//
// Created by tomas on 19/1/2021.
//

#ifndef TPALGORITMOS_CASILLEROVIOLETA_H
#define TPALGORITMOS_CASILLEROVIOLETA_H

#include "casillero.h"


class casilleroVioleta : public Casillero{
private:

public:
    casilleroVioleta(int fila, int columna);

    int obtenerPeso(Personaje* personaje);

    ~casilleroVioleta();

};


#endif //TPALGORITMOS_CASILLEROVIOLETA_H
