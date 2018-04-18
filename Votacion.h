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

#ifndef PARCIAL1_VOTACION_H
#define PARCIAL1_VOTACION_H

#include <string>
#include <vector>
#include "Ciudadano.h"


using namespace std;

class Votacion
{
private:
    vector<Ciudadano> votantes;
    vector<Ciudadano> candidatos;
    vector<Ciudadano> candidatosV2;
    vector<int> votosPrimeraVuelta;
    vector<int> votosSegundaVuelta;
    vector<int> yaVotoPrimera;
    vector<int> yaVotoSegunda;
    vector<int> votosTotalPrimera;
    vector<int> votosTotalSegunda;
    bool inscripcionesAbiertas;
    bool votacionesAbiertas =  false;
    int queVuelta=1;
public:
    Votacion();
    ~Votacion();
    void interfazPrincipal();
    void setInscripcionesAbiertas(bool inscripcionesAbiertas);
    bool getInscripcionesAbiertas();
    void registrarCiudadano();
    bool buscarCiudadano(int cedula);
    void consultarCiudadano();
    void cerrarOAbrirInscripciones();
    void cerrarOAbrirVotaciones();
    void realizarVotacion();
    int cedulaPorPosicion(int posicion);
    int cedulaPorPosicion2(int posicion);
    bool cedulaYaVoto(int cedula, int vuelta);
    void finalizarVuelta();
    void contarVotos(int vuelta);



};

#endif //PARCIAL1_VOTACION_H
