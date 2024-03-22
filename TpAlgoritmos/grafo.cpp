//
// Created by tomas on 2/2/2021.
//

#include "grafo.h"

#include "windows.h"
#include "personaje.h"
#include "personaje_fuego.h"
#include "personaje_agua.h"
#include "personaje_tierra.h"
#include "personaje_aire.h"



grafo::grafo(){
    inicializar();
}

void grafo::inicializar(){
    int contador = 0;
    for(int i = 0; i < FILAS; i++)
        for(int j = 0; j < COLUMNAS; j++){
            Casillero *nuevoCasillero;
            if (this -> mapa[i][j] == 0)
                nuevoCasillero = new casilleroGris(i, j);
            else if (this -> mapa[i][j] == 1)
                nuevoCasillero = new casilleroRojo(i, j);
            else if (this -> mapa[i][j] == 2)
                nuevoCasillero = new casilleroAzul(i, j);
            else if (this -> mapa[i][j] == 5)
                nuevoCasillero = new casilleroAmarillo(i, j);
            else if (this -> mapa[i][j] == 6)
                nuevoCasillero = new casilleroVioleta(i, j);
            else
                nuevoCasillero = new casilleroVerde(i, j);

            insertarVertice(nuevoCasillero,contador,i,j);
            contador++;
        }

    for(int i = 0; i < FILAS; i++)
        for(int j = 0; j < COLUMNAS; j++){
            if(obtenerVertice(i + 1, j) != 0)
                insertarArista(obtenerVertice(i,j),obtenerVertice(i + 1,j));
            if(obtenerVertice(i - 1, j) != 0)
                insertarArista(obtenerVertice(i,j),obtenerVertice(i - 1,j));
            if(obtenerVertice(i,j + 1) != 0)
            insertarArista(obtenerVertice(i,j),obtenerVertice(i,j + 1));
            if(obtenerVertice(i,j - 1) != 0)
            insertarArista(obtenerVertice(i,j),obtenerVertice(i,j - 1));
        }

    iniciarMatrices();

}

bool grafo::vacio() {
    return (this -> origen == 0);
}


void grafo::insertarVertice(Casillero *casillero, int numeroVertice, int fila, int columna) {
    vertice *nuevoVertice = new vertice();
    nuevoVertice -> numeroVertice = numeroVertice;
    nuevoVertice -> casillero = casillero;
    nuevoVertice -> fila = fila;
    nuevoVertice -> columna = columna;
    nuevoVertice -> sig = 0;
    nuevoVertice -> adyacente = 0;

    if(vacio())
        this -> origen = nuevoVertice;
    else{
        vertice *auxiliar = this -> origen;
        while(auxiliar -> sig != 0)
            auxiliar = auxiliar -> sig;
        auxiliar -> sig = nuevoVertice;
    }



}

void grafo::insertarArista(vertice *inicio, vertice *destino) {
    arista *nuevaArista = new arista();
    nuevaArista -> sig = 0;
    nuevaArista -> adyacente = 0;

    arista *auxiliar = inicio -> adyacente;

    if(auxiliar == 0)
        inicio -> adyacente = nuevaArista;
    else{
        while(auxiliar -> sig != 0)
            auxiliar = auxiliar -> sig;
        auxiliar -> sig = nuevaArista;
    }
    nuevaArista -> adyacente = destino;

}


vertice* grafo::obtenerVertice(int fila, int columna){
    vertice *auxiliar;
    auxiliar = this -> origen;
    while(auxiliar != 0) {
        if( auxiliar -> fila == fila && auxiliar -> columna == columna)
            return auxiliar;
        auxiliar = auxiliar->sig;
    }

    return 0;
}

vertice* grafo::obtenerVertice(int numeroVertice){
    vertice* auxiliar;
    auxiliar = this-> origen;
        while(auxiliar != 0) {
            if (auxiliar->numeroVertice == numeroVertice)
                return auxiliar;
            auxiliar = auxiliar->sig;
        }
        return 0;
}


