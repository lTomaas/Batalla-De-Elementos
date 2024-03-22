//
// Created by tomas on 19/1/2021.
//

#ifndef TPALGORITMOS_CASILLEROAZUL_H
#define TPALGORITMOS_CASILLEROAZUL_H

#include "casillero.h"



class casilleroAzul : public Casillero {
private:

public:
    casilleroAzul(int fila, int columna);

    int obtenerPeso(Personaje* personaje);

    ~casilleroAzul();

};


#endif //TPALGORITMOS_CASILLEROAZUL_H
