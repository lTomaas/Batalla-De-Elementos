//
// Created by tomas on 2/2/2021.
//

#ifndef TPALGORITMOS_GRAFO_H
#define TPALGORITMOS_GRAFO_H

#include "vertice.h"
#include "casilleroGris.h"
#include "casilleroAzul.h"
#include "casilleroRojo.h"
#include "casilleroAmarillo.h"
#include "casilleroVerde.h"
#include "casilleroVioleta.h"

const int FILAS = 8;
const int COLUMNAS = 8;
const int VERTICES = 64;
const int INFINITO = 10000;

class grafo {
private:
    vertice *origen = 0;
    int mapa[FILAS][COLUMNAS] = {
            {2,2,0,0,0,6,1,1},
            {2,2,0,6,1,1,1,1},
            {0,1,1,1,1,0,0,0},
            {1,5,5,5,2,6,5,5},
            {5,5,6,5,5,5,5,0},
            {5,5,5,6,7,7,7,0},
            {0,7,7,7,7,2,2,2},
            {0,0,7,0,6,2,2,2}
    };
    int matrizAdyacenciaFuego[VERTICES][VERTICES];
    int matrizAdyacenciaAgua[VERTICES][VERTICES];
    int matrizAdyacenciaTierra[VERTICES][VERTICES];
    int matrizAdyacenciaAire[VERTICES][VERTICES];
    int recorridosFuego[VERTICES][VERTICES];
    int recorridosAgua[VERTICES][VERTICES];
    int recorridosTierra[VERTICES][VERTICES];
    int recorridosAire[VERTICES][VERTICES];
public:
    //Constructor
    grafo();

    //PRE:
    //POS: devuelve true si el grafo esta vacio, sino false;
    bool vacio();

    //PRE: ( 0 <= fila < FILAS) y ( 0 <= columna < COLUMNAS)
    //POS: devuelve el vertice que se encuentra en la posicion (fila,columna) del mapa
    vertice* obtenerVertice(int fila, int columna);

    //PRE:  0 <= numeroVertice < VERTICES
    //POS: devuelve el vertice de numero numeroVertice del grafo
    vertice* obtenerVertice(int numeroVertice);

    //PRE: ( 0 <= fila < FILAS) y ( 0 <= columna < COLUMNAS)
    //POS: ubica al personaje en la posicion (fila,columna) del mapa
    void posicionarPersonaje(Personaje* personaje,int fila, int columna, string jugador);

    //PRE: ( 0 <= fila < FILAS) y ( 0 <= columna < COLUMNAS), tiene la energia suficiente y el casillero al que se va a mover no esta ocupado (puedeMoverse)
    //POS: ubica al personaje en la posicion (fila,columna) del mapa
    void moverPersonaje(Personaje* personaje, int fila, int columna, string jugador);

    //PRE:
    //POS: Imprime el mapa
    void dibujarMapa();

    //PRE: ( 0 <= fila < FILAS) y ( 0 <= columna < COLUMNAS)
    //POS: devuelve true si, tiene la energia suficiente para moverse al casillero (fila,columna) y este no esta ocupado, sino devuelve false
    bool puedeMoverse(Personaje* personaje, int fila, int columna);

    ~grafo();

private:
    //PRE:
    //POS: Se genera la matriz de adyacencia para los personajes de tipo FUEGO
    void generarMatrizFuego();

    //PRE:
    //POS: Se genera la matriz de adyacencia para los personajes de tipo AGUA
    void generarMatrizAgua();

    //PRE:
    //POS: Se genera la matriz de adyacencia para los personajes de tipo TIERRA
    void generarMatrizTierra();

    //PRE:
    //POS: Se genera la matriz de adyacencia para los personajes de tipo AIRE
    void generarMatrizAire();

    //PRE:
    //POS: Se inician las matrices de adyacencia de todos los personajes
    void iniciarMatrices();

    //PRE:
    //POS: Se genera una matriz de adyacencia determinada
    void matrizAdyacencia(int matriz[VERTICES][VERTICES],int recorrido[VERTICES][VERTICES],Personaje* personaje);

    //PRE:
    //POS: Se forma la matriz de camino minimo con su recorrido
    void caminoMinimo(int matriz[VERTICES][VERTICES],int recorrido[VERTICES][VERTICES]);

    //PRE:
    //POS: Se obtiene el camino minimo segun el tipo de personaje
    void obtenerCaminoMinimo(int filaActual, int columnaActual, int filaDestino, int columnaDestino, Personaje* personaje);

    //PRE:
    //POS: Imprime el recorrido del camino de menor costo al destino filaDestino y columnaDestino
    void obtenerCaminoMinimo(int recorrido[VERTICES][VERTICES], int filaActual, int columnaActual, int filaDestino, int columnaDestino);

    //PRE:
    //POS: Busca el costo de camino minimo segun el tipo de personaje
    int obtenerCostoCamino(int filaActual, int columnaActual, int filaDestino, int columnaDestino, Personaje* personaje);

    //PRE:
    //POS: Devuelve el costo del camino minimo para mover al personaje a filaDestino y columnaDestino
    int obtenerCostoCamino(int distancia[VERTICES][VERTICES], int filaActual, int columnaActual, int filaDestino, int columnaDestino);

    //PRE:
    //POS: Se inserta un vertice en la ultima posicion de los vertices
    void insertarVertice(Casillero *casillero,int numeroVertice,int fila, int columna);

    //PRE:
    //POS: Se inserta una arista en la ultima posicion de las aristas que une al vertice de inicio con el vertice destino
    void insertarArista(vertice *inicio, vertice *destino);

    //PRE:
    //POS: Se inicializa el grafo
    void inicializar();

};


#endif //TPALGORITMOS_GRAFO_H
