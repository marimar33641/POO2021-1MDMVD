#include "Triangulo.h"
#include <iostream>
#include <math.h>
const int CAP = 10;
using namespace std;

Triangulo::Triangulo(  ){
    base = 0;
    altura = 0;
}

Triangulo::Triangulo( float altura, float base ){
    this->altura = altura;
    this->base = base;
}

void Triangulo::calcularAreaTriangulo(  ){
    float area;
    area = ( base * altura ) / 2;
    cout<<"El area del triangulo es de "<< area<<"\n";
}
void Triangulo::calcularPerimetroTriangulo(  ){
    float perimetro, hipotenusa;
    hipotenusa =  sqrt(pow( ( base / 2 ), 2 ) + pow( altura, 2 ));
    perimetro = base + ( hipotenusa * 2 );
    cout<<"El perimetro del triangulo es de: "<< perimetro<<"\n";
}

float Triangulo::getAlturaTriangulo(  ){
    return this->altura;
}

float Triangulo::getBaseTriangulo(  ){
    return this->base;
}

void Triangulo::setAlturaTriangulo( float altura ){
    this->altura = altura;
}

void Triangulo::setBaseTriangulo( float base ){
    this->base = base;
}

