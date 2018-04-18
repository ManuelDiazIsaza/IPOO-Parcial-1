/*
  Archivo: voto.h
  Autor: Manuel Diaz, Jeffrey Rios
  Email: manuel.isaza@correounivalle.edu.co, jeffrey.rios@correounivalle.edu.co
  Fecha creación: 2018-04-17
  Fecha Última modificación: 2018-04-17
  Versión: 0.1
  Licencia: GPL
*/

// Clase: Voto
// Responsabilidad: Administrar informacion de un voto
// Colaboracion: Ninguna

#ifndef PARCIAL1_VOTO_H
#define PARCIAL1_VOTO_H

#include <string>
#include <vector>

using namespace std;

class Voto
{
private:
    int cedulaVotante;
    int cedulaVotado;
public:
    Voto();
    ~Voto();

};

#endif //PARCIAL1_VOTO_H