#include "director.h"

//Constructor Director

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