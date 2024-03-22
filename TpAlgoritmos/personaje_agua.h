//
// Created by patricio on 21/11/20.
//

#ifndef TPALGORITMOS_PERSONAJE_AGUA_H
#define TPALGORITMOS_PERSONAJE_AGUA_H

#include "personaje.h"

const int CANTIDAD_ALIMENTO = 3;

class PersonajeAgua : public Personaje {
private:
    int cantidadAlimento = CANTIDAD_ALIMENTO;
public:
    PersonajeAgua(string nombre, string elemento, string alimento, float valorVida, int valorEnergia, int valorEscudo);

    void alimentarPersonaje();

    void defenderse();

    void recibirAtaque(Personaje* personaje);

   ~PersonajeAgua();

private:
    bool puedeAlimentarse();

};


#endif //TPALGORITMOS_PERSONAJE_AGUA_H