void grafo::matrizAdyacencia(int matriz[VERTICES][VERTICES],int recorrido[VERTICES][VERTICES],Personaje* personaje) {
    int i,j;
    for(i = 0; i < VERTICES; i++)
        for(j = 0; j < VERTICES; j++) {
            matriz[i][j] = INFINITO;
            recorrido[i][j] = 0;
        }

    vertice *vertAux;
    arista *aristaAux;

    vertAux = this -> origen;

    while( vertAux != 0) {
        aristaAux = vertAux -> adyacente;
        i = vertAux -> numeroVertice;
        while(aristaAux != 0){
            j = aristaAux -> adyacente -> numeroVertice;
            matriz[i][j] = aristaAux -> adyacente -> casillero -> obtenerPeso(personaje);
            aristaAux = aristaAux -> sig;
        }
        vertAux = vertAux -> sig;
    }

    for(i = 0; i < VERTICES; i++) {
        for (j = 0; j < VERTICES; j++) {
            if(matriz[i][j] == INFINITO)
                recorrido[i][j] = 0;
            else
                recorrido[i][j] = i;
        }
    }

    caminoMinimo(matriz,recorrido);

}



void grafo::caminoMinimo(int matriz[VERTICES][VERTICES], int recorrido[VERTICES][VERTICES]) {
    for (int k = 0; k < VERTICES; k++) {
        for (int i = 0; i < VERTICES; i++) {
            for (int j = 0; j < VERTICES; j++)
                if (matriz[i][j] > (matriz[i][k] + matriz[k][j])) {
                    matriz[i][j] = matriz[i][k] + matriz[k][j];
                    recorrido[i][j] = recorrido[k][j];
                }
        }
    }
}

void grafo::obtenerCaminoMinimo(int filaActual, int columnaActual, int filaDestino, int columnaDestino, Personaje* personaje){
    if(personaje -> obtenerElemento() == "Fuego")
        obtenerCaminoMinimo(recorridosFuego,filaActual,columnaActual,filaDestino,columnaDestino);
    else if(personaje -> obtenerElemento() == "Agua")
        obtenerCaminoMinimo(recorridosAgua,filaActual,columnaActual,filaDestino,columnaDestino);
    else if(personaje -> obtenerElemento() == "Tierra")
        obtenerCaminoMinimo(recorridosTierra,filaActual,columnaActual,filaDestino,columnaDestino);
    else
        obtenerCaminoMinimo(recorridosAire,filaActual,columnaActual,filaDestino,columnaDestino);
}

void grafo::obtenerCaminoMinimo(int recorrido[VERTICES][VERTICES], int filaActual, int columnaActual, int filaDestino, int columnaDestino) {
    int i,j;
    int inicio = obtenerVertice(filaActual, columnaActual) -> numeroVertice;
    int destino = obtenerVertice(filaDestino, columnaDestino) -> numeroVertice;
    int aux = destino;

    cout << "\n\nEl camino con menor costo a su destino es...";
    cout << "\n[" << filaDestino + 1 << "][" << columnaDestino + 1 << "]";
    while (aux != inicio) {
        i = obtenerVertice(recorrido[inicio][aux]) -> fila;
        j = obtenerVertice(recorrido[inicio][aux]) -> columna;
        cout << "<-[" << i + 1<< "][" << j + 1 << "]";
        aux = recorrido[inicio][aux];
    }
}

void grafo::posicionarPersonaje(Personaje* personaje, int fila, int columna, string jugador){
    int filaActual = personaje -> obtenerFila();
    int columnaActual = personaje -> obtenerColumna();

    obtenerCaminoMinimo(filaActual,columnaActual,fila,columna,personaje);
    obtenerVertice(fila,columna) -> ubicarPersonaje(personaje,jugador);
    obtenerVertice(filaActual,columnaActual) -> reestablecerOcupante();

    personaje -> asignarFila(fila);
    personaje -> asignarColumna(columna);
}

int grafo::obtenerCostoCamino(int filaActual, int columnaActual, int filaDestino, int columnaDestino, Personaje *personaje) {
    if (personaje->obtenerElemento() == ELEMENTO_FUEGO)
        obtenerCostoCamino(matrizAdyacenciaFuego, filaActual, columnaActual, filaDestino, columnaDestino);
    else if (personaje->obtenerElemento() == ELEMENTO_AGUA)
        obtenerCostoCamino(matrizAdyacenciaAgua, filaActual, columnaActual, filaDestino, columnaDestino);
    else if (personaje->obtenerElemento() == ELEMENTO_TIERRA)
        obtenerCostoCamino(matrizAdyacenciaTierra, filaActual, columnaActual, filaDestino, columnaDestino);
    else
        obtenerCostoCamino(matrizAdyacenciaAire, filaActual, columnaActual, filaDestino, columnaDestino);
}


