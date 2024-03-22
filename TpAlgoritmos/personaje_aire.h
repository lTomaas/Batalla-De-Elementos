//
// Created by patricio on 21/11/20.
//

#ifndef TPALGORITMOS_PERSONAJE_AIRE_H
#define TPALGORITMOS_PERSONAJE_AIRE_H

#include "personaje.h"

class PersonajeAire : public Personaje{
private:

public:
    PersonajeAire(string nombre, string elemento, string alimento, float valorVida, int valorEnergia, int valorEscudo);

    void alimentarPersonaje();

    void defenderse();

    void recibirAtaque(Personaje* personaje);

    ~PersonajeAire();


};


#endif //TPALGORITMOS_PERSONAJE_AIRE_H
