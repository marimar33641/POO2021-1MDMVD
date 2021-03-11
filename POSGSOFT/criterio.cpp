#include "criterio.h"

Criterio::Criterio(string nombreCriterio, float calificacion, float ponderacion, string observaciones, int por ){
    this->nombreCriterio = nombreCriterio;
    this->calificacion = calificacion;
    this->ponderacion = ponderacion;
    this->observaciones = observaciones;
    this->por = por;
}

void Criterio::mostrarCriterio(){
    cout << "================"<< endl;
    cout << nombreCriterio << endl;
    cout << "Calificacion: " << calificacion << endl;
    cout << "Ponderacion" << ponderacion << endl;
    cout << "Observaciones" << endl << observaciones << endl;
    if(por = 1){
        cout << "Jurado 1" << endl;
    }
    else{
        cout << "Jurado 2" << endl;
    }
}

