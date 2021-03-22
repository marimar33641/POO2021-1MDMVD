#include "criterio.h"

/*Se crea el constructor*/

Criterio::Criterio(string nombreCriterio, float calificacion, float ponderacion, string observaciones, int jurado ){
    this->nombreCriterio = nombreCriterio;
    this->calificacion = calificacion;
    this->ponderacion = ponderacion;
    this->observaciones = observaciones;
}

void Criterio::mostrarCriterio(){
    /*Mostramos */
    cout << "Nombre del criterio: "<< nombreCriterio << endl;
    cout << "Calificacion: " << calificacion << endl;
    cout << "Ponderacion" << ponderacion << endl;
    cout << "Observaciones" << endl << observaciones << endl;

}
/*Se bhace get de todos los atributos de Criterio*/
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
/*Se crea esta funcion para que solo muestre el criterio (funcion se llama en Acta*/
void Criterio :: mostrarNombreCriterio(){
    cout << nombreCriterio << endl;

}

/*Set de la calificacion y observaciones*/
void Criterio::setCalificacionCriterio( float calificacion ){
    this->calificacion = calificacion;
}

void Criterio::setObservacionCriterio( string observaciones ){
    this->observaciones = observaciones;
}


