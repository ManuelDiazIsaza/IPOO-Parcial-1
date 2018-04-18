/*
  Archivo: main.cpp
  Autor: Manuel Diaz Cod 1741652, Jeffrey Rios Cod 1744831
  Email: manuel.isaza@correounivalle.edu.co, jeffrey.rios@correounivalle.edu.co
  Fecha creación: 2018-04-17
  Fecha Última modificación: 2018-04-18
  Versión: 0.1
  Licencia: GPL
*/

// Clase: Main
// Responsabilidad: Inicializacion del programa
// Colaboracion: Ninguna

/*Este programa permite manejar las inscripciones de ciudadanos a una votacion presidencial, ademas de realizar como tal el
proceso de votacion, tanto para primera como segunda vuelta y mostrar las estadisticas pertinentes.*/


#include <iostream>
#include "Votacion.h"

int main() {

    Votacion votaciones;
    votaciones.interfazPrincipal();

    return 0;
}