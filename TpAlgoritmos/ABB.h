//
// Created by tomas on 24/12/2020.
//

#ifndef TPALGORITMOS_ABB_H
#define TPALGORITMOS_ABB_H
#include "ABBNodo.h"


class ABB {
private:
    ABBNodo* raiz;
public:
    ABB();

    //PRE:
    //POS: Devuelve el personaje con nombre == clave
    dato obtenerPersonaje(string clave);

    //PRE:
    //POS: Inserta un personaje siguiendo el orden alfabetico por nombre
    void insertar(dato n);

    //PRE:
    //POS: Imprime los nombres de todos los personajes del diccionario en orden alfabetico
    void imprimirEnOrden();

    //PRE:
    //POS: Devuelve true si existe un personaje con nombre == clave
    bool buscar(string clave);

    //PRE:
    //POS: Devuelve el dato minimo del diccionario
    dato encontrarMinimo();

    //PRE:
    //POS: Devuelve el dato maximo del diccionario
    dato encontrarMaximo();

    //PRE:
    //POS: Devuelve el dato sucesor a la clave
    dato sucesor(string clave);

    //PRE:
    //POS: Devuelve el dato predecesor a la clave
    dato predecesor(string clave);

    //PRE:
    //POS: Se elimina al personaje con nombre == clave del diccionario
    void borrarDato(string clave);

    //PRE:
    //POS: Devuelve el nodo raiz
    ABBNodo* obtenerRaiz();

    //PRE:
    //POS: Devuelve true si el diccionario esta vacio, sino falso
    bool vacio();

    //PRE:
    //POS: Elimina todos los datos del diccionario
    void borrarTodo();

    ~ABB();

private:

    ABBNodo* insertar(ABBNodo* nodo, dato n);

    void imprimirEnOrden(ABBNodo* nodo);

    ABBNodo* buscar(ABBNodo* nodo, string clave);

    dato encontrarMinimo(ABBNodo* nodo);

    dato encontrarMaximo(ABBNodo* nodo);

    dato sucesor(ABBNodo* nodo);

    dato predecesor(ABBNodo* nodo);

    ABBNodo* borrarDato(ABBNodo* nodo, string clave);

    void borrarTodo(ABBNodo* nodo);

};


#endif //TPALGORITMOS_ABB_H
