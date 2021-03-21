#include "acta.h"

Acta::Acta( ){

}

Acta::Acta( string titulo, string fecha , Director director , int tipoTrabajo, Jurado jurado1, Jurado jurado2, float notafinal , int estado, list<Criterio> listaCriterios ){
    this-> titulo = titulo;
    this-> fecha = fecha;
    this-> director = director;
    this-> tipoTrabajo = tipoTrabajo;
    this-> jurado1 = jurado1;
    this-> jurado2 = jurado2;
    this-> notaFinal = notaFinal;
    this-> estado = estado;
    this-> listaCriterios = listaCriterios;
}

void Acta::setTituloActa( string titulo ){
    cout<<"Titulo1: "<<titulo<<endl;
    this->titulo = titulo;
    cout<<"titulo"<< titulo<<endl;
    cout<<"Titulo2: "<<titulo<<endl;
}

void Acta::setFechaActa( string fecha ){
    this->fecha = fecha;
}

void Acta::setDirector( Director director ){
    this-> director = director;
}

void Acta::setTipoTrabajo( int tipoTrabajo ){
    this->tipoTrabajo = tipoTrabajo;
}

void Acta::setJuradoUno( Jurado juradoUno ){
    this->jurado1 = juradoUno;
}

void Acta::setJuradoDos( Jurado juradoDos ){
    this->jurado2 = juradoDos;
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

string Acta::getFecha(){
    return this->fecha;
}

string Acta::getTitulo(){
    return this->titulo;
}

int Acta::getModalidad(){
    return this->tipoTrabajo;
}

string Acta::getNombreJuradoUnoActa( ){
    return this->jurado1.getNombreJurado();
}

string Acta::getNombreJuradoDosActa( ){
    return this-> jurado2.getNombreJurado();
}

string Acta::getNombreDirectorActa(){
    return this->director.getNombreDirector();
}

list <Criterio> Acta::getListaCriterios(){
    return this->listaCriterios;
}

void Acta::mostrarActa(  ){
    cout<<"===================="<<endl;
    cout<<"Titulo: "<<titulo<<endl;
    cout<<"Fecha: "<<fecha<<endl;
    cout<<"Tipo de trabajo: "<<tipoTrabajo<<endl;
}
