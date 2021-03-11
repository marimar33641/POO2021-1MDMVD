#include "jurado.h"

//Constructor Jurado

Jurado::Jurado(){
    this->nombreJurado = "NA";
}

Jurado::Jurado( string nombreJurado, int estado ){
    this->nombreJurado = nombreJurado; 
    this->estado = estado;
}

void Jurado::mostrarJurado(  ){
    cout<<"===================="<<endl;
    cout<<"Nombre: "<<this->nombreJurado<<endl;
}


