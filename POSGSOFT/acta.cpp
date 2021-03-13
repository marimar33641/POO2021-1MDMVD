#include "acta.h"

Acta::Acta( ){
    this-> titulo = titulo;
    this-> fecha = fecha;
    this-> periodo = periodo;
    this->director = director;
    this-> tipoTrabajo = tipoTrabajo;
    this-> jurado1 = jurado1;
    this-> jurado2 = jurado2;
    this-> notaFinal = notaFinal;
    this-> estado = estado;
    this-> listaCriterios = listaCriterios;
}

Acta::Acta( string titulo, string fecha , Director director , int periodo, int tipoTrabajo, Jurado jurado1, Jurado jurado2, int notafinal , int estado, list<Criterio> listaCriterios ){
    this-> titulo = titulo;
    this-> fecha = fecha;
    this->director = director;
    this-> periodo = periodo;
    this-> tipoTrabajo = tipoTrabajo;
    this-> jurado1 = jurado1;
    this-> jurado2 = jurado2;
    this-> notaFinal = notaFinal;
    this-> estado = estado;
    this-> listaCriterios = listaCriterios;
}

void Acta::mostrarActa(  ){
    cout<<"===================="<<endl;
    cout<<"Titulo: "<<titulo<<endl;
    cout<<"Fecha: "<<fecha<<endl;
    cout<<"Periodo: "<<periodo<<endl;
    cout<<"Tipo de trabajo: "<<tipoTrabajo<<endl;
}

