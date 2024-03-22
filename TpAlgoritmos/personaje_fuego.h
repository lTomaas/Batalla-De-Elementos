//
// Created by patricio on 21/11/20.
//

#ifndef TPALGORITMOS_PERSONAJE_FUEGO_H
#define TPALGORITMOS_PERSONAJE_FUEGO_H

#include "personaje.h"



class PersonajeFuego : public Personaje {
private:

public:
    PersonajeFuego(string nombre, string elemento, string alimento, float valorVida, int valorEnergia, int valorEscudo);

    void alimentarPersonaje();

    void defenderse();

    void recibirAtaque(Personaje* personaje);

    ~PersonajeFuego();

};


#endif //TPALGORITMOS_PERSONAJE_FUEGO_H
