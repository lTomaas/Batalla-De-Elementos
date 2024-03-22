//
// Created by patricio on 21/11/20.
//

#include "utiles.h"
#include "windows.h"

void mensajeBienvenida(){
    cout << endl << "BIENVENIDOS A LA BATALLA DE LOS ELEMENTOS" << endl;
    cout << endl << "INDICACIONES" << endl;
    cout << endl << "Existen 4 tipos de personajes, todos tienen un maximo de 20 puntos de ENERGIA y maximo 100 puntos de VIDA.";
    cout << endl << "1) AGUA: Este personaje se alimenta de PLANCTON y solo puede hacerlo 3 veces, recupera 10 puntos de ENERGIA.";
    cout << endl << "2) FUEGO: Este personaje necesita MADERA para alimentarse, recupera 5 puntos de VIDA y 10 puntos de ENERGIA.";
    cout << endl << "3) TIERRA: Este personaje se alimenta de HIERBAS, recupera 8 puntos de ENERGIA.";
    cout << endl << "4) AIRE: Este personaje NO REQUIERE ALIMENTARSE y recupera energia por cada turno." << endl;
    cout << endl << "TIPOS DE ATAQUE" << endl;
    cout << endl << "Cada personaje requiere una cantidad de energia para atacar";
    cout << endl << "AGUA: Este personaje ataca un casillero en especifico, COSTO: " << COSTO_ENERGIA_ATAQUE_AGUA;
    cout << endl << "FUEGO: Este personaje ataca a todos los personajes que se encuentren en la misma fila y una fila por encima y una fila por debajo, COSTO: " << COSTO_ENERGIA_ATAQUE_FUEGO;
    cout << endl << "TIERRA: Este personaje provoca mayor danio cuanto mas cerca este el oponente, COSTO: " << COSTO_ENERGIA_ATAQUE_TIERRA;
    cout << endl << "AIRE: Este personaje provoca danio a todos los personajes del mapa, COSTO: " << COSTO_ENERGIA_ATAQUE_AIRE << endl;
    cout << endl << "TIPOS DE DEFENSA" << endl;
    cout << endl << "Cada personaje requiere una cantidad de energia para defenderse";
    cout << endl << "AGUA: Este personaje recibe 50 puntos de VIDA y cura otros 10 puntos de VIDA a sus companieros, COSTO: " << COSTO_ENERGIA_DEFENSA_AGUA;
    cout << endl << "FUEGO: Este personaje recibe 10 puntos de VIDA, COSTO: " << COSTO_ENERGIA_DEFENSA_FUEGO;
    cout << endl << "TIERRA: Este personaje gana por un turno 2 puntos extra de ESCUDO, COSTO: " << COSTO_ENERGIA_DEFENSA_TIERRA;
    cout << endl << "AIRE: Este personaje obtiene la habilidad de desplazarse a cualquier casillero sin gastar ENERGIA, COSTO: " << COSTO_ENERGIA_DEFENSA_AIRE << endl << endl;
}

void partidaGuardada(Personaje* vector1[], Personaje* vector2[], int &primerJugador, bool &hayPartidaGuardada, grafo* mapa){
    fstream archivo;
    archivo.open("../partida.csv", ios::in);
    if(!archivo) {
        hayPartidaGuardada = false;
        cout << "No hay partida guardada" << endl;
    }
    else{
        int contador = 0, escudo, energia, fila, columna, defensa;
        int i = 0;
        float vida;
        bool vector1Cargado = false;
        hayPartidaGuardada = true;
        string lectura, elemento, nombre;
        getline(archivo,lectura,'\n');
        primerJugador = stoi(lectura);
        while(getline(archivo,lectura,',')){
            defensa = stoi(lectura);
            if(contador == MAX_PERSONAJES){
                vector1Cargado = true;
                i = 0;
            }
            getline(archivo,elemento,',');
            getline(archivo,nombre,',');
            getline(archivo,lectura,',');
            escudo = stoi(lectura);
            getline(archivo,lectura,',');
            vida = stof(lectura);
            getline(archivo,lectura,',');
            energia = stoi(lectura);
            getline(archivo,lectura,',');
            fila = stoi(lectura);
            getline(archivo,lectura,'\n');
            columna = stoi(lectura);
            if (!vector1Cargado)
                llenarVectorPersonajes(vector1, elemento, nombre, escudo, vida, energia, fila, columna,"1", i, mapa, defensa);
            else
                llenarVectorPersonajes(vector2, elemento, nombre, escudo, vida, energia, fila, columna,"2", i, mapa, defensa);



            contador++;
            i++;
        }
        archivo.close();
    }
}

void llenarVectorPersonajes(Personaje* vector[], string elemento, string nombre, int escudo, float vida, int energia, int fila, int columna, string jugador, int i, grafo* mapa, int defensa){
    vector[i] = agregarPersonaje(nombre,elemento,vida,escudo,energia);
    if(vida > VIDA_NULA)
        mapa -> obtenerVertice(fila, columna) -> ubicarPersonaje(vector[i], jugador);

    vector[i] -> asignarFila(fila);
    vector[i] -> asignarColumna(columna);

    if (defensa == VERDADERO)
        vector[i]->cambiarEstadoDefensa(VERDADERO);
    else
        vector[i]->cambiarEstadoDefensa(FALSO);

}

void leerArchivo(ABB* diccionario){
    fstream archivo;
    archivo.open("../Personajes.csv", ios::in);
    if(!archivo)
        cout << "No se pudo abrir el archivo" << endl;
    else {
        string nombre, elemento, lectura;
        float vida;
        int escudo, energia;
        while(getline(archivo,elemento,',')){
            getline(archivo,nombre,',');
            getline(archivo,lectura,',');
            escudo = stoi(lectura);
            getline(archivo,lectura,'\n');
            vida = stof(lectura);
            energia = valorRandom(ENERGIA_MAXIMA,ENERGIA_MINIMA);
            diccionario -> insertar(agregarPersonaje(nombre, elemento, vida, escudo, energia));
        }
        archivo.close();
    }
}

Personaje* agregarPersonaje(string nombre, string elemento, float vida, int escudo, int energia){
    Personaje *nuevoPersonaje;
    if(elemento == ELEMENTO_AGUA){
        nuevoPersonaje = new PersonajeAgua(nombre,elemento,ALIMENTO_AGUA,vida,energia,escudo);
    }
    else if(elemento == ELEMENTO_FUEGO){
        nuevoPersonaje = new PersonajeFuego(nombre,elemento,ALIMENTO_FUEGO,vida,energia,escudo);
    }
    else if(elemento == ELEMENTO_TIERRA){
        nuevoPersonaje = new PersonajeTierra(nombre,elemento,ALIMENTO_TIERRA,vida,energia,escudo);
    }
    else{
         nuevoPersonaje = new PersonajeAire(nombre,elemento,ALIMENTO_AIRE,vida,energia,escudo);
    }
    return nuevoPersonaje;
}

int valorRandom(int maximo, int minimo){
    return (minimo + rand() % (maximo - minimo + 1));
}

void imprimirMenuOpciones(){
    cout << endl << "1) Agregar un nuevo personaje.";
    cout << endl << "2) Eliminar un personaje.";
    cout << endl << "3) Mostrar nombres de los personajes.";
    cout << endl << "4) Buscar por nombre los detalles de un personaje en particular.";
    cout << endl << "5) Salir.";
    cout << endl << "6) Comenzar juego." << endl;

}


void procesarOpcion(ABB* diccionario,bool &comenzar){
    char opcion;
    bool salir = false;

    while (!salir){
        imprimirMenuOpciones();
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        fflush(stdin);
        switch (opcion) {
            case AGREGAR_PERSONAJE:
                menuCreacionPersonaje(diccionario);
                break;
            case ELIMINAR_PERSONAJE:
                menuEliminacionPersonaje(diccionario);
                break;
            case MOSTRAR_NOMBRES:
                mostrarNombres(diccionario);
                break;
            case BUSCAR_PERSONAJE:
                buscarPersonaje(diccionario);
                break;
            case SALIR:
                salir = true;
                break;
            case COMENZAR_JUEGO:
                comenzar = true;
                salir = true;
                break;
            default:
                cout << "ERROR: Ingrese una opcion valida" << endl;
        }
    }
}

void imprimirMenuCreacion(){
    cout << endl << "ELEMENTO DE PERSONAJE";
    cout << endl << "1) AGUA";
    cout << endl << "2) FUEGO";
    cout << endl << "3) TIERRA";
    cout << endl << "4) AIRE";
    cout << endl << "Ingrese su opcion (numero): ";
}

string definirElemento(int opcion){
    string elemento;
    switch (opcion) {
        case OPCION_AGUA:
            elemento = ELEMENTO_AGUA;
            break;
        case OPCION_FUEGO:
            elemento = ELEMENTO_FUEGO;
            break;
        case OPCION_TIERRA:
            elemento = ELEMENTO_TIERRA;
            break;
        case OPCION_AIRE:
            elemento = ELEMENTO_AIRE;
            break;
    }
    return elemento;
}

void validarValor(int minimo, int maximo, int &opcion){
    while(opcion < minimo || opcion > maximo){
        cout << "ERROR: Ingrese un numero entre " << minimo << " y " << maximo << ": ";
        cin >> opcion;
    }
}

void validarNombre(string &nombre,ABB* diccionario){
    while (diccionario->buscar(nombre)){
        cout << endl << "ERROR: Ya existe un personaje con ese nombre, ingrese otro: ";
        cin >> nombre;
    }
}

void menuCreacionPersonaje(ABB* diccionario){
    string nombre, elemento;
    float vida;
    int energia, escudo, opcion;

    imprimirMenuCreacion();
    cin >> opcion;
    validarValor(1, 4, opcion);
    elemento = definirElemento(opcion);

    cout << endl << "Ingrese su nombre: ";
    cin >> nombre;
    validarNombre(nombre,diccionario);

    vida = (float)valorRandom(VIDA_MAXIMA,VIDA_MINIMA);
    escudo = valorRandom(ESCUDO_MAXIMO,ESCUDO_MINIMO);
    energia = valorRandom(ENERGIA_MAXIMA,ENERGIA_MINIMA);

    diccionario -> insertar(agregarPersonaje(nombre,elemento,vida,escudo,energia));
}

void mostrarNombres(ABB* diccionario){

    if(!diccionario->vacio()) {
        cout << endl << "LISTA DE PERSONAJES" << endl;
        diccionario->imprimirEnOrden();
    }
    else
        cout << endl << "LISTA VACIA" << endl;
}

void menuEliminacionPersonaje(ABB* diccionario){
    string nombre;
    if(!diccionario -> vacio()) {
        cout << endl << "Ingrese el nombre del personaje que desea eliminar: ";
        cin >> nombre;
        if(diccionario -> buscar(nombre)){
            diccionario -> borrarDato(nombre);
        }
        else
            cout << endl << "ERROR: No existe un personaje con ese nombre";
    }
    else
        cout << endl << "LISTA VACIA" << endl;
}

void mostrarEstadisticas(ABB* diccionario, string clave){
    cout << endl << "Nombre: " << diccionario -> obtenerPersonaje(clave) -> obtenerNombre();
    cout << endl << "Elemento: " << diccionario -> obtenerPersonaje(clave) -> obtenerElemento();
    cout << endl << "Valor de Vida: " << diccionario -> obtenerPersonaje(clave) -> obtenerVida();
    cout << endl << "Valor de Escudo: " << diccionario -> obtenerPersonaje(clave) -> obtenerEscudo();
    cout << endl << "Valor de Energia: " << diccionario -> obtenerPersonaje(clave) -> obtenerEnergia() << "/" << ENERGIA_MAXIMA;
    cout << endl << "Alimento: " << diccionario -> obtenerPersonaje(clave) -> obtenerAlimento() << endl;
}

void buscarPersonaje(ABB* diccionario){
    string nombre;
    if(!diccionario->vacio()) {
        cout << "Ingrese el nombre del personaje: ";
        cin >> nombre;
        if(diccionario->buscar(nombre))
            mostrarEstadisticas(diccionario,nombre);
        else
            cout << "No existe personaje con ese nombre" << endl;
    }
    else
        cout << endl << "LISTA VACIA" << endl;
}


void selecionPersonajes(ABB* diccionario, Personaje* vector1[], Personaje* vector2[]){
    char opcion;
    bool salir;
    for(int contador = 0; contador < MAX_PERSONAJES; contador++){
        for(int jugador = 1; jugador <= 2; jugador++) {
            salir = false;
            while(!salir){
                fflush(stdin);
                imprimirMenuSeleccion(jugador);
                cout << "Ingrese una opcion: ";
                cin >> opcion;
                fflush(stdin);
                cout << endl;

                switch(opcion){
                    case BUSCAR:
                        buscarPersonaje(diccionario);
                        break;
                    case MOSTRAR:
                        mostrarNombres(diccionario);
                        break;
                    case SELECCIONAR:
                        if(jugador == 1)
                            vector1[contador] = seleccionarPersonaje(diccionario);
                        else
                            vector2[contador] = seleccionarPersonaje(diccionario);
                        salir = true;
                        break;
                    default:
                        cout << "Opcion incorrecta" << endl;
                }
            }
        }
    }
}

void imprimirMenuSeleccion(int jugador){
    cout << endl << "JUGADOR " << jugador;
    cout << endl << "1)Buscar por nombre los detalles de un personaje particular";
    cout << endl << "2)Mostrar todos los nombres de los personajes habilitados";
    cout << endl << "3)Seleccionar personaje" << endl;
}

Personaje* seleccionarPersonaje(ABB* diccionario){
    fflush(stdin);
    string nombre;
    cout << "Ingrese el nombre del personaje que desea agregar: ";
    cin >> nombre;
    while(!diccionario -> buscar(nombre) || !diccionario -> obtenerPersonaje(nombre) -> estaHabilitado()){
        diccionario -> imprimirEnOrden();
        cout << endl << "ERROR: Ese nombre de personaje no existe o ya fue elegido, reingrese el nombre: ";
        cin >> nombre;
    }
    diccionario -> obtenerPersonaje(nombre) -> elegido();
    return diccionario -> obtenerPersonaje(nombre);
}

void posicionamiento(Personaje* vector[], grafo* mapa, int i, string jugador){
    mapa -> dibujarMapa();
    int fila, columna;
    cout << "\n\nIngrese la fila y columna donde va a ubicar al personaje >> " << vector[i]->obtenerNombre() << " <<\n";
    cout << "Fila: ";
    cin >> fila;
    fila--;
    cout << "Columna: ";
    cin >> columna;
    columna--;
    comprobarPosicion(&fila, &columna, mapa);
    mapa -> obtenerVertice(fila,columna) -> ubicarPersonaje(vector[i],jugador);
    vector[i] -> asignarFila(fila);
    vector[i] -> asignarColumna(columna);

}

void comprobarPosicion(int *fila, int *columna, grafo* mapa){
    while((*fila < 0 || *fila >= FILAS) || (*columna < 0 || *columna >= COLUMNAS) || (mapa -> obtenerVertice(*fila,*columna) -> estaOcupado())) {
        cout << "ERROR: Esa posicion (fila,columna) no existe o ya esta ocupada, reeingrese los valores" << endl;
        cout << "Fila: ";
        cin >> *fila;
        cout << "Columna: ";
        cin >> *columna;
        (*fila)--;
        (*columna)--;
    }
}

void posicionarPersonajes(Personaje* vector1[], Personaje* vector2[], grafo* mapa, int primerJugador){
    int turno = 0;
    cout << endl << "JUEGO COMENZADO, POSICIONEN SUS PERSONAJES!" << endl;
    while(turno < MAX_PERSONAJES) {
            cout << "TURNO " << turno + 1 << endl;
            if (primerJugador == 1) {
                cout << "JUGADOR 1" << endl;
                posicionamiento(vector1,mapa,turno,"1");
                cout << "JUGADOR 2" << endl;
                posicionamiento(vector2,mapa,turno,"2");
            }
            else {
                cout << "JUGADOR 2" << endl;
                posicionamiento(vector2, mapa, turno, "2");
                cout << "JUGADOR 1" << endl;
                posicionamiento(vector1, mapa, turno, "1");
                }
            turno++;
    }
    cout << endl << "POSICION FINAL DE LOS PERSONAJES" << endl;
    mapa->dibujarMapa();
}

void elegirAccion(Personaje* vector[], grafo* mapa,int jugador){
    int contador = 0;
    while(contador < MAX_PERSONAJES){
        if(vector[contador] -> estaVivo()){
            cout << endl << endl;
            fflush(stdin);
            mapa -> dibujarMapa();
            mostrarEstadoPersonajes(vector[contador], vector[contador] -> obtenerFila(), vector[contador] -> obtenerColumna(),jugador);
            menuAccionesMovimiento(vector, mapa, contador);
            cout << endl << endl;
            fflush(stdin);
            mapa -> dibujarMapa();
            mostrarEstadoPersonajes(vector[contador], vector[contador] -> obtenerFila(), vector[contador] -> obtenerColumna(),jugador);
            menuAccionesAtaque(vector, mapa, contador);
        }
        else {
            cout << endl << "A " << vector[contador] -> obtenerNombre() << " se le acabaron sus puntos de vida" << endl;
            mapa -> obtenerVertice(vector[contador] -> obtenerFila(),vector[contador] -> obtenerColumna()) -> reestablecerOcupante();
        }
        contador++;
    }
}

void mostrarEstadoPersonajes(Personaje* personaje, int fila, int columna,int jugador){
    cout << endl << "Jugador " << jugador << endl;
    cout << "Elemento: " << personaje -> obtenerElemento() << endl;
    cout << "Nombre: " << personaje -> obtenerNombre() << endl;
    cout << "Vida: " << personaje -> obtenerVida() << "/" << VIDA_MAXIMA << endl;
    cout << "Energia: " << personaje -> obtenerEnergia() << "/" << ENERGIA_MAXIMA << endl;
    cout << "Escudo: " << personaje -> obtenerEscudo() << "/" << ESCUDO_MAXIMO << endl;
    cout << "Posicion del personaje" << endl << "FILA: " << fila + 1 << endl << "COLUMNA: " << columna + 1 << endl;
}

void mostrarMenuAccionesMovimiento(int &opcion,Personaje* personaje){
    fflush(stdin);
    cout << endl << "1) Alimentarse.";
    cout << endl << "2) Moverse.";
    cout << endl << "3) Pasar opcion.";
    cout << endl << "Ingrese su opcion: ";
    cin >> opcion;
    validarValor(ALIMENTARSE,PASAR_OPCION,opcion);
}

void mostrarMenuAccionesAtaque(int &opcion, Personaje* personaje){
    fflush(stdin);
    cout << endl << "1) Defenderse (COSTO DE ENERGIA: " << personaje -> obtenerCostoDefenderse() << ").";
    cout << endl << "2) Atacar. (COSTO DE ENERGIA: " << personaje -> obtenerCostoAtaque() << ").";
    cout << endl << "3) Pasar opcion.";
    cout << endl << "Ingrese su opcion: ";
    cin >> opcion;
    validarValor(DEFENDERSE,PASAR_OPCION,opcion);
}

void menuAccionesMovimiento(Personaje* vector[], grafo* mapa, int i){
    bool salir = false;
    int opcion;
    while(!salir) {
        fflush(stdin);
        mostrarMenuAccionesMovimiento(opcion, vector[i]);
        switch (opcion) {
            case ALIMENTARSE:
                vector[i] -> alimentarPersonaje();
                salir = true;
                break;
            case MOVERSE:
                moverPersonaje(vector,i,mapa);
                salir = true;
                break;
            case PASAR_OPCION:
                salir = true;
                break;
            default:
                cout << endl << "ERROR: Opcion incorrecta" << endl;
        }
    }
}

void menuAccionesAtaque(Personaje* vector[], grafo* mapa, int i){
    bool salir = false;
    int opcion;
    while(!salir) {
        fflush(stdin);
        mostrarMenuAccionesAtaque(opcion, vector[i]);
        switch (opcion) {
            case DEFENDERSE:
                defenderPersonaje(vector,i,mapa);
                salir = true;
                break;
            case ATACAR:
                if(vector[i] -> puedeAtacar())
                    ataquePersonaje(vector,i,mapa);
                salir = true;
                break;
            case PASAR_OPCION:
                salir = true;
                break;
            default:
                cout << endl << "ERROR: Opcion incorrecta" << endl;
        }
    }

}

void comenzarJuego(Personaje* vector1[], Personaje* vector2[], grafo* mapa, int primerJugador, bool hayPartidaGuardada){
    int turno = 1, jugadorGanador = 0;
    bool juegoTerminado = false;
    bool salir = false;
    while(jugadorGanador == 0 && !salir){
            cout << endl << "TURNO " << turno << endl;
            if (primerJugador == 1) {
                cout << endl << "JUGADOR 1" << endl;
                if(guardar()){
                    guardarPartida(1, vector1, vector2);
                    salir = true;
                }
                else {
                    if (turno != 1 || hayPartidaGuardada)
                        avanzarTurno(juegoTerminado, vector1, jugadorGanador, 2);
                    elegirAccion(vector1, mapa,1);
                    if (turno != 1 || hayPartidaGuardada) {
                        avanzarTurno(juegoTerminado, vector2, jugadorGanador, 1);
                    }
                    cout << endl << "JUGADOR 2" << endl;
                    if (guardar()) {
                        guardarPartida(2, vector1, vector2);
                        salir = true;
                    }
                    else
                        elegirAccion(vector2, mapa,2);
                }
            }
            else {
                cout << endl << "JUGADOR 2" << endl;
                if(guardar()) {
                    guardarPartida(2, vector1, vector2);
                    salir = true;
                }
                else {
                    if (turno != 1 || hayPartidaGuardada)
                        avanzarTurno(juegoTerminado, vector2, jugadorGanador, 1);
                    elegirAccion(vector2, mapa,2);
                    if (turno != 1 || hayPartidaGuardada)
                        avanzarTurno(juegoTerminado, vector1, jugadorGanador, 2);
                    cout << endl << "JUGADOR 1" << endl;
                    if(guardar()){
                        guardarPartida(1, vector1, vector2);
                        salir = true;
                    }
                    else
                        elegirAccion(vector1, mapa,1);
                }
            }
            turno++;
    }
    if(jugadorGanador != 0){
        cout << endl << "JUEGO TERMINADO" << endl << "JUGADOR GANADOR: " << jugadorGanador;
        if(hayPartidaGuardada)
            remove("../partida.csv");
    }
}

void moverPersonaje(Personaje* vector[], int i, grafo* mapa){
    int fila, columna, opcion;
    bool sePuedeMover = false;
    bool salir = false;
    string jugador  = mapa -> obtenerVertice(vector[i] -> obtenerFila(),vector[i] -> obtenerColumna()) -> ocupadoPor;
    while(!sePuedeMover && !salir ) {
        mapa -> dibujarMapa();
        cout << "Ingrese la fila y columna donde ubicara su personaje" << endl;
        cout << "Fila: ";
        cin >> fila;
        cout << "Columna: ";
        cin >> columna;
        fila--;
        columna--;
        comprobarPosicion(&fila, &columna, mapa);
        sePuedeMover = mapa -> puedeMoverse(vector[i],fila,columna);
        if(!sePuedeMover) {
            cout << "Que desea hacer?" << endl << "1) Ingresar otra posicion" << endl << "2) Salir" << endl
                 << "Ingrese su opcion (numero): ";
            cin >> opcion;
            validarValor(1, 2, opcion);
        }
        if(opcion == 2)
            salir = true;

    }
    if(sePuedeMover)
        mapa -> moverPersonaje(vector[i], fila, columna, jugador);

}


void defenderPersonaje(Personaje* vector[], int i, grafo* mapa){
    string tipoElemento = vector[i] -> obtenerElemento();
    if(tipoElemento == ELEMENTO_AIRE)
    {   if(vector[i] -> obtenerEnergia() >= COSTO_ENERGIA_DEFENSA_AIRE ) {
            int filaActual = vector[i] -> obtenerFila();
            int columnaActual = vector[i] -> obtenerColumna();
            string jugador = mapa -> obtenerVertice(filaActual, columnaActual) -> obtenerJugadorOcupante();
            mapa -> obtenerVertice(filaActual, columnaActual)->reestablecerOcupante();
            posicionamiento(vector, mapa, i, jugador);
        }
        vector[i] -> defenderse();
    }
    else if(tipoElemento == ELEMENTO_AGUA){
        if(vector[i] -> obtenerEnergia() >= COSTO_ENERGIA_DEFENSA_AGUA){
            for(int k = 0; k < MAX_PERSONAJES; k++)
                if(k != i && vector[k] -> estaVivo()) {
                    if (vector[k] -> obtenerVida() + VIDA_RECUPERADA_ALIADOS_AGUA < VIDA_MAXIMA)
                        vector[k] -> asignarVida(vector[k]->obtenerVida() + VIDA_RECUPERADA_ALIADOS_AGUA);
                    else
                        vector[k] -> asignarVida(VIDA_MAXIMA);
                }
        }
        vector[i] -> defenderse();
    }
    else
        vector[i] -> defenderse();
}

void ataquePersonaje(Personaje* vector[], int i, grafo* mapa){
    string tipoElemento = vector[i] -> obtenerElemento();
    mapa -> dibujarMapa();
    if (tipoElemento == ELEMENTO_FUEGO)
        ataqueFuego(vector, i, mapa);
    else if (tipoElemento == ELEMENTO_TIERRA)
        ataqueTierra(vector, i, mapa);
    else if (tipoElemento == ELEMENTO_AGUA) {
        ataqueAgua(vector, i, mapa);
    }
    else
        ataqueAire(vector, i, mapa);
}


void ataqueFuego(Personaje* vector[], int i, grafo* mapa){
    int filaActual = vector[i] -> obtenerFila();
    int columnaActual = vector[i] -> obtenerColumna();
    string jugador = mapa -> obtenerVertice(filaActual,columnaActual) -> obtenerJugadorOcupante();
    cout << endl << vector[i] -> obtenerNombre() << " utiliza ataque LLAMARADA DE FUEGO, atacando las filas " << filaActual << ", " << filaActual + 1 << " y " << filaActual + 2 << endl;

    for(int j = 0; j < COLUMNAS; j++){
        if (mapa -> obtenerVertice(filaActual,j) -> estaOcupado() && mapa -> obtenerVertice(filaActual,j) -> obtenerJugadorOcupante() != jugador)
            mapa -> obtenerVertice(filaActual,j) -> ocupante -> recibirAtaque(vector[i]);
        if (filaActual - 1 >= 0)
            if (mapa -> obtenerVertice(filaActual - 1,j) -> estaOcupado() && mapa -> obtenerVertice(filaActual - 1,j) -> obtenerJugadorOcupante() != jugador)
                mapa -> obtenerVertice(filaActual - 1,j) -> ocupante -> recibirAtaque(vector[i]);
        if (filaActual + 1 < FILAS)
            if (mapa -> obtenerVertice(filaActual + 1,j) -> estaOcupado() && mapa -> obtenerVertice(filaActual + 1,j) -> obtenerJugadorOcupante() != jugador)
                mapa -> obtenerVertice(filaActual + 1,j) -> ocupante -> recibirAtaque(vector[i]);
    }

}

void ataqueAgua(Personaje* vector[], int i, grafo* mapa){
    int fila, columna;
    int filaActual = vector[i] -> obtenerFila();
    int columnaActual = vector[i] -> obtenerColumna();
    string jugador = mapa -> obtenerVertice(filaActual,columnaActual) -> obtenerJugadorOcupante();
    cout << endl << "Ingrese la fila y columna de la posicion que desea atacar" << endl;
    cout << "Fila: ";
    cin >> fila;
    validarValor(0,FILAS,fila);
    cout << "Columna: ";
    cin >> columna;
    validarValor(0,COLUMNAS,columna);
    fila--;
    columna--;
    cout << vector[i] -> obtenerNombre() << " utiliza ataque GEISER en la posicion [" << fila + 1 << "][" << columna + 1 << "]" << endl << endl;
    if (mapa -> obtenerVertice(fila,columna) -> estaOcupado() && mapa -> obtenerVertice(fila, columna) -> obtenerJugadorOcupante() != jugador){
        mapa -> obtenerVertice(fila,columna) -> ocupante -> recibirAtaque(vector[i]);
    }
    else
        cout << endl << "Ataque fallado!!" << endl;
}

void ataqueAire(Personaje* vector[], int i, grafo* mapa){
    int fila = vector[i] -> obtenerFila();
    int columna = vector[i] -> obtenerColumna();
    string jugador = mapa -> obtenerVertice(fila,columna) -> obtenerJugadorOcupante();
    string elemento;
    cout << vector[i] -> obtenerNombre() << " ha desatado un TORNADO que produce danio a todo el mapa" << endl;
    for(int k = 0; k < FILAS; k++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (mapa -> obtenerVertice(k, j) -> estaOcupado() && mapa -> obtenerVertice(k, j) -> obtenerJugadorOcupante() != jugador) {
                mapa -> obtenerVertice(k, j) -> ocupante -> recibirAtaque(vector[i]);
            }
        }
    }
}

void ataqueTierra(Personaje* vector[], int i, grafo* mapa) {
    int filaActual = vector[i] -> obtenerFila();
    int columnaActual = vector[i] -> obtenerColumna();
    float vidaActual;
    string jugador = mapa -> obtenerVertice(filaActual,columnaActual) -> obtenerJugadorOcupante();
    string tipoElemento;
    cout << endl << vector[i] -> obtenerNombre() << " utiliza ataque TERREMOTO que se expande por todo el mapa" << endl;

    for(int k = 0; k < FILAS; k++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (mapa -> obtenerVertice(k, j) -> estaOcupado()) {
                if (mapa -> obtenerVertice(k, j) -> obtenerJugadorOcupante() != jugador) {
                    tipoElemento = mapa -> obtenerVertice(k, j) -> ocupante -> obtenerElemento();
                    float danioReducido = mapa -> obtenerVertice(k, j) -> ocupante -> obtenerDanioRecibido();

                    if (tipoElemento == ELEMENTO_AIRE) {
                        mapa->obtenerVertice(k, j) -> ocupante -> recibirAtaque(vector[i]);
                    }
                    else {
                        if ((k <= filaActual + ZONA_MARRON_OSCURO && k >= filaActual - ZONA_MARRON_OSCURO) && (j <= columnaActual + ZONA_MARRON_OSCURO && j >= columnaActual - ZONA_MARRON_OSCURO)) {
                            mapa -> obtenerVertice(k, j) -> ocupante -> recibirAtaque(vector[i]);
                            vidaActual = mapa->obtenerVertice(k, j) -> ocupante -> obtenerVida();
                            mapa -> obtenerVertice(k, j) -> ocupante -> asignarVida(
                                    vidaActual - (ATAQUE_ZONA_MARRON_OSCURO * danioReducido));
                            cout << endl << mapa->obtenerVertice(k, j) -> ocupante -> obtenerNombre() << " ha recibido "
                                 << ATAQUE_ZONA_MARRON_OSCURO * danioReducido
                                 << " puntos de danio por encontrarse en el epicentro del TERREMOTO" << endl;
                            cout << "Vida actual: " << mapa -> obtenerVertice(k, j) -> ocupante -> obtenerVida()
                                 << "\n\n";

                        }
                        else{
                            if ((k > filaActual + ZONA_MARRON || k < filaActual - ZONA_MARRON) || (j > columnaActual + ZONA_MARRON || j < columnaActual - ZONA_MARRON)) {
                                mapa->obtenerVertice(k, j) -> ocupante -> recibirAtaque(vector[i]);
                                vidaActual = mapa->obtenerVertice(k, j) -> ocupante -> obtenerVida();
                                mapa->obtenerVertice(k, j) -> ocupante -> asignarVida(
                                        vidaActual - (ATAQUE_ZONA_MARRON_CLARO * danioReducido));
                                cout << endl << mapa->obtenerVertice(k, j)->ocupante->obtenerNombre() << " ha recibido "
                                     << ATAQUE_ZONA_MARRON_CLARO * danioReducido
                                     << " puntos de danio por encontrarse lejos del epicentro del TERREMOTO" << endl;
                                cout << "Vida actual: " << mapa->obtenerVertice(k, j)->ocupante->obtenerVida()
                                     << "\n\n";
                            }
                            else{
                                mapa -> obtenerVertice(k, j) -> ocupante -> recibirAtaque(vector[i]);
                                vidaActual = mapa->obtenerVertice(k, j) -> ocupante -> obtenerVida();
                                mapa -> obtenerVertice(k, j) -> ocupante -> asignarVida(
                                        vidaActual - (ATAQUE_ZONA_MARRON * danioReducido));
                                cout << endl << mapa -> obtenerVertice(k, j) -> ocupante -> obtenerNombre() << " ha recibido "
                                     << ATAQUE_ZONA_MARRON * danioReducido
                                     << " puntos de danio por encontrarse cerca del epicentro del TERREMOTO" << endl;
                                cout << "Vida actual: " << mapa -> obtenerVertice(k, j) -> ocupante -> obtenerVida()
                                     << "\n\n";
                            }
                        }
                    }
                }
            }
        }
    }
}

