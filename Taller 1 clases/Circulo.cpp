#include <iostream>
#include <math.h>
#include "Circulo.h"
const int CAP = 10;
using namespace std;

Circulo::Circulo(  ){
    radio = 0;
}


Circulo::Circulo( float radio ){
    this->radio = radio;
}

void Circulo::calcularAreaCirculo(  ){
    float area;
    area =  M_PI * pow(radio,2);
    cout<<"El area del circulo es de "<< area << "cm^2"<<endl;
}

void Circulo::calcularPerimetroCirculo(  ){
    float perimetro;
    perimetro = 2*M_PI*radio;
    cout<<"El perimetro del circulo es de "<<perimetro<<" cm "<<endl;
}

float Circulo::getCirculo(  ){
    return this->radio;
}

void Circulo::setRadio( float radio ){
    this->radio = radio;
}

