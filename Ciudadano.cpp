/*
  Archivo: Ciudadano.cpp
  Autor: Manuel Diaz Cod 1741652, Jeffrey Rios Cod 1744831
  Email: manuel.isaza@correounivalle.edu.co, jeffrey.rios@correounivalle.edu.co
  Fecha creación: 2018-04-17
  Fecha Última modificación: 2018-04-18
  Versión: 0.1
  Licencia: GPL
*/

// Clase: Ciudadano
// Responsabilidad: Administrar informacion de un Ciudadano
// Colaboracion: Ninguna

#include "Ciudadano.h"
#include <iomanip>
#include <iostream>

using namespace std;

Ciudadano::Ciudadano()
{
}

Ciudadano::Ciudadano(string nombre, int cedula, string ciudad, string departamento, string partido, int tipoCiudadano)
{
    this -> nombre = nombre;
    this -> cedula = cedula;
    this -> ciudad = ciudad;
    this -> departamento = departamento;
    this -> partidaPolitico = partido;
    this -> tipoCiudadano = tipoCiudadano;

}

Ciudadano::~Ciudadano()
{
    //Método destructor
}

void Ciudadano::setNombre(string nombre)
{
    this -> nombre = nombre;
}

string Ciudadano::getNombre()
{
    return nombre;
}

void Ciudadano::setCedula(int cedula)
{
    this -> cedula = cedula;

}

int Ciudadano::getCedula()
{
    return cedula;
}

void Ciudadano::setCiudad(string ciudad)
{
    this -> ciudad = ciudad;
}

string Ciudadano::getCiudad()
{
    return ciudad;
}

void Ciudadano::setDepartamento(string departamento)
{
    this -> departamento = departamento;
}

string Ciudadano::getDepartamento()
{
    return departamento;
}

void Ciudadano::setPartido(string partido)
{
    this -> partidaPolitico = partido;
}

string Ciudadano::getPartido()
{
    return partidaPolitico;
}

void Ciudadano::setTipo(int tipo)
{
    this -> tipoCiudadano = tipo;
}

int Ciudadano::getTipo()
{
    return tipoCiudadano;
}




