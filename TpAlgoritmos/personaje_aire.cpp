//
// Created by patricio on 21/11/20.
//

#include "personaje_aire.h"


PersonajeAire::PersonajeAire(string nombre, string elemento, string alimento, float valorVida, int valorEnergia, int valorEscudo) : Personaje(nombre, elemento, alimento, valorVida, valorEnergia, valorEscudo){

}

void PersonajeAire::alimentarPersonaje() {
    cout << endl << nombre << " es de tipo AIRE y no requiere alimentarse" << endl;
}

void PersonajeAire::defenderse(){
    if(valorEnergia >= COSTO_ENERGIA_DEFENSA_AIRE) {
        valorEnergia = valorEnergia - COSTO_ENERGIA_DEFENSA_AIRE;
        cout << nombre << " utilizo OJO DE LA TORMENTA, reposicionandose en otro casillero" << endl;
    }
    else
        cout << nombre << " NO posee energia suficiente para defenderse!" << endl;
}

void PersonajeAire::recibirAtaque(Personaje* personaje) {
    string tipoElemento = personaje->obtenerElemento();
    float danioBloqueado = obtenerDanioRecibido();

    cout << nombre << " ha recibido un ataque de " << personaje->obtenerNombre() << " en la posicion: " << endl;
    cout << "Fila: " << fila + 1 << endl;
    cout << "Columna: " << columna + 1 << endl;

    if (tipoElemento == ELEMENTO_FUEGO) {
        this -> valorVida = valorVida - (ATAQUE_FUEGO_AIRE * danioBloqueado);
        cout << nombre << " fue gravemente herido por las llamas de " << personaje->obtenerNombre() << ", perdiendo "
             << ATAQUE_FUEGO_AIRE * danioBloqueado << " puntos de vida" << endl;
        cout << "Vida actual: " << valorVida << endl << endl;
    }
    else if (tipoElemento == ELEMENTO_AGUA) {
        this->valorVida = valorVida - (ATAQUE_AGUA_AIRE * danioBloqueado);
        cout << nombre << " ha sido impactado por el GEISER, perdiendo " << ATAQUE_AGUA_AIRE * danioBloqueado << " puntos de vida" << endl;
        cout << "Vida actual: " << valorVida << endl << endl;
    }
    else if (tipoElemento == ELEMENTO_TIERRA) {
        this -> valorVida = valorVida - (ATAQUE_TIERRA_AIRE * danioBloqueado);
        cout << nombre << " por su habilidad de poder levitar, fue ligeramente afectado por el TERREMOTO, perdiendo solo " << ATAQUE_TIERRA_AIRE * danioBloqueado << " puntos de vida" << endl;
        cout << "Vida actual: " << valorVida << endl << endl;
    }
    else{
        this->valorVida = valorVida - (ATAQUE_AIRE_AIRE * danioBloqueado);
        cout << nombre << " fue afectado por el TORNADO, perdiendo " << ATAQUE_AIRE_AIRE * danioBloqueado << " puntos de vida" << endl;
        cout << "Vida actual: " << valorVida << endl << endl;
    }

    if(valorVida <= VIDA_NULA)
        cout << nombre << " ha muerto!" << endl << endl;
}

PersonajeAire::~PersonajeAire(){

}