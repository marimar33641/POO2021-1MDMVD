#include "jurado.h"

//Constructor Jurado

Jurado::Jurado(){
    this->nombreJurado = "NA";
}

Jurado::Jurado( string nombreJurado, int estado, string identificacion, string email, string celular ){
    this->nombreJurado = nombreJurado; 
    this->estado = estado;
    this->identificacion = identificacion;
    this->email = email;
    this->celular = celular;
}

void Jurado::mostrarJurado(  ){
    cout<<"===================="<<endl;
    cout<<"Nombre: "<<this->nombreJurado<<endl;
    cout << "Tabajo: ";
    if( estado == 1 ){
        cout << "Interno" << endl;
    }
    else{
        cout << "Externo" << endl;
    }
    cout << "Identificacion: " << identificacion << endl;
    cout << "Email: " << email << endl;
    cout << "celular: " << celular << endl;
    cout << endl;
}

string Jurado::getNombreJurado(){
    return this-> nombreJurado;
}

