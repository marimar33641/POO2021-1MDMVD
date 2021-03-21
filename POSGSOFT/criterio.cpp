#include "criterio.h"

Criterio::Criterio(string nombreCriterio, float calificacion, float ponderacion, string observaciones, int jurado ){
    this->nombreCriterio = nombreCriterio;
    this->calificacion = calificacion;
    this->ponderacion = ponderacion;
    this->observaciones = observaciones;
}

void Criterio::mostrarCriterio(){
    cout << "Nombre del criterio: "<< nombreCriterio << endl;
    cout << "Calificacion: " << calificacion << endl;
    cout << "Ponderacion" << ponderacion << endl;
    cout << "Observaciones" << endl << observaciones << endl;

}

float Criterio:: getCalificacion(){
    return this->calificacion;
}

string Criterio:: getNombreCriterio(){
    return this->nombreCriterio;
}

float Criterio::getPonderacion(){
    return this->ponderacion;
}

string Criterio::getObservaciones(){
    return this->observaciones;
}

