#include "Rectangulo.h"
#include <iostream>
#include <math.h>
const int CAP = 10;
using namespace std;


Rectangulo::Rectangulo(  ){
    largo = 0;
    ancho = 0;
}

Rectangulo::Rectangulo( float largo, float ancho ){
    this->largo = largo;
    this->ancho = ancho;
}

void Rectangulo::calcularAreaRectangulo(  ){
    float area;
    area = largo * ancho;
    cout<<"El area del rectangulo es: "<<area<<endl;

} 
void Rectangulo::calcularPerimetroRectangulo(  ){
    float perimetro;
    perimetro = ( 2 * largo ) + ( 2 * ancho );
    cout<<"El perimetro del rectangulo es: "<<perimetro<<endl;
}
float Rectangulo::getLargo(  ){
    return this->largo;
}
float Rectangulo::getAncho(  ){
    return this->ancho;
}

void Rectangulo::setLargo( float largo ){
    this->largo = largo;
}

void Rectangulo::setAncho( float ancho ){
    this->ancho = ancho;
}

