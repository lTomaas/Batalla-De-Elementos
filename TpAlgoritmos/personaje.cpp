//
// Created by patricio on 21/11/20.
//

#include "personaje.h"

Personaje::Personaje(string nombre, string elemento, string alimento, float valorVida, int valorEnergia, int valorEscudo) {
    this -> nombre = nombre;
    this -> elemento = elemento;
    this -> alimento = alimento;
    this -> valorVida = valorVida;
    this -> valorEnergia = valorEnergia;
    this -> valorEscudo = valorEscudo;
    this -> fila = -1;
    this -> columna = -1;
    this -> habilitado = true;
}

Personaje::~Personaje() {

}

void Personaje::asignarFila(int fila) {
    this -> fila = fila;
}

void Personaje::asignarColumna(int columna) {
    this -> columna = columna;
}

int Personaje::obtenerFila() {
    return fila;
}

int Personaje::obtenerColumna() {
    return columna;
}


string Personaje::obtenerAlimento() {
    return alimento;
}

string Personaje::obtenerElemento() {
    return elemento;
}

string Personaje::obtenerNombre() {
    return nombre;
}

int Personaje::obtenerEnergia() {
    return valorEnergia;
}

int Personaje::obtenerEscudo() {
    return valorEscudo;
}

float Personaje::obtenerVida() {
    return valorVida;
}

int Personaje::obtenerCostoAtaque() {
    if (this -> elemento == ELEMENTO_FUEGO)
        return COSTO_ENERGIA_ATAQUE_FUEGO;
    else if (this -> elemento == ELEMENTO_AIRE)
        return COSTO_ENERGIA_ATAQUE_AIRE;
    else if (this -> elemento == ELEMENTO_TIERRA)
        return COSTO_ENERGIA_ATAQUE_TIERRA;
    else
        return COSTO_ENERGIA_ATAQUE_AGUA;
}

int Personaje::obtenerCostoDefenderse(){
    if (this -> elemento == ELEMENTO_FUEGO)
        return  COSTO_ENERGIA_DEFENSA_FUEGO;
    else if (this -> elemento == ELEMENTO_AIRE)
        return COSTO_ENERGIA_DEFENSA_AIRE;
    else if(this -> elemento == ELEMENTO_TIERRA)
        return COSTO_ENERGIA_DEFENSA_TIERRA;
    else
        return COSTO_ENERGIA_DEFENSA_AGUA;
}


void Personaje::asignarEnergia(int nuevaEnergia){
    if(nuevaEnergia < ENERGIA_MAXIMA) {
        this->valorEnergia = nuevaEnergia;
    }
    else
        this -> valorEnergia = ENERGIA_MAXIMA;
}


bool Personaje::estaHabilitado() {
    return this -> habilitado;
}

bool Personaje::estaVivo() {
    return (this -> valorVida > VIDA_NULA);
}

void Personaje::elegido() {
    this -> habilitado = false;
}

void Personaje::asignarVida(float vida) {
    this -> valorVida = vida;
}

void Personaje::asignarEscudo(int escudo) {
    this -> valorEscudo = escudo;
}

float Personaje::obtenerDanioRecibido() {
    if (valorEscudo == ESCUDO_MINIMO)
        return 1;
    else if (valorEscudo == ESCUDO_MEDIO)
        return 0.9;
    else if (valorEscudo == ESCUDO_MAXIMO)
        return 0.8;
    else
        return 0.2;
}

bool Personaje::puedeAtacar() {
    costoAtaque = obtenerCostoAtaque();
    if(valorEnergia >= costoAtaque){
        this -> valorEnergia = valorEnergia - costoAtaque;
        cout << endl << "Energia actual: " << valorEnergia << "/" << ENERGIA_MAXIMA << endl << endl;
        return true;
    }
    else {
        cout << endl <<"Energia insuficiente, costo de energia de ataque: " << costoAtaque << endl;
        cout << "Energia actual: " << valorEnergia << "/" << ENERGIA_MAXIMA;
        return false;
    }
}

bool Personaje::estaDefendiendose() {
    return this -> defendiendose;
}

void Personaje::cambiarEstadoDefensa(int num) {
    if (num == VERDADERO)
        this -> defendiendose = true;
    else
        this -> defendiendose = false;
}