void avanzarTurno(bool &juegoTerminado, Personaje* vector[], int &jugadorGanador, int jugador){
    int i = 0, energia;
    string tipoElemento;
    juegoTerminado = true;
    while(i < MAX_PERSONAJES && juegoTerminado){
        if(vector[i] -> estaVivo())
            juegoTerminado = false;
        i++;
    }

    if(juegoTerminado)
        jugadorGanador = jugador;

    for(i = 0; i < MAX_PERSONAJES; i++){
        tipoElemento = vector[i] -> obtenerElemento();
        if(vector[i] -> estaVivo()) {
            if (tipoElemento == ELEMENTO_TIERRA)
                if (vector[i] -> estaDefendiendose()) {
                    vector[i] -> asignarEscudo(vector[i] -> obtenerEscudo() - ESCUDO_MAXIMO);
                    cout << endl << vector[i] -> obtenerNombre()
                         << "(TIERRA) ha perdido la habilidad DUREZA, volviendo a su escudo normal: "
                         << vector[i] -> obtenerEscudo() << endl;
                    vector[i] -> cambiarEstadoDefensa(FALSO);
                }
            if (tipoElemento == ELEMENTO_FUEGO)
                if (vector[i]->obtenerEnergia() == ENERGIA_MINIMA) {
                    vector[i]->asignarVida(vector[i]->obtenerVida() - VIDA_PERDIDA_POR_TURNO_FUEGO);
                    cout << endl << vector[i]->obtenerNombre() << "(FUEGO) ha perdido " << VIDA_PERDIDA_POR_TURNO_FUEGO
                         << " puntos de vida por tener 0 puntos de energia" << endl;
                }
            if (tipoElemento == ELEMENTO_AIRE) {
                energia = vector[i] -> obtenerEnergia() + ENERGIA_RECUPERADA_POR_TURNO_AIRE;
                vector[i] -> asignarEnergia(energia);
                cout << endl << vector[i] -> obtenerNombre() << "(AIRE) ha ganado " << ENERGIA_RECUPERADA_POR_TURNO_AIRE
                     << " puntos de energia por ser de tipo AIRE" << endl;
            }
        }
    }
}

void guardarPartida(int primerJugador, Personaje* vector1[], Personaje* vector2[]){
    int contador = 0;
    int i = 0, j = 0;
    bool vector1Cargado = false;
    fstream archivo;
    archivo.open("../partida.csv", ios::out);
    archivo << primerJugador << "\n";
    while(j < MAX_PERSONAJES){
        if(contador >= MAX_PERSONAJES) {
            if(vector2[j] -> obtenerElemento() == ELEMENTO_TIERRA && vector2[j] -> estaDefendiendose())
                archivo << 1 << ",";
            else
                archivo << 0 << ",";
            archivo << vector2[j] -> obtenerElemento() << ",";
            archivo << vector2[j] -> obtenerNombre() << ",";
            archivo << vector2[j] -> obtenerEscudo() << ",";
            archivo << vector2[j] -> obtenerVida() << ",";
            archivo << vector2[j] -> obtenerEnergia() << ",";
            archivo << vector2[j] -> obtenerFila() << ",";
            archivo << vector2[j] -> obtenerColumna() << "\n";
            j++;
        }
        else {
            if(vector1[i] -> obtenerElemento() == ELEMENTO_TIERRA && vector1[i] -> estaDefendiendose())
                archivo << 1 << ",";
            else
                archivo << 0 << ",";
            archivo << vector1[i] -> obtenerElemento() << ",";
            archivo << vector1[i] -> obtenerNombre() << ",";
            archivo << vector1[i] -> obtenerEscudo() << ",";
            archivo << vector1[i] -> obtenerVida() << ",";
            archivo << vector1[i] -> obtenerEnergia() << ",";
            archivo << vector1[i] -> obtenerFila() << ",";
            archivo << vector1[i] -> obtenerColumna() << "\n";
            i++;
        }
        contador++;
    }
    archivo.close();
}


bool guardar(){
    fflush(stdin);
    int opcion;
    cout << endl << "Desea guardar y salir de la partida?" << endl << "1) Si." << endl << "2) No." << endl << "Ingrese su opcion(numero): ";
    cin >> opcion;
    validarValor(1,2,opcion);
    if(opcion == 1)
        return true;
    else
        return false;
}
















