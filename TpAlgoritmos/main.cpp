#include "utiles.h"


int main() {



    srand(time(0));

    ABB* diccionario = new ABB();

    grafo* mapaGrafo = new grafo();

    bool comenzar = false;

    bool hayPartidaGuardada = false;

    int primerJugador;

    Personaje* personajesJugador1[MAX_PERSONAJES];
    Personaje* personajesJugador2[MAX_PERSONAJES];

    mensajeBienvenida();


    partidaGuardada(personajesJugador1,personajesJugador2,primerJugador,hayPartidaGuardada,mapaGrafo);


    if(hayPartidaGuardada) {
        cout << "\nSE ENCONTRO UNA PARTIDA GUARDADA\n\n";
        comenzarJuego(personajesJugador1, personajesJugador2, mapaGrafo, primerJugador, hayPartidaGuardada);
    }
    else {
        leerArchivo(diccionario);
        procesarOpcion(diccionario, comenzar);

        if (comenzar) {
            primerJugador = valorRandom(2, 1);

            selecionPersonajes(diccionario, personajesJugador1, personajesJugador2);

            posicionarPersonajes(personajesJugador1, personajesJugador2, mapaGrafo, primerJugador);

            comenzarJuego(personajesJugador1, personajesJugador2, mapaGrafo, primerJugador, hayPartidaGuardada);
        }
    }



    delete mapaGrafo;
    delete diccionario;
}
