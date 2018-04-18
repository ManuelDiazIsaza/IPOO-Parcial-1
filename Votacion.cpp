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

void Votacion::interfazPrincipal()
{
    Ciudadano ciudadanoUno("Manuel", 1, "Cali", "Valle", "", 1);
    Ciudadano ciudadanoDos("Jeffrey", 2, "Cali", "Valle", "", 1);
    Ciudadano ciudadanoTres("Daniel", 3, "Bogota", "Bogota", "", 1);
    Ciudadano ciudadanoCuatro("Hider", 4, "Medellin", "Antioquia", "", 1);
    Ciudadano ciudadanoCinco("Andres", 6, "Buenaventura", "Valle", "", 1);
    Ciudadano ciudadanoSeis("Andrea", 7, "Barranquilla", "Atlantico", "", 1);
    Ciudadano ciudadanoSiete("Michelle", 8, "Cali", "Valle", "", 1);
    Ciudadano ciudadanoOcho("Carmen", 9, "Cali", "Valle", "", 1);
    Ciudadano ciudadanoNueve("Petro", 5, "Cali", "Valle", "Progresistas", 2);
    Ciudadano ciudadanoDiez("Duque", 10, "Cali", "Valle", "Centro Democratico", 2);
    Ciudadano ciudadanoOnce("Fajardo", 11, "Cali", "Valle", "Alianza Verde", 2);
    Ciudadano ciudadanoDoce("De la Calle", 12, "Cali", "Valle", "Liberal Colombiano", 2);
    Ciudadano ciudadanoTrece("Manuel", 13, "Cali", "Valle", "", 1);
    Ciudadano ciudadanoCatorce("Jeffrey", 14, "Cali", "Valle", "", 1);
    Ciudadano ciudadanoQuince("Daniel", 15, "Bogota", "Bogota", "", 1);
    Ciudadano ciudadano16("Hider", 16, "Medellin", "Antioquia", "", 1);
    Ciudadano ciudadano17("Andres", 17, "Buenaventura", "Valle", "", 1);
    Ciudadano ciudadano18("Andrea", 18, "Barranquilla", "Atlantico", "", 1);


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
    votantes.push_back(ciudadanoOnce);
    votantes.push_back(ciudadanoDoce);
    votantes.push_back(ciudadanoTrece);
    votantes.push_back(ciudadanoCatorce);
    votantes.push_back(ciudadanoQuince);
    votantes.push_back(ciudadano16);
    votantes.push_back(ciudadano17);
    votantes.push_back(ciudadano18);
    candidatos.push_back(ciudadanoNueve);
    candidatos.push_back(ciudadanoDiez);
    candidatos.push_back(ciudadanoOnce);
    candidatos.push_back(ciudadanoDoce);

    votosPrimeraVuelta.push_back(5);
    votosPrimeraVuelta.push_back(5);
    votosPrimeraVuelta.push_back(5);
    votosPrimeraVuelta.push_back(10);
    votosPrimeraVuelta.push_back(10);
    votosPrimeraVuelta.push_back(11);
    votosPrimeraVuelta.push_back(11);
    votosPrimeraVuelta.push_back(12);
    votosPrimeraVuelta.push_back(12);
    votosPrimeraVuelta.push_back(12);
    votosPrimeraVuelta.push_back(12);


    int opcion = 0;
    do
    {
    cout << ":::::::::::::::::::::::::::::MENU PRINCIPAL:::::::::::::::::::::::" << endl;

    if (queVuelta == 1)
    {
        do
        {
            cout << "------------- Estamos en la vuelta 1 -------------" << endl;
            cout << "1: Registrar ciudadano" << endl;
            cout << "2: Consultar ciudadano" << endl;
            if (inscripcionesAbiertas == true) {
                cout << "3: Cerrar inscripciones" << endl;
            } else {
                cout << "3: Abrir inscripciones" << endl;
            }
            if (votacionesAbiertas == true) {
                cout << "4: Cerrar votaciones" << endl;
            } else {
                cout << "4: Abrir votaciones" << endl;
            }
            cout << "5: Realizar votacion" << endl;
            cout << "6: Finalizar Vuelta" << endl;
            cout << "7: Salir" << endl;
            cout << "Su opcion: " << endl;
            cin >> opcion;
            switch (opcion) {
                case 1:
                    if (inscripcionesAbiertas) {
                        registrarCiudadano();
                    } else {
                        cout << "Las Inscripciones estan cerradas." << endl;
                    }
                    break;
                case 2:
                    consultarCiudadano();
                    break;
                case 3:
                    cerrarOAbrirInscripciones();
                    break;
                case 4:
                    cerrarOAbrirVotaciones();
                    break;
                case 5:
                    if (!inscripcionesAbiertas && votacionesAbiertas) {
                        realizarVotacion();
                    } else {
                        cout
                                << "Las inscripciones estan abiertas o las votaciones estan cerradas por lo tanto no se puede proceder a votar."
                                << endl;
                    }
                    break;
                case 6:
                    finalizarVuelta();
                    break;
                default:
                    if (opcion != 7)
                        cout << endl << "=== Opcion no valida ===" << endl;
            }

        }while (opcion != 7 && queVuelta==1);
    }
    else
    {
        cout << "------------- Estamos en la vuelta 2 -------------" << endl;
        cout << "1: Consultar ciudadano" << endl;
        if (votacionesAbiertas == true) {
            cout << "2: Cerrar votaciones" << endl;
        } else {
            cout << "2: Abrir votaciones" << endl;
        }
        cout << "3: Realizar votacion" << endl;
        cout << "4: Finalizar Vuelta" << endl;
        cout << "5: Salir" << endl;
        cout << "Su opcion: " << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                consultarCiudadano();
                break;
            case 2:
                cerrarOAbrirVotaciones();
                break;
            case 3:
                if (!inscripcionesAbiertas && votacionesAbiertas) {
                    realizarVotacion();
                } else {
                    cout
                            << "Las votaciones estan cerradas por lo tanto no se puede proceder a votar."
                            << endl;
                }
                break;
            case 4:
                finalizarVuelta();
                break;
            default:
                if (opcion != 5)
                    cout << endl << "=== Opcion no valida ===" << endl;
        }
    }
        }while(opcion != 5);
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
        if (buscarCiudadano(cedula) && !cedulaYaVoto(cedula, 1) && queVuelta==1) {
            int opcion;
            cout << "Por quien desea votar: " << endl;
            vector<Ciudadano>::iterator it;
            int numero = 1;
            for (it = candidatos.begin(); it != candidatos.end(); it++) {
                cout << numero << ". " << (*it).getNombre() << " del partido politico " << (*it).getPartido() << endl;
                numero++;
            }
            cin >> opcion;

            votosPrimeraVuelta.push_back(cedulaPorPosicion(opcion));
            yaVotoPrimera.push_back(cedula);

            //mostrarVotos();

        }
        else if(buscarCiudadano(cedula) && !cedulaYaVoto(cedula, 2) && queVuelta==2)
        {
            int opcion;
            cout << "Por quien desea votar: " << endl;
            vector<Ciudadano>::iterator it;
            int numero = 1;
            for (it = candidatosV2.begin(); it != candidatosV2.end(); it++) {
                cout << numero << ". " << (*it).getNombre() << " del partido politico " << (*it).getPartido() << endl;
                numero++;
            }
            cin >> opcion;

            votosSegundaVuelta.push_back(cedulaPorPosicion2(opcion));
            yaVotoSegunda.push_back(cedula);
        }
        else
        {
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

int Votacion::cedulaPorPosicion2(int posicion)
{
    vector<Ciudadano>::iterator it;
    int contador=1;
    for(it = candidatosV2.begin(); it != candidatosV2.end(); it++)
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

void Votacion::finalizarVuelta()
{
    if(queVuelta == 1)
    {
        votosTotalPrimera.clear();
        contarVotos(1);
        int cantidadTotalVotantes = votantes.size();
        int cantidadQueVotaron = votosPrimeraVuelta.size();
        double  porcVotantes = (double)cantidadQueVotaron/cantidadTotalVotantes*100;
        cout << cantidadQueVotaron << " total de votos." << endl;
        cout << cantidadTotalVotantes <<" total de votantes registrados." << endl;
        cout << "El porcentaje de personas que votaron respecto a la cantidad de registrados fue: "<< porcVotantes<< "%"<<endl;
        cout << "El porcentaje de abstinencia fue: "<< (double)100-porcVotantes<< "%"<<endl<<endl;
        vector<Ciudadano>::iterator it;
        vector<int>::iterator it2;
        it2 = votosTotalPrimera.begin();
        bool huboGanador;
        for(it = candidatos.begin(); it != candidatos.end(); it++)
        {
            double porcentaje = (double)*it2/cantidadQueVotaron*100;
            cout << "EL candidato de nombre: " << (*it).getNombre() << " obtuvo " << *it2 << " votos."<< " Su porcentaje fue: " << porcentaje <<" %";
            if(cantidadQueVotaron/2+1 <= *it2)
            {
                cout << " Este candidato es el nuevo presidente.";
                huboGanador = true;
            }
            it2++;
            cout << endl;
        }
        cout<<endl<<endl;
        if(!huboGanador) {
            cout << "Estas elecciones pasan a segunda vuelta." << endl;

            vector<Ciudadano> candiTemp = candidatos;
            vector<int> votosTemp = votosTotalPrimera;
            cout << "Los Candidatos que pasan a segunda vuelta son:" << endl;
            for (int i = 0; i < 2; i++) {
                int mayorTemporal = 0;
                for (it2 = votosTemp.begin(); it2 != votosTemp.end(); it2++) {
                    if (*it2 > mayorTemporal) {
                        mayorTemporal = *it2;
                    }
                }
                //cout << mayorTemporal << endl;
                vector<Ciudadano>::iterator it3 = candiTemp.begin();
                int apunt = 0;
                for (it2 = votosTemp.begin(); it2 != votosTemp.end(); it2++) {
                    if (*it2 == mayorTemporal)
                    {
                        candidatosV2.push_back(candiTemp.at(apunt));
                        cout << "El candidato de nombre: " << candidatosV2.at(i).getNombre() << " del partido politico "
                             << candidatosV2.at(i).getPartido() <<
                             " con " << mayorTemporal << " votos y un porcentaje de "
                             << (double) mayorTemporal / cantidadQueVotaron * 100 << " %" << endl;
                        candiTemp.erase(it3);
                        votosTemp.at(apunt) = 0;
                    }
                    apunt++;
                    it3++;

                }

            }
        }
        cout << endl << endl;
    queVuelta = 2;
    }
    else
    {
            votosTotalSegunda.clear();
            contarVotos(2);
            int cantidadTotalVotantes = votantes.size();
            int cantidadQueVotaron = votosSegundaVuelta.size();
            double  porcVotantes = (double)cantidadQueVotaron/cantidadTotalVotantes*100;
            cout << cantidadQueVotaron << " total de votos." << endl;
            cout << cantidadTotalVotantes <<" total de votantes registrados." << endl;
            cout << "El porcentaje de personas que votaron respecto a la cantidad de registrados fue: "<< porcVotantes<< "%"<<endl;
            cout << "El porcentaje de abstinencia fue: "<< (double)100-porcVotantes<< "%"<<endl<<endl;
            vector<Ciudadano>::iterator it;
            vector<int>::iterator it2;
            it2 = votosTotalSegunda.begin();
            bool huboGanador;
            for(it = candidatosV2.begin(); it != candidatosV2.end(); it++)
            {
                double porcentaje = (double)*it2/cantidadQueVotaron*100;
                cout << "EL candidato de nombre: " << (*it).getNombre() << " obtuvo " << *it2 << " votos."<< " Su porcentaje fue: " << porcentaje <<" %";
                if(cantidadQueVotaron/2+1 <= *it2)
                {
                    cout << " Este candidato es el nuevo presidente.";
                    huboGanador = true;
                }
                it2++;
                cout << endl;
            }
            cout<<endl<<endl;

            cout << endl << endl;
            queVuelta = 2;
    }

}

void Votacion::contarVotos(int vuelta)
{
    if (vuelta == 1)
    {
        vector<Ciudadano>::iterator it;
        vector<int>::iterator it2;
        for(it = candidatos.begin(); it != candidatos.end(); it++)
        {
            int contadorVotos=0;
            for(it2 = votosPrimeraVuelta.begin(); it2 != votosPrimeraVuelta.end(); it2++)
            {
                if (*it2 == (*it).getCedula())
                    contadorVotos++;
            }
            votosTotalPrimera.push_back(contadorVotos);
            //cout << "El Candidato " << (*it).getNombre() << " obtuvo " << contadorVotos << endl;
        }
    }
    else if (vuelta == 2)
    {
        vector<Ciudadano>::iterator it;
        vector<int>::iterator it2;
        for(it = candidatosV2.begin(); it != candidatosV2.end(); it++)
        {
            int contadorVotos=0;
            for(it2 = votosSegundaVuelta.begin(); it2 != votosSegundaVuelta.end(); it2++)
            {
                if (*it2 == (*it).getCedula())
                    contadorVotos++;
            }
            votosTotalSegunda.push_back(contadorVotos);
            cout << "El Candidato " << (*it).getNombre() << " obtuvo " << contadorVotos << endl;
        }
    }
}




