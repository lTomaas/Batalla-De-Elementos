//
// Created by patricio on 21/11/20.
//

#ifndef TPALGORITMOS_UTILES_H
#define TPALGORITMOS_UTILES_H

#include "ABB.h"
#include "personaje.h"
#include "personaje_agua.h"
#include "personaje_fuego.h"
#include "personaje_tierra.h"
#include "personaje_aire.h"
#include "grafo.h"
#include "casillero.h"
#include "casilleroGris.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

const char AGREGAR_PERSONAJE = '1';
const char ELIMINAR_PERSONAJE = '2';
const char MOSTRAR_NOMBRES = '3';
const char BUSCAR_PERSONAJE = '4';
const char SALIR = '5';
const char COMENZAR_JUEGO = '6';

const int OPCION_AGUA = 1;
const int OPCION_FUEGO = 2;
const int OPCION_TIERRA = 3;
const int OPCION_AIRE = 4;

const int MAX_PERSONAJES = 2;

const char BUSCAR = '1';
const char MOSTRAR = '2';
const char SELECCIONAR = '3';

const int ALIMENTARSE = 1;
const int MOVERSE = 2;
const int PASAR_OPCION = 3;
const int DEFENDERSE = 1;
const int ATACAR = 2;



//PRE:
//POS: Imprime el mensaje de bienvenida
void mensajeBienvenida();

//PRE: El archivo no esta vacio
//POS: Se lee el archivo con los atributos de los personajes
void leerArchivo(ABB* diccionario);

//PRE:
//POS: Devuelve un personaje que posteriormente sera agregado al diccionario
Personaje* agregarPersonaje(string nombre, string elemento, float vida, int escudo, int energia);

//PRE:
//POS: Devuelve un entero aleatorio entre el rango [minimo,maximo]
int valorRandom(int maximo, int minimo);

//PRE: opcion es un entero
//POS: Valida que opcion este entre el minimo y maximo valor, incluidos
void validarValor(int minimo, int maximo, int &opcion);

//PRE:
//POS: Imprime el menu de opciones
void imprimirMenuOpciones();

//PRE:
//POS: Se ejecuta la operacion elegida por el usuario
void procesarOpcion(ABB* diccionario,bool &comenzar);

//PRE:
//POS: Imprime el menu de creacion de personaje
void imprimirMenuCreacion();

//PRE: opcion es un entero, 1 <= opcion <= 4 (Tipos de personajes)
//POS: Se define el tipo de elemento que va a ser el personaje a crear
string definirElemento(char opcion);

void validarNombre(string &nombre, ABB* diccionario);

//PRE:
//POS: Se crea un personaje y se añade a la lista
void menuCreacionPersonaje(ABB* diccionario);

//PRE: La lista no esta vacia, cantidad > 0
//POS: Imprime los nombres de todos los personajes de la lista
void mostrarNombres(ABB* diccionario);

//PRE:
//POS: Se imprime el menu de eliminacion de personaje
void menuEliminacionPersonaje(ABB* diccionario);

//PRE: El diccionario tiene una cantidad de personajes > MAX_PERSONAJES
//POS: Se elimina el personaje con nombre == clave del diccionario
void eliminarPersonaje(ABB* diccionario, string clave);

//PRE: pos es un entero, 0 < pos <= cantidad
//POS: Se imprime las estadisticas del personaje de la posicion elegida
void mostrarEstadisticas(ABB* diccionario, string clave);

//PRE: La lista no esta vacia, cantidad > 0
//POS: Se imprime la lista de personajes y el usuario indica cual desea eliminar
void buscarPersonaje(ABB* diccionario);

//PRE:
//POS: Cada jugador selecciona sus personajes hasta un maximo de MAX_PERSONAJES
void selecionPersonajes(ABB* diccionario, Personaje* vector1[], Personaje* vector2[]);

//PRE:
//POS: imprime el menu de seleccion de personajes
void imprimirMenuSeleccion(int jugador);

//PRE: El diccionario no esta vacio
//POS: Devuelve el personaje elegido por el jugador
Personaje* seleccionarPersonaje(ABB* diccionario);

//PRE:
//POS: Cada jugador posiciona sus personajes en el mapa
void posicionarPersonajes(Personaje* vector1[], Personaje* vector2[], grafo* mapa, int primerJugador);

//PRE:
//POS: se ubica al Personaje en la fila y columna indicada por el jugador
void posicionamiento(Personaje* vector[], grafo* mapa, int i, string jugador);

//PRE:
//POS: Comprueba que el casillero no este ocupado por otro personaje y que (0 <= fila < FILAS y 0<= columna < COLUMNAS
void comprobarPosicion(int *fila, int *columna, grafo* mapa);

//PRE:
//POS: Comienza la partida
void comenzarJuego(Personaje* vector1[], Personaje* vector2[], grafo* mapa, int primerJugador, bool hayPartidaGuardada);

//PRE:
//POS: Se elige la accion que va a realizar cada personaje de cada jugador
void elegirAccion(Personaje* vector[], grafo* mapa,int jugador);

//PRE:
//POS: Se imprime las estadisticas del personaje que va a realizar sus acciones
void mostrarEstadoPersonajes(Personaje* personaje, int fila, int columna, int jugador);

//PRE:
//POS: Se imprime el menu de acciones para movimiento o alimentacion del personaje
void mostrarMenuAccionesMovimiento(int &opcion, Personaje* personaje);

//PRE:
//POS: Se imprime el menu de acciones para defensa o ataque del personaje
void mostrarMenuAccionesAtaque(int &opcion, Personaje* personaje);

//PRE:
//POS: El jugador elige que accion de movimiento o alimentacion va a realizar su personaje
void menuAccionesMovimiento(Personaje* vector[], grafo* mapa, int i);

//PRE:
//POS: Se ubica al personaje en la posicion fila y columna indicada si puede moverse
void moverPersonaje(Personaje* vector[], int i, grafo* mapa);

//PRE:
//POS: El jugador elige que accion de defensa o ataque va a realizar su personaje
void menuAccionesAtaque(Personaje* vector[], grafo* mapa, int i);

//PRE:
//POS: El personaje ejecuta su accion de defensa si tiene energia suficiente
void defenderPersonaje(Personaje* vector[], int i, grafo* mapa);

//PRE:
//POS: El personaje ejecuta su accion de ataque si tiene energia suficiente
void ataquePersonaje(Personaje* vector[], int i, grafo* mapa);

//PRE:
//POS Se realiza el ataque determinado para los personajes de tipo FUEGO
void ataqueFuego(Personaje* vector[], int i, grafo* mapa);

//PRE:
//POS: Se realiza el ataque determinado para los personajes de tipo TIERRA
void ataqueTierra(Personaje* vector[], int i, grafo* mapa);

//PRE:
//POS: Se realiza el ataque determinado para los personajes de tipo AGUA
void ataqueAgua(Personaje* vector[], int i, grafo* mapa);

//PRE:
//POS: Se realiza el ataque determinado para los personajes de tipo AIRE
void ataqueAire(Personaje* vector[], int i, grafo* mapa);

//PRE:
//POS: Se avanza al siguiente turno, comprobando si hay un ganador y aplicando los efectos por turno de cada personaje
void avanzarTurno(bool &juegoTerminado, Personaje* vector[], int &jugadorGanador, int jugador);

//PRE:
//POS: comprueba si existe partida guardada, si la hay, se lee el archivo para llenar los vectores de personajes de cada jugador
void partidaGuardada(Personaje* vector1[], Personaje* vector2[], int &primerJugador, bool &hayPartidaGuardada, grafo* mapa);

//PRE:
//POS: Se llenan los vectores de personajes de cada jugador con los datos leidos de la partida guardada
void llenarVectorPersonajes(Personaje* vector[], string elemento, string nombre, int escudo, float vida, int energia, int fila, int columna, string jugador, int i, grafo* mapa, int defensa);

//PRE:
//POS: se guarda la partida en el archivo .csv
void guardarPartida(int primerJugador, Personaje* vector1[], Personaje* vector2[]);

//PRE:
//POS: devuelve true si el usuario decide guardar la partida, sino false
bool guardar();


#endif //TPALGORITMOS_UTILES_H
