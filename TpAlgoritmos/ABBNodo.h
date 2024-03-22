//
// Created by tomas on 24/12/2020.
//

#ifndef TPALGORITMOS_ABBNODO_H
#define TPALGORITMOS_ABBNODO_H

#include "personaje.h"

typedef Personaje* dato;

class ABBNodo {
private:
    string clave;
    dato personaje;
    ABBNodo* derecho;
    ABBNodo* izquierdo;
    ABBNodo* padre;
public:
    ABBNodo(dato n);

    //PRE: Nodo no vacio
    //POS: Devuelve el personaje ubicado en el nodo
    dato obtenerDato();

    //PRE: Nodo no vacio
    //POS: Devuelve la clave del nodo
    string obtenerClave();

    //PRE:
    //POS: Le asigna un dato al nodo
    void asignarDato(dato n);

    //PRE:
    //POS: Le asigna un hijo derecho al nodo
    void asignarDerecho(ABBNodo* derecho, ABBNodo* padre);

    //PRE:
    //POS: Le asigna un hijo derecho al nodo
    void asignarDerecho(ABBNodo* derecho);

    //PRE:
    //POS: Le asigna un hijo izquierdo al nodo
    void asignarIzquierdo(ABBNodo* izquierdo, ABBNodo* padre);

    //PRE:
    //POS: Le asigna un hijo izquierdo al nodo
    void asignarIzquierdo(ABBNodo* izquierdo);

    //PRE:
    //POS: Le asigna un padre al nodo
    void asignarPadre(ABBNodo* padre);

    //PRE: Tiene hijo derecho
    //POS: Devuelve el nodo hijo derecho
    ABBNodo* obtenerDerecho();

    //PRE: Tiene hijo izquierdo
    //POS: Devuelve el nodo hijo izquierdo
    ABBNodo* obtenerIzquierdo();

    //PRE: Tiene nodo padre
    //POS: Devuelve el nodo padre
    ABBNodo* obtenerPadre();

    //PRE:
    //POS: Devuelve true si es un nodo hoja, sino false
    bool esHoja();

    //PRE:
    //POS: Devuelve true si solo tiene hijo derecho, sino false
    bool soloHijoDerecho();

    //PRE:
    //POS: Devuelve true si solo tiene hijo izquierdo, sino false
    bool soloHijoIzquierdo();

    ~ABBNodo();

};


#endif //TPALGORITMOS_ABBNODO_H
