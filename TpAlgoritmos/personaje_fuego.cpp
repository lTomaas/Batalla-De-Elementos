//
// Created by patricio on 21/11/20.
//

#include "personaje_fuego.h"

PersonajeFuego::PersonajeFuego(string nombre, string elemento, string alimento, float valorVida, int valorEnergia, int valorEscudo) : Personaje(nombre, elemento, alimento, valorVida, valorEnergia, valorEscudo){

}

void PersonajeFuego::alimentarPersonaje() {
    cout << endl << nombre << " se ha alimentado con " << alimento << " y ha recuperado " << VIDA_RECUPERADA_FUEGO << " puntos de VIDA y " << ENERGIA_RECUPERADA_FUEGO << " puntos de ENERGIA" << endl;
    if(valorVida + VIDA_RECUPERADA_FUEGO < VIDA_MAXIMA)
        this->valorVida = valorVida + VIDA_RECUPERADA_FUEGO;
    else
        this->valorVida = VIDA_MAXIMA;
    cout << "Vida actual: " << valorVida << "/" << VIDA_MAXIMA << endl;
    if(valorEnergia + ENERGIA_RECUPERADA_FUEGO < ENERGIA_MAXIMA)
        this -> valorEnergia = valorEnergia + ENERGIA_RECUPERADA_FUEGO;
    else
        this -> valorEnergia = ENERGIA_MAXIMA;
    cout << "Energia actual: " << valorEnergia << "/" << ENERGIA_MAXIMA << endl;


}
void PersonajeFuego::defenderse() {
    if(valorEnergia >= COSTO_ENERGIA_DEFENSA_FUEGO){
        this -> valorEnergia = valorEnergia - COSTO_ENERGIA_DEFENSA_FUEGO;
        if(valorVida + VIDA_RECUPERADA_FUEGO > VIDA_MAXIMA)
            this -> valorVida = VIDA_MAXIMA;
        else
            this -> valorVida = valorVida + VIDA_RECUPERADA_FUEGO;
        cout << endl << nombre << " utilizo INCENDIO para recuperar " << VIDA_RECUPERADA_FUEGO << " puntos de vida" << endl;
        cout << "Vida Actual: " << valorVida << "/" << VIDA_MAXIMA << endl;
    }
    else
        cout << endl << nombre << " NO posee energia suficiente para defenderse!" << endl;
}

void PersonajeFuego::recibirAtaque(Personaje* personaje){
    string tipoElemento = personaje -> obtenerElemento();
    float danioBloqueado = obtenerDanioRecibido();

    cout << nombre << " ha recibido un ataque de " << personaje -> obtenerNombre() << " en la posicion: " << endl;
    cout << "Fila: " << fila + 1 << endl;
    cout << "Columna: " << columna + 1 << endl;

    if(tipoElemento == ELEMENTO_AGUA) {
        this->valorVida = valorVida - (ATAQUE_AGUA_FUEGO * danioBloqueado);
        cout << nombre << " fue gravemente afectado por el GEISER de " << personaje->obtenerNombre() << ", perdiendo " << ATAQUE_AGUA_FUEGO * danioBloqueado << " puntos de vida" << endl;
        cout << "Vida actual: " << valorVida << endl << endl;
    }
    else if(tipoElemento == ELEMENTO_AIRE ){
        this -> valorVida = valorVida - (ATAQUE_AIRE_FUEGO * danioBloqueado);
        cout << nombre << " ha logrado disipar los vientos del TORNADO, recibiendo solo " << ATAQUE_AIRE_FUEGO * danioBloqueado << " puntos de danio" << endl;
        cout << "Vida actual: " << valorVida << endl << endl;
    }
    else if(tipoElemento == ELEMENTO_FUEGO) {
        this -> valorVida = valorVida - (ATAQUE_FUEGO_FUEGO * danioBloqueado);
        cout << nombre << " no pudo soportar las llamas de " << personaje -> obtenerNombre() << ", perdiendo " << ATAQUE_FUEGO_FUEGO * danioBloqueado << " puntos de vida" << endl;
        cout << "Vida actual: " << valorVida << endl << endl;
    }
    if(this -> valorVida <= VIDA_NULA)
        cout << nombre << " ha muerto!" << endl << endl;
}

PersonajeFuego::~PersonajeFuego(){

}