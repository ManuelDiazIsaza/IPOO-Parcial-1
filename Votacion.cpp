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

#include "Votacion.h"
#include <iomanip>
#include <iostream>

using namespace std;

Votacion::Votacion()
{

}

Votacion::~Votacion()
{
    //Método destructor
}

void Votacion::setInscripcionesAbiertas(bool inscripcionesAbiertas)
{
    this -> inscripcionesAbiertas = inscripcionesAbiertas;
}

bool Votacion::getInscripcionesAbiertas()
{
    return inscripcionesAbiertas;
}

void Votacion::interfazPrincipal() {
    Ciudadano ciudadanoUno("Manuel",1,"Cali","Valle","",1);
    Ciudadano ciudadanoDos("Jeffrey",2,"Cali","Valle","",1);
    Ciudadano ciudadanoTres("Daniel",3,"Bogota","Bogota","",1);
    Ciudadano ciudadanoCuatro("Hider",4,"Medellin","Antioquia","",1);
    Ciudadano ciudadanoCinco("Andres",6,"Buenaventura","Valle","",1);
    Ciudadano ciudadanoSeis("Andrea",7,"Barranquilla","Atlantico","",1);
    Ciudadano ciudadanoSiete("Michelle",8,"Cali","Valle","",1);
    Ciudadano ciudadanoOcho("Carmen",9,"Cali","Valle","",1);
    Ciudadano ciudadanoNueve("Petro",5,"Cali","Valle","Progresistas",2);
    Ciudadano ciudadanoDiez("Duque",10,"Cali","Valle","Centro Democratico",2);


    votantes.push_back(ciudadanoUno);
    votantes.push_back(ciudadanoDos);
    votantes.push_back(ciudadanoTres);
    votantes.push_back(ciudadanoCuatro);
    votantes.push_back(ciudadanoCinco);
    votantes.push_back(ciudadanoSeis);
    votantes.push_back(ciudadanoSiete);
    votantes.push_back(ciudadanoOcho);
    votantes.push_back(ciudadanoNueve);
    votantes.push_back(ciudadanoDiez);
    candidatos.push_back(ciudadanoNueve);
    candidatos.push_back(ciudadanoDiez);


    int opcion =0;
    do{
    cout << ":::::::::::::::::::::::::::::MENU PRINCIPAL:::::::::::::::::::::::"<<endl;
    cout << "1: Registrar ciudadano"<<endl;
    cout << "2: Consultar ciudadano"<<endl;
    if(inscripcionesAbiertas==true)
    {
        cout << "3: Cerrar inscripciones"<<endl;
    }
    else
    {
        cout << "3: Abrir inscripciones"<<endl;
    }
    if(votacionesAbiertas==true)
    {
        cout << "4: Cerrar votaciones"<<endl;
    }
    else
    {
        cout << "4: Abrir votaciones"<<endl;
    }
    cout << "5: Realizar votacion"<<endl;
    cout << "6: Salir"<<endl;
    cout << "Su opcion: "<<endl;
    cin >> opcion;
        switch(opcion){
            case 1:
                if(inscripcionesAbiertas)
                {
                    registrarCiudadano();
                }
                else
                {
                    cout << "Las Inscripciones estan cerradas." << endl;
                }
                break;
            case 2:consultarCiudadano(); break;
            case 3:cerrarOAbrirInscripciones(); break;
            case 4:cerrarOAbrirVotaciones(); break;
            case 5:
                if(!inscripcionesAbiertas && votacionesAbiertas)
                {
                  realizarVotacion();
                }
                else
                {
                    cout << "Las inscripciones estan abiertas o las votaciones estan cerradas por lo tanto no se puede proceder a votar." << endl;

                }

                break;
            case 6:  ; break;
            default:
                if(opcion!=6)
                    cout << endl << "=== Opcion no valida ===" << endl;
        }


    }while(opcion!=6);

}

void Votacion::registrarCiudadano()
{
    string nombre, ciudad, departamento;
    string partidoPolitico = "";
    int cedula, tipo;
    cout << ":::::::::::::::::::::::::::::REGISTRAR CIUDADANO:::::::::::::::::::::::"<<endl;
    do
    {
    cout << "Ingrese la cedula del ciudadano a inscribir: "<<endl;
    cin >> cedula;
    if(buscarCiudadano(cedula))
    {
        cout << "La Cedula ya esta inscrita, por favor digite otra cedula." << endl;
    }
    } while (buscarCiudadano(cedula));
    cout << "Ingrese el nombre del ciudadano a inscribir: "<<endl;
    cin >> nombre;
    cout << "Ingrese la ciudad del ciudadano a inscribir: "<<endl;
    cin >> ciudad;
    cout << "Ingrese el departamento del ciudadano a inscribir: "<<endl;
    cin >> departamento;
    do{
    cout << "Ingrese el tipo de ciudadano a inscribir: "<<endl;
    cout << "1. Votante Regular. "<<endl;
    cout << "2. Candidato. "<<endl;
    cin >> tipo;
    } while (tipo != 1 && tipo !=2);
    if (tipo == 2) {
        cout << "Ingrese el nombre del Partido Politico del Candidato: " << endl;
        cin >> partidoPolitico;
    }
    Ciudadano ciudadanoInscribir(nombre,cedula,ciudad,departamento,partidoPolitico,tipo);
    if(tipo == 1)
    {
        votantes.push_back(ciudadanoInscribir);
    }
    else
    {
        candidatos.push_back(ciudadanoInscribir);
        votantes.push_back(ciudadanoInscribir);
    }
    if(buscarCiudadano(cedula))
    {
    cout << "Inscrito Correctamente."<<endl;
    }
    else
    {
    cout << "Error al registrar Ciudadano.";
    }
}
bool Votacion::buscarCiudadano(int cedula)
{
    bool resultado = false;
    int tamano = votantes.size();
    for (int i = 0 ; i < tamano; i++){
        if(votantes[i].getCedula() == cedula){
            resultado = true;
        }
    }
    return resultado;
}

void Votacion::consultarCiudadano()
{
    int cedula;
    vector<Ciudadano>::iterator it;
    vector<Ciudadano>::iterator encontrado;
    bool resultado = false;
    cout << ":::::::::::::::::::::::::::::CONSULTAR CIUDADANO:::::::::::::::::::::::"<<endl;
    cout << "Ingrese la cedula del ciudadano a consultar: "<<endl;
    cin >> cedula;
    for(it = votantes.begin(); it != votantes.end(); it++){
        if ( (*it).getCedula() == cedula  ){
            resultado = true;
            encontrado = it;
            it = votantes.end()-1;
        }
    }
    if(resultado)
    {
        cout << "El ciudadano de Nombre: "<<  (*encontrado).getNombre() << " esta inscrito para las votaciones." << endl;
    } else
    {
        cout << "El Ciudadano no esta inscrito.";
    }
}

void Votacion::cerrarOAbrirInscripciones()
{
    if(inscripcionesAbiertas == true)
    {
        inscripcionesAbiertas = false;
        cout << "Se han cerrado las inscripciones." << endl;
    }
    else
    {
        inscripcionesAbiertas = true;
        cout << "Se han abierto las inscripciones." << endl;
    }
}

void Votacion::cerrarOAbrirVotaciones()
{
    if(votacionesAbiertas == true)
    {
        votacionesAbiertas = false;
        cout << "Se han cerrado las votaciones." << endl;
    }
    else
    {
        votacionesAbiertas = true;
        cout << "Se han abierto las votaciones." << endl;
    }
}

void Votacion::realizarVotacion()
{
    int salir=1;
    do {
        int cedula;
        cout << ":::::::::::::::::::::::::::::VOTAR:::::::::::::::::::::::" << endl;
        cout << "Por favor digite su cedula: ";
        cin >> cedula;
        if (buscarCiudadano(cedula) && !cedulaYaVoto(cedula, queVuelta)) {
            int opcion;
            cout << "Por quien desea votar: " << endl;
            vector<Ciudadano>::iterator it;
            int numero = 1;
            for (it = candidatos.begin(); it != candidatos.end(); it++) {
                cout << numero << ". " << (*it).getNombre() << " del partido politico " << (*it).getPartido() << endl;
                numero++;
            }
            cin >> opcion;
            if (queVuelta == 1) {
                votosPrimeraVuelta.push_back(cedulaPorPosicion(opcion));
                yaVotoPrimera.push_back(cedula);
            }
            //mostrarVotos();
        } else {
            cout << "Tu cedula no esta inscrita o ya votaste en este vuelta." << endl;
        }
        cout << "Presione 0 si desea salir o presione cualquier otro numero si desea continuar con la votacion" << endl;
        cin >> salir;
    } while (salir != 0);
}

int Votacion::cedulaPorPosicion(int posicion)
{
    vector<Ciudadano>::iterator it;
    int contador=1;
    for(it = candidatos.begin(); it != candidatos.end(); it++)
    {
        if(posicion==contador)
        {
            return (*it).getCedula();
        }
        contador++;
    }
}

void Votacion::mostrarVotos()
{
    vector<int>::iterator it;
    for(it = votosPrimeraVuelta.begin(); it != votosPrimeraVuelta.end(); it++)
    {
            cout << *it;
    }
}

bool Votacion::cedulaYaVoto(int cedula, int vuelta)
{
    bool resultado = false;
    vector<int>::iterator it;
    if(vuelta==1)
    {
    for(it = yaVotoPrimera.begin(); it != yaVotoPrimera.end(); it++)
    {
        if(*it == cedula && vuelta == queVuelta)
        {
            resultado = true;
        }
    }
    return resultado;
    }
    else
    {
    for(it = yaVotoSegunda.begin(); it != yaVotoSegunda.end(); it++)
        {
            if(*it == cedula && vuelta == queVuelta)
            {
                resultado = true;
            }
        }
        return resultado;
    }
}