int grafo::obtenerCostoCamino(int distancia[VERTICES][VERTICES], int filaActual, int columnaActual, int filaDestino, int columnaDestino) {
    int i = obtenerVertice(filaActual,columnaActual) -> numeroVertice;
    int j = obtenerVertice(filaDestino,columnaDestino) -> numeroVertice;

    return distancia[i][j];
}

void grafo::moverPersonaje(Personaje *personaje, int fila, int columna, string jugador) {
    int energiaGastada = obtenerCostoCamino(personaje -> obtenerFila(),personaje -> obtenerColumna(),fila,columna,personaje);
    int energiaPersonaje = personaje -> obtenerEnergia();
    int energia;
    if (energiaPersonaje >= energiaGastada && !obtenerVertice(fila,columna) -> casillero -> estaOcupado()){
        energia = energiaPersonaje - energiaGastada;
        personaje -> asignarEnergia(energia);
        posicionarPersonaje(personaje,fila,columna,jugador);
        cout << "\nCosto del recorrido: " << energiaGastada << endl;
    }
}

bool grafo::puedeMoverse(Personaje* personaje, int fila, int columna){
    int filaActual = personaje -> obtenerFila();
    int columnaActual = personaje -> obtenerColumna();
    int energiaPersonaje = personaje -> obtenerEnergia();
    int energiaGastada = obtenerCostoCamino(filaActual,columnaActual,fila,columna,personaje);

    if (energiaPersonaje >= energiaGastada && !obtenerVertice(fila,columna) -> casillero -> estaOcupado())
        return true;
    else{
        cout << personaje -> obtenerNombre() << " no posee energia suficiente para moverse a ese casillero" << endl;
        cout << "Energia del personaje: " << energiaPersonaje << endl;
        cout << "Energia necesaria para moverse al casillero: " << energiaGastada << endl;
        return false;
    }
}

void grafo::generarMatrizFuego(){
    Personaje* personaje = new PersonajeFuego("","Fuego","",100,100,100);
    matrizAdyacencia(matrizAdyacenciaFuego,recorridosFuego,personaje);
    delete personaje;
}

void grafo::generarMatrizAgua(){
    Personaje* personaje = new PersonajeAgua("","Agua","",100,100,100);
    matrizAdyacencia(matrizAdyacenciaAgua,recorridosAgua,personaje);
    delete personaje;
}

void grafo::generarMatrizTierra(){
    Personaje* personaje = new PersonajeTierra("","Tierra","",100,100,100);
    matrizAdyacencia(matrizAdyacenciaTierra,recorridosTierra,personaje);
    delete personaje;
}

void grafo::generarMatrizAire(){
    Personaje* personaje = new PersonajeAire("","Aire","",100,100,100);
    matrizAdyacencia(matrizAdyacenciaAire,recorridosAire,personaje);
    delete personaje;
}

void grafo::iniciarMatrices(){
    generarMatrizFuego();
    generarMatrizAgua();
    generarMatrizTierra();
    generarMatrizAire();
}

grafo::~grafo(){
    vertice* aux;
    arista* aristAux;

    while(origen != 0){
        aux = origen;
        while(origen -> adyacente != 0){
            aristAux = origen -> adyacente;
            origen -> adyacente = origen -> adyacente -> sig;
            delete aristAux;
        }
        origen = origen->sig;
        delete aux -> casillero;
        delete aux;
    }
}



void grafo::dibujarMapa(){

    for(int i = 0; i < FILAS; i++)
        cout << " " << i + 1 << " ";
    cout << endl;
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            if(mapa[i][j] == 0) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
                cout << " " << obtenerVertice(i,j) -> obtenerJugadorOcupante() << " ";
            }
                if(mapa[i][j] == 2) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
                    cout << " " << obtenerVertice(i,j) -> obtenerJugadorOcupante() << " ";
                }
                if(mapa[i][j] == 1) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),64);
                    cout << " " << obtenerVertice(i,j) -> obtenerJugadorOcupante() << " ";
                }
                if(mapa[i][j] == 6) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),80);
                    cout << " " << obtenerVertice(i,j) -> obtenerJugadorOcupante() << " ";
                }
                if(mapa[i][j] == 5) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),96);
                    cout << " " << obtenerVertice(i,j) -> obtenerJugadorOcupante() << " ";
                }
                if(mapa[i][j] == 7) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),160);
                    cout << " " << obtenerVertice(i,j) -> obtenerJugadorOcupante() << " ";
                }
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
            cout << " " << i + 1 << endl;
        }
}



