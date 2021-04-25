#include "Cuadrado.h"

Cuadrado :: Cuadrado(){}

Cuadrado :: Cuadrado( float longitud ){
    this-> longitud = longitud;
}

void Cuadrado :: calcularArea(){
    this ->area = this->longitud * this->longitud;
}

void Cuadrado::calcularPerimetro(){
    this->perimetro = 4 * this->longitud;
}

void Cuadrado::mostrarFigura(){
    cout << "La longitud es: " << longitud << " -- "<< endl;
    if (this->area == 0) // si no he calculado el area
    {
        this->calcularArea();
    }
    if (this->perimetro == 0)
    {
        this->calcularPerimetro();
    }
    cout << "El area del cuadrado es: " << this->area << endl;
    cout << "El perimetro del cuadrado es : " << this->perimetro << endl;
    // LLamo al mostrarFigura delegado
    FiguraGeometrica::mostrarFigura();
}

float Cuadrado :: getLongitud(){
    return this-> longitud;
}

void Cuadrado :: setLongitud(float longitud){
    this->longitud = longitud;
}

