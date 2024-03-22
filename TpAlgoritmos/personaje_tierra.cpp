//
// Created by patricio on 21/11/20.
//

#include "personaje_tierra.h"


PersonajeTierra::PersonajeTierra(string nombre, string elemento, string alimento, float valorVida, int valorEnergia, int valorEscudo) : Personaje(nombre, elemento, alimento, valorVida, valorEnergia, valorEscudo){

}

void PersonajeTierra::alimentarPersonaje() {
    cout << endl << nombre << " se ha alimentado con " << alimento << " y ha recuperado " << ENERGIA_RECUPERADA_TIERRA << " puntos de energia" << endl;
    if(valorEnergia + ENERGIA_RECUPERADA_TIERRA < ENERGIA_MAXIMA)
        this -> valorEnergia = valorEnergia + ENERGIA_RECUPERADA_TIERRA;
    else
        this->valorEnergia = ENERGIA_MAXIMA;
    cout << "Energia actual: " << valorEnergia << "/" << ENERGIA_MAXIMA << endl;
}

PersonajeTierra::~PersonajeTierra(){

}

void PersonajeTierra::defenderse(){
    if(valorEnergia >= COSTO_ENERGIA_DEFENSA_TIERRA) {
        cambiarEstadoDefensa(VERDADERO);
        this -> valorEnergia = valorEnergia - COSTO_ENERGIA_DEFENSA_TIERRA;
        this -> valorEscudo = valorEscudo + ESCUDO_OBTENIDO_TIERRA;
        if(valorEscudo > ESCUDO_MAXIMO)
            cout << endl << nombre << " ha obtenido la habilidad DUREZA, que le otorga una reduccion de 80% del danio recibido por 1 TURNO" << endl;
    }
    else
        cout << "Energia insuficiente, energia necesaria para defenderse: " << COSTO_ENERGIA_DEFENSA_TIERRA;
}

void PersonajeTierra::recibirAtaque(Personaje* personaje){
    string tipoElemento = personaje -> obtenerElemento();
    float danioBloqueado = obtenerDanioRecibido();

    cout << nombre << " ha recibido un ataque de " << personaje -> obtenerNombre() << " en la posicion: " << endl;
    cout << "Fila: " << fila + 1 << endl;
    cout << "Columna: " << columna + 1 << endl;

    if(tipoElemento == ELEMENTO_AGUA) {
        this->valorVida = valorVida - (ATAQUE_AGUA_TIERRA * danioBloqueado);
        cout << nombre << " por su dureza logro resistir el impacto del GEISER, perdiendo solo " << ATAQUE_AGUA_TIERRA * danioBloqueado << " puntos de vida" << endl;
        cout << "Vida actual: " << valorVida << endl << endl;

    }
    else if(tipoElemento == ELEMENTO_FUEGO) {
        this -> valorVida = valorVida - (ATAQUE_FUEGO_TIERRA * danioBloqueado);
        cout << nombre << " ha sido afectado por las LLAMAS de " << personaje -> obtenerNombre() << " perdiendo " << ATAQUE_FUEGO_TIERRA * danioBloqueado << " puntos de vida" << endl;
        cout << "Vida actual: " << valorVida << endl << endl;
    }
    else {
        this->valorVida = valorVida - (ATAQUE_AIRE_TIERRA * danioBloqueado);
        cout << nombre << " fue erosionado por el tornado desatado por " << personaje -> obtenerNombre() << ", resultando gravemente herido y perdiendo " << ATAQUE_AIRE_TIERRA * danioBloqueado<< " puntos de vida" << endl;
        cout << "Vida actual: " << valorVida << endl << endl;
    }
    if(valorVida <= VIDA_NULA)
        cout << nombre << " ha muerto!" << endl << endl;
}
