#include "acta.h"

Acta::Acta( string nombreEstudiante, string fecha,string nombreTrabajo , int periodo, int tipoTrabajo, int idEstudiante, Jurado jurado1, Jurado jurado2, int notafinal , int estado, list<Criterio> listaCriterios ){
    this-> nombreEstudiante = nombreEstudiante;
    this-> fecha = fecha;
    this-> nombreTrabajo = nombreTrabajo;
    this-> periodo = periodo;
    this-> tipoTrabajo = tipoTrabajo;
    this-> idEstudiante = idEstudiante;
    this-> jurado1 = jurado1;
    this-> jurado2 = jurado2;
    this-> notaFinal = notaFinal;
    this-> estado = estado;
    this-> listaCriterios = listaCriterios;
}

void Acta::mostrarActa(  ){
    cout<<"===================="<<endl;
    cout<<"Nombre Estudiante: "<<nombreEstudiante<<endl;
    cout<<"Fecha: "<<fecha<<endl;
    cout<<"Periodo: "<<periodo<<endl;
    cout<<"Tipo de trabajo: "<<tipoTrabajo<<endl;
    cout<<"ID: "<<idEstudiante<<endl;
}

