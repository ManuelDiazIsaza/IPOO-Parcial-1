/*
  Archivo: Votacion.h
  Autor: Manuel Diaz Cod 1741652, Jeffrey Rios Cod 1744831
  Email: manuel.isaza@correounivalle.edu.co, jeffrey.rios@correounivalle.edu.co
  Fecha creación: 2018-04-17
  Fecha Última modificación: 2018-04-18
  Versión: 0.1
  Licencia: GPL
*/

// Clase: Votacion
// Responsabilidad: Administrar informacion y procesos de una votacion presidencial en Colombia
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
    vector<Ciudadano> votantes; // Votantes inscritos para la votacion
    vector<Ciudadano> candidatos; // Candidatos inscritos para la primera vuelta
    vector<Ciudadano> candidatosV2; // Candidatos que pasan a la segunda vuelta
    vector<int> votosPrimeraVuelta; // Todos los votos hechos en la primera vuelta
    vector<int> votosSegundaVuelta; // Todos los votos hechos en la segunda vuelta
    vector<int> yaVotoPrimera; // Cedulas que ya votaron en la primera vuelta
    vector<int> yaVotoSegunda; // Cedulas que ya votaron en la segunda vuelta
    vector<int> votosTotalPrimera; // Votos totales por candidato en la primera vuelta
    vector<int> votosTotalSegunda; // Votos totales por candidato en la segunda vuelta
    bool inscripcionesAbiertas; // Booleano que determina si las inscripciones estan abiertas o no
    bool votacionesAbiertas =  false; // Booleano que determina si las votaciones estan abiertas o no
    int queVuelta=1; // entero que determina en que vuelta de elecciones estamos
public:
    Votacion();
    ~Votacion();
    void interfazPrincipal(); // Se encarga de manejar la interfaz y menus
    void setInscripcionesAbiertas(bool inscripcionesAbiertas);
    bool getInscripcionesAbiertas();
    void registrarCiudadano(); // Metodo para registrar o inscribir un ciudadano en las votaciones
    bool buscarCiudadano(int cedula); // Busca si un ciudadano esta en las elecciones mediante su numero de cedula
    void consultarCiudadano(); // Metodo para consultar si un ciudadano esta en las votaciones
    void cerrarOAbrirInscripciones(); // Cierra o abre las inscripciones dependiendo su estado actual
    void cerrarOAbrirVotaciones(); //  Cierra o abre las votaciones dependiendo su estado actual
    void realizarVotacion(); // Proceso para realizar votaciones
    int cedulaPorPosicion(int posicion); // Devuelve la cedula de un candidato en la primera vuelta dependiendo de su posicion en el vector
    int cedulaPorPosicion2(int posicion); // Devuelve la cedula de un candidato en la segunda vuelta dependiendo de su posicion en el vector
    bool cedulaYaVoto(int cedula, int vuelta); // Determina si una cedula ya voto pasandole la cedula y el numero de vuelta
    void finalizarVuelta(); // Finaliza una vuelta presidencial (La actual)
    void contarVotos(int vuelta); // Cuenta los votos de cierta vuelta que es el parametro de entrada

};

#endif //PARCIAL1_VOTACION_H
