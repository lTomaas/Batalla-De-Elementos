//
// Created by patricio on 21/11/20.
//

#ifndef TPALGORITMOS_PERSONAJE_H
#define TPALGORITMOS_PERSONAJE_H

#include <iostream>

using namespace std;

const int ENERGIA_MAXIMA = 20;
const int ENERGIA_MINIMA = 0;
const float VIDA_MAXIMA = 100;
const float VIDA_MINIMA = 10;
const float VIDA_NULA = 0;
const int ESCUDO_MAXIMO = 2;
const int ESCUDO_MEDIO = 1;
const int ESCUDO_MINIMO = 0;

const string ELEMENTO_AGUA = "Agua";
const string ELEMENTO_AIRE = "Aire";
const string ELEMENTO_FUEGO = "Fuego";
const string ELEMENTO_TIERRA = "Tierra";

//CONSTANTES FUEGO
const string ALIMENTO_FUEGO = "Madera";
const int ENERGIA_RECUPERADA_FUEGO = 10;
const int VIDA_RECUPERADA_FUEGO = 5;
const int COSTO_ENERGIA_DEFENSA_FUEGO = 10;
const int COSTO_ENERGIA_ATAQUE_FUEGO = 5;
const int ATAQUE_AGUA_FUEGO = 30;
const int ATAQUE_AIRE_FUEGO = 10;
const int ATAQUE_FUEGO_FUEGO = 20;
const int VIDA_PERDIDA_POR_TURNO_FUEGO = 5;

//CONSTANTES AGUA
const string ALIMENTO_AGUA = "Plancton";
const int ENERGIA_RECUPERADA_AGUA = 10;
const int VIDA_RECUPERADA_AGUA = 50;
const int COSTO_ENERGIA_DEFENSA_AGUA = 12;
const int COSTO_ENERGIA_ATAQUE_AGUA = 5;
const int VIDA_RECUPERADA_ALIADOS_AGUA = 10;
const int ATAQUE_TIERRA_AGUA = 20;
const int ATAQUE_AIRE_AGUA = 15;
const int ATAQUE_FUEGO_AGUA = 10;
const int ATAQUE_AGUA_AGUA = 20;

//CONSTANTES AIRE
const string ALIMENTO_AIRE = "ESTE PERSONAJE NO REQUIERE ALIMENTARSE";
const int ENERGIA_RECUPERADA_AIRE = 20;
const int COSTO_ENERGIA_DEFENSA_AIRE = 15;
const int COSTO_ENERGIA_ATAQUE_AIRE = 8;
const int ATAQUE_FUEGO_AIRE = 30;
const int ATAQUE_TIERRA_AIRE = 10;
const int ATAQUE_AGUA_AIRE = 20;
const int ATAQUE_AIRE_AIRE = 15;
const int ENERGIA_RECUPERADA_POR_TURNO_AIRE = 5;

//CONSTANTES TIERRA
const string ALIMENTO_TIERRA = "Hierbas";
const int ENERGIA_RECUPERADA_TIERRA = 8;
const int COSTO_ENERGIA_DEFENSA_TIERRA = 5;
const int COSTO_ENERGIA_ATAQUE_TIERRA = 6;
const int ESCUDO_OBTENIDO_TIERRA = 2;
const int ATAQUE_AGUA_TIERRA = 10;
const int ATAQUE_FUEGO_TIERRA = 20;
const int ATAQUE_AIRE_TIERRA = 20;
const int ZONA_MARRON_OSCURO = 2;
const int ZONA_MARRON = 4;
const int ATAQUE_ZONA_MARRON_OSCURO = 30;
const int ATAQUE_ZONA_MARRON = 20;
const int ATAQUE_ZONA_MARRON_CLARO = 10;

const int VERDADERO = 1;
const int FALSO = 0;


class Personaje {
protected:
    string nombre;
    string elemento;
    string alimento;
    float valorVida;
    int valorEnergia;
    int valorEscudo;
    int costoAtaque;
    int fila;
    int columna;
    bool habilitado;
    bool defendiendose = false;
public:
    //POS:
    //PRE: Crea un objeto personaje con sus atributos
    Personaje(string nombre, string elemento, string alimento, float valorVida,int valorEnergia, int valorEscudo);

    //PRE:
    //POS: Se muestra el nombre del personaje, alimento, con que se alimento, la energia que recupero y su energia actual
    virtual void alimentarPersonaje() = 0;

    //PRE:
    //POS: Devuelve el nombre del personaje
    string obtenerNombre();

    //PRE:
    //POS: Devuelve el elemento del personaje
    string obtenerElemento();

    //PRE:
    //POS: Devuelve el alimento del personaje
    string obtenerAlimento();

    //PRE:
    //POS: Devuelve el valor de vida del personaje
    float obtenerVida();

    //PRE:
    //POS: Devuelve el valor de energia del personaje
    int obtenerEnergia();

    //PRE:
    //POS: Devuelve el valor de escudo del personaje
    int obtenerEscudo();

    //PRE:
    //POS: Devuelve el valor del costo de ataque
    int obtenerCostoAtaque();

    //PRE:
    //POS: Devuelve el valor del costo de defenderse
    int obtenerCostoDefenderse();

    //PRE:
    //POS cambia su estado de habilitado a false
    void elegido();

    //PRE:
    //POS: Si esta habilitado devuelve true, sino false
    bool estaHabilitado();

    //PRE:
    //POS: Devuelve true si el valorVida del personaje > VIDA_MINIMA, sino false
    bool estaVivo();

    //PRE: 0 <= fila < FILAS
    //POS: le asigna la posicion fila al personaje
    void asignarFila(int fila);

    //PRE: 0 <= columna < COLUMNAS
    //POS: le asigna la posicion columna al personaje
    void asignarColumna(int columna);

    //PRE:
    //POS: devuelve la posicion fila del personaje
    int obtenerFila();

    //PRE:
    //POS: devuelve la posicion columna del personaje
    int obtenerColumna();

    //PRE: 0 <= nuevaEnergia <= ENERGIA_MAXIMA
    //POS: se le asigna el nuevo valor nuevaEnergia a valorEnergia
    void asignarEnergia(int nuevaEnergia);

    //PRE: 0 <= vida <= VIDA_MAXIMA
    //POS: se le asigna el nuevo valor de vida a valorVida
    void asignarVida(float vida);

    //PRE: 0 <= escudo <= ESCUDO_MAXIMO + 2
    //POS: se le asigna el nuevo valor de escudo a valorEscudo
    void asignarEscudo(int escudo);

    //PRE: el personaje tiene energia suficiente para defenderse
    //POS: El personaje utiliza su habilidad de defensa
    virtual void defenderse() = 0;

    //PRE:
    //POS: El Personaje recibe un ataque de parte de personaje y pierde vida
    virtual void recibirAtaque(Personaje* personaje) = 0;

    //PRE:
    //POS: devuelve true si tiene energia suficiente para ejecutar su ataque
    bool puedeAtacar();

    //PRE:
    //POS: Devuelve el valor de danio recibido despues de ser bloqueado por su valorEscudo
    float obtenerDanioRecibido();

    //PRE: El personaje es de tipo TIERRA
    //POS: Devuelve true si el personaje ejecuto su accion de defensa y sigue activa
    bool estaDefendiendose();

    //PRE: El personaje es de tipo TIERRA
    //POS: Se cambia el estado de defensa del personaje
    void cambiarEstadoDefensa(int num);


    //Destructor
    virtual ~Personaje();

};


#endif //TPALGORITMOS_PERSONAJE_H
