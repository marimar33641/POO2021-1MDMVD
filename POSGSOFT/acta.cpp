#include "acta.h"

Acta::Acta( ){
    this-> titulo = titulo;
    this-> fecha = fecha;
    this-> tipoTrabajo = tipoTrabajo;
    this-> notaFinal = notaFinal;
    this-> estado = estado;
}

Acta::Acta( string titulo, string fecha , Director director , int tipoTrabajo, Jurado jurado1, Jurado jurado2, float notafinal , int estado, list<Criterio> listaCriterios ){
    this-> titulo = titulo;
    this-> fecha = fecha;
    this->director = director;
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
    cout<<"Tipo de trabajo: "<<tipoTrabajo<<endl;
}

void Acta::setTitulo( string titulo ){
    this->titulo = titulo;
}

void Acta::setFecha( string fecha ){
    this->fecha = fecha;
}

void Acta::setDirector( Director Director ){
    this-> director = director;
}

void Acta::setTipoTrabajo( int tipoTrabajo ){
    this->tipoTrabajo = tipoTrabajo;
}

void Acta::setJuradoUno( Jurado juradoUno ){
    this->jurado1 = jurado1;
}

void Acta::setJuradoDos( Jurado JuradoDos ){
    this->jurado2 = jurado2;
}

void Acta::setNotaFinal( float NotaFinal ){
    this->notaFinal = notaFinal;
}

void Acta::setEstado( int estado ){
    this->estado = estado;
}

void Acta::setListaCriterios( list<Criterio> listaCriterios ){
    this->listaCriterios = listaCriterios;
}


