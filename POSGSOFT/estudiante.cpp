#include "estudiante.h"

//Constructor estudiante

Estudiante::Estudiante( string nombre, string identificacion, string email, string celular, Acta actaEstudiante, string id){
    this->nombre = nombre; 
    this->identificacion = identificacion;
    this->email = email;
    this->celular = celular;
    this->actaEstudiantes = actaEstudiantes;
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