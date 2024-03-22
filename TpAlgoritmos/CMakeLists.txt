cmake_minimum_required(VERSION 3.17)
project(TpAlgoritmos)

set(CMAKE_CXX_STANDARD 14)

add_executable(TpAlgoritmos main.cpp personaje.cpp personaje.h utiles.cpp utiles.h personaje_agua.cpp personaje_agua.h personaje_fuego.cpp personaje_fuego.h personaje_tierra.cpp personaje_tierra.h personaje_aire.cpp personaje_aire.h ABBNodo.cpp ABBNodo.h ABB.cpp ABB.h casillero.cpp casillero.h casilleroGris.cpp casilleroGris.h casilleroAzul.cpp casilleroAzul.h casilleroRojo.cpp casilleroRojo.h casilleroVerde.cpp casilleroVerde.h casilleroAmarillo.cpp casilleroAmarillo.h casilleroVioleta.cpp casilleroVioleta.h grafo.cpp grafo.h vertice.cpp vertice.h)