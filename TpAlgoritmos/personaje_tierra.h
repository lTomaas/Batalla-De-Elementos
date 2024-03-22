//
// Created by patricio on 21/11/20.
//

#ifndef TPALGORITMOS_PERSONAJE_TIERRA_H
#define TPALGORITMOS_PERSONAJE_TIERRA_H

#include "personaje.h"


class PersonajeTierra : public Personaje{
private:

public:
    PersonajeTierra(string nombre, string elemento, string alimento, float valorVida, int valorEnergia, int valorEscudo);

    void alimentarPersonaje();

    void defenderse();

    void recibirAtaque(Personaje* personaje);

    ~PersonajeTierra();

};


#endif //TPALGORITMOS_PERSONAJE_TIERRA_H
