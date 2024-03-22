//
// Created by tomas on 24/12/2020.
//

#include "ABBNodo.h"


ABBNodo::ABBNodo(dato n) {
    this -> clave = n->obtenerNombre();
    this -> personaje = n;
    this -> derecho = 0;
    this -> izquierdo = 0;
    this -> padre = 0;
}

dato ABBNodo::obtenerDato() {
    return this -> personaje;
}

string ABBNodo::obtenerClave() {
    return this -> clave;
}

void ABBNodo::asignarDato(dato n) {
    this -> personaje = n;
}

void ABBNodo::asignarDerecho(ABBNodo *derecho, ABBNodo *padre) {
    this -> derecho = derecho;
    this -> padre = padre;

}

void ABBNodo::asignarDerecho(ABBNodo *derecho) {
    this -> derecho = derecho;
}

void ABBNodo::asignarIzquierdo(ABBNodo *izquierdo, ABBNodo *padre) {
    this -> izquierdo = izquierdo;
    this -> padre = padre;
}

void ABBNodo::asignarIzquierdo(ABBNodo *izquierdo) {
    this -> izquierdo = izquierdo;
}

void ABBNodo::asignarPadre(ABBNodo *padre) {
    this -> padre = padre;
}

ABBNodo* ABBNodo::obtenerDerecho() {
    return this -> derecho;
}

ABBNodo* ABBNodo::obtenerIzquierdo(){
    return this->izquierdo;
}

ABBNodo* ABBNodo::obtenerPadre() {
    return this -> padre;
}

bool ABBNodo::esHoja() {
    return(this -> obtenerIzquierdo() == 0 && this -> obtenerDerecho() == 0);
}

bool ABBNodo::soloHijoDerecho() {
    return(this -> obtenerIzquierdo() == 0 && this -> obtenerDerecho() != 0);
}

bool ABBNodo::soloHijoIzquierdo() {
    return(this -> obtenerIzquierdo() != 0 && this -> obtenerDerecho() == 0);
}

ABBNodo::~ABBNodo(){
    delete this -> personaje;
}










