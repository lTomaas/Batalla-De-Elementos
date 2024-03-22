//
// Created by tomas on 24/12/2020.
//

#include "ABB.h"

ABB::ABB() {
    this->raiz = NULL;
}

ABBNodo* ABB::insertar(ABBNodo *nodo, dato n) {
    if (nodo == 0)
        nodo = new ABBNodo(n);
    else
        if (n -> obtenerNombre() > nodo -> obtenerClave())
            nodo -> asignarDerecho(insertar(nodo -> obtenerDerecho(),n),nodo);
        else
            nodo -> asignarIzquierdo(insertar(nodo -> obtenerIzquierdo(),n),nodo);
    return nodo;
}

void ABB::insertar(dato n) {
    this -> raiz = insertar(this->raiz,n);
}

void ABB::imprimirEnOrden(ABBNodo *nodo) {
    if (nodo != 0){
        imprimirEnOrden(nodo -> obtenerIzquierdo());
        if(nodo->obtenerDato() -> estaHabilitado())
            std::cout << nodo -> obtenerClave() << endl;
        imprimirEnOrden(nodo -> obtenerDerecho());
    }
}

void ABB::imprimirEnOrden() {
    this->imprimirEnOrden(this->raiz);
}

ABBNodo* ABB::buscar(ABBNodo *nodo, string clave) {
    if (nodo == 0 || nodo -> obtenerClave() == clave)
        return nodo;
    if (clave > nodo -> obtenerClave())
        return buscar(nodo -> obtenerDerecho(),clave);

    return buscar(nodo -> obtenerIzquierdo(),clave);
}

bool ABB::buscar(string clave) {
    ABBNodo* resultado = buscar(this->raiz,clave);

    return resultado != 0;
}

dato ABB::encontrarMinimo(ABBNodo *nodo) {
    if (nodo == 0)
        return 0;
    else if (nodo -> obtenerIzquierdo() == 0)
        return nodo -> obtenerDato();
    else
        return encontrarMinimo(nodo -> obtenerIzquierdo());
}

dato ABB::encontrarMinimo() {
    return encontrarMinimo(this->raiz);
}

dato ABB::encontrarMaximo(ABBNodo *nodo) {
    if (nodo == 0)
        return 0;
    else if (nodo -> obtenerDerecho() == 0)
        return nodo -> obtenerDato();
    else
        return encontrarMaximo(nodo -> obtenerDerecho());
}

dato ABB::encontrarMaximo() {
    return encontrarMaximo(this -> raiz);
}

dato ABB::sucesor(ABBNodo *nodo) {
    if (nodo -> obtenerDerecho() != 0)
        return encontrarMinimo(nodo -> obtenerDerecho());

    ABBNodo* sucesor = 0;
    ABBNodo* ancestro = this->raiz;
    while(ancestro != nodo) {
        if (nodo -> obtenerClave() < ancestro -> obtenerClave()) {
            sucesor = ancestro;
            ancestro = ancestro -> obtenerIzquierdo();
        }
        else
            ancestro = ancestro -> obtenerDerecho();
    }
    return sucesor -> obtenerDato();
}

dato ABB::sucesor(string clave) {
    ABBNodo* nodoDato = this -> buscar(this->raiz,clave);

    if (nodoDato == 0)
        return 0;
    else
        return sucesor(nodoDato);
}

dato ABB::predecesor(ABBNodo *nodo) {
    if (nodo -> obtenerIzquierdo() != 0)
        return encontrarMaximo(nodo -> obtenerIzquierdo());

    ABBNodo* sucesor = 0;
    ABBNodo* ancestro = this->raiz;
    while(ancestro != nodo) {
        if (nodo -> obtenerClave() > ancestro -> obtenerClave()) {
            sucesor = ancestro;
            ancestro = ancestro -> obtenerDerecho();
        }
        else
            ancestro = ancestro -> obtenerIzquierdo();
    }
    return sucesor -> obtenerDato();
}

dato ABB::predecesor(string clave) {
    ABBNodo* nodoDato = this -> buscar(this->raiz,clave);

    if (nodoDato == 0)
        return 0;
    else
        return predecesor(nodoDato);
}

ABBNodo* ABB::borrarDato(ABBNodo *nodo, string clave) {
    if (nodo == 0)
        return 0;

    if (nodo -> obtenerClave() == clave){
        if(nodo -> esHoja()) {
            delete nodo;
            return 0;
        }
        else
            if (nodo -> soloHijoDerecho()){
                nodo -> obtenerDerecho() -> asignarPadre(nodo -> obtenerPadre());
                ABBNodo* aux = nodo;
                nodo = nodo -> obtenerDerecho();
                delete aux;
                }
            else
                if (nodo -> soloHijoIzquierdo()) {
                    nodo -> obtenerIzquierdo() -> asignarPadre(nodo -> obtenerPadre());
                    ABBNodo *aux = nodo;
                    nodo = nodo -> obtenerIzquierdo();
                    delete aux;
                }
                else{
                    dato datoSucesor = this -> sucesor(clave);
                    nodo -> asignarDato(datoSucesor);
                    nodo -> asignarDerecho(borrarDato(nodo -> obtenerDerecho(),datoSucesor -> obtenerNombre()));
                }
    }
    else
        if (nodo -> obtenerClave() < clave)
            nodo -> asignarDerecho(borrarDato(nodo -> obtenerDerecho(),clave));
        else
            nodo -> asignarIzquierdo(borrarDato(nodo -> obtenerIzquierdo(),clave));

    return nodo;
}

void ABB::borrarDato(string clave) {
    this -> raiz = borrarDato(this -> raiz,clave);
}

ABBNodo* ABB::obtenerRaiz() {
    return this -> raiz;
}


bool ABB::vacio() {
    return this -> raiz == 0;
}

void ABB::borrarTodo(ABBNodo *nodo){
    if(nodo == 0)
        return;
    this -> borrarTodo(nodo -> obtenerIzquierdo());
    this -> borrarTodo(nodo -> obtenerDerecho());
    delete nodo;
}

void ABB::borrarTodo() {
    this -> borrarTodo(this -> raiz);
}

ABB::~ABB() {
    this->borrarTodo();
}

dato ABB::obtenerPersonaje(string clave) {
    return buscar(raiz,clave) -> obtenerDato();
}
