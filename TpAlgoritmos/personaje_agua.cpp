//
// Created by patricio on 21/11/20.
//

#include "personaje_agua.h"

PersonajeAgua::PersonajeAgua(string nombre, string elemento, string alimento, float valorVida, int valorEnergia, int valorEscudo) : Personaje(nombre, elemento, alimento, valorVida, valorEnergia, valorEscudo){

}

void PersonajeAgua::alimentarPersonaje() {
    if(puedeAlimentarse()) {
        cout << endl << nombre << " se ha alimentado con " << alimento << " y ha recuperado " << ENERGIA_RECUPERADA_AGUA << " puntos de energia" << endl;
        cantidadAlimento--;
        cout << nombre << " puede alimentarse solo " << cantidadAlimento << " veces mas" << endl;
        if(valorEnergia + ENERGIA_RECUPERADA_AGUA < ENERGIA_MAXIMA)
            this->valorEnergia = valorEnergia + ENERGIA_RECUPERADA_AGUA;
        else
            this->valorEnergia = ENERGIA_MAXIMA;
        cout << "Energia actual: " << valorEnergia << "/" << ENERGIA_MAXIMA << endl;
    }
    else
        cout << endl << nombre << " ya comio demasiado plancton!" << endl;
}

bool PersonajeAgua::puedeAlimentarse() {
    return(cantidadAlimento > 0);
}

void PersonajeAgua::defenderse() {
    int vidaActual;
    if(this -> valorEnergia >= COSTO_ENERGIA_DEFENSA_AGUA){
        valorEnergia = valorEnergia - COSTO_ENERGIA_DEFENSA_AGUA;
        if(valorVida + VIDA_RECUPERADA_AGUA > VIDA_MAXIMA)
            valorVida = VIDA_MAXIMA;
        else
            valorVida = valorVida + VIDA_RECUPERADA_AGUA;
        cout << endl << nombre << " utilizo TSUNAMI, recuperando " << VIDA_RECUPERADA_AGUA << " puntos de vida y curando a sus aliados " << VIDA_RECUPERADA_ALIADOS_AGUA << " puntos de vida" << endl;
        cout << "Vida Actual: " << valorVida << "/" << VIDA_MAXIMA << endl;
    }
    else{
        cout << endl << nombre << " NO tiene energia suficiente para defenderse " << endl;
        cout << "Energia Actual: " << valorEnergia << endl;
        cout << "Costo de energia para defenderse: " << COSTO_ENERGIA_DEFENSA_AGUA;
    }

}

void PersonajeAgua::recibirAtaque(Personaje* personaje){
    string tipoElemento = personaje -> obtenerElemento();
    float danioBloqueado = obtenerDanioRecibido();

    cout << nombre << " ha recibido un ataque de " << personaje -> obtenerNombre() << " en la posicion: " << endl;
    cout << "Fila: " << fila + 1 << endl;
    cout << "Columna: " << columna + 1 << endl;

    if(tipoElemento == ELEMENTO_TIERRA) {
        this -> valorVida = valorVida - (ATAQUE_TIERRA_AGUA * danioBloqueado);
        cout << nombre << " ha recibido " << ATAQUE_TIERRA_AGUA * danioBloqueado << " puntos de danio extra por ser de tipo AGUA, debil contra tierra" << endl;
    }
    else if(tipoElemento == ELEMENTO_AIRE) {
        this -> valorVida = valorVida - (ATAQUE_AIRE_AGUA * danioBloqueado);
        cout << nombre << " fue afectado por el TORNADO, perdiendo " << ATAQUE_AIRE_AGUA * danioBloqueado << " puntos de vida" << endl;
        cout << "Vida actual: " << valorVida << endl << endl;
    }
    else if(tipoElemento == ELEMENTO_FUEGO){
        this -> valorVida = valorVida - (ATAQUE_FUEGO_AGUA * danioBloqueado);
        cout << nombre << " ha logrado apagar las llamas de " << personaje -> obtenerNombre() << " recibiendo solo " << ATAQUE_FUEGO_AGUA * danioBloqueado << " puntos de danio" << endl;
        cout << "Vida actual: " << valorVida << endl << endl;
    }
    else {
        this -> valorVida = valorVida - (ATAQUE_AGUA_AGUA * danioBloqueado);
        cout << nombre << " ha sido impactado por el GEISER, perdiendo " << ATAQUE_AGUA_AGUA * danioBloqueado << " puntos de vida" << endl;
        cout << "Vida actual: " << valorVida << endl << endl;
    }
    if(valorVida <= VIDA_NULA)
        cout << nombre << " ha muerto!" << endl << endl;
}

PersonajeAgua::~PersonajeAgua(){

}

