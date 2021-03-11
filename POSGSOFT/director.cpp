#include "director.h"

//Constructor Director
Director::Director( string nombreDirector ){
    this->nombreDirector = nombreDirector; 
}
void Director::mostrarDirector(  ){
    cout<<"===================="<<endl;
    cout<<"Nombre: "<<this->nombreDirector<<endl;
}