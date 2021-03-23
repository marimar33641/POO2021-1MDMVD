#include "director.h"

//Constructor Director

Director :: Director(){
    this->nombreDirector = "NA";
    this->identificacion = "NA";
    this->email = "NA";
    this->celular = "NA";
}

Director::Director( string nombreDirector, string identificacion, string email, string celular){
    this->nombreDirector = nombreDirector; 
    this->identificacion = identificacion;
    this->email = email;
    this->celular = celular;
}
void Director::mostrarDirector(  ){
    
    cout<<"===================="<<endl;
    cout<< "Nombre: "<< this-> nombreDirector<<endl;
    cout<< "Id: "<< this-> identificacion<<endl;
    cout<< "Email: " << this->email<< endl;
    cout<< "Celular: " << this->celular<<endl;
}

string Director::getNombreDirector(){
    return this->nombreDirector;
}

string Director::getIdentificacion(){
    return this->identificacion;
}