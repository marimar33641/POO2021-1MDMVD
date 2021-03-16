#include "estudiante.h"

//Constructor estudiante
Estudiante::Estudiante(  ){
    this->nombre = "NA"; 
    this->identificacion = "NA";
    this->email = "NA";
    this->celular = "NA";
    this->actaEstudiante = actaEstudiante;
    this->id = "NA";
}

Estudiante::Estudiante( string nombre, string identificacion, string email, string celular, Acta actaEstudiante, string id){
    this->nombre = nombre; 
    this->identificacion = identificacion;
    this->email = email;
    this->celular = celular;
    this->actaEstudiante = actaEstudiante;
    this->id = id;
}
void Estudiante::mostrarEstudiante(  ){
    cout<<"===================="<<endl;
    cout<< "Nombre: "<< this-> nombre<<endl;
    cout<< "Id: "<< this-> identificacion<<endl;
    cout<< "Email: " << this->email<< endl;
    cout<< "Celular: " << this->celular<<endl;
    cout << "ID: " << this->id << endl;
}

void Estudiante::setActa( Acta acta ){
    this->actaEstudiante = acta;
}