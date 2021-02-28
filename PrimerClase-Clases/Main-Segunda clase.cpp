#include <iostream>
#include <conio.h>
using namespace std;

class Rectangulo{
    private:
        float largo, ancho;
    public:
        Rectangulo( );
        void calcularPerimetro();
        void calcularArea();
        float getLargo(  ); 
        void setLargo(float); 
};

Rectangulo::Rectangulo(  ){ 
    this->largo = 5;
    this->ancho = 4;
    cout<<"Entre y me cree"<<endl;
}

float Rectangulo::getLargo(  ){
    return this->largo;
}

void Rectangulo::setLargo( float largo ){
    this->largo = largo;
}

void Rectangulo::calcularPerimetro(  ){
    float perimetro;
    perimetro = ( 2 * largo ) + ( 2 * ancho );
    cout<<"El perimetro es de "<<perimetro<<endl;
}

void Rectangulo::calcularArea(  ){
    float area;
    area = largo * ancho;
    cout<<"El area es: "<<area<<endl;
}

int main(){
    Rectangulo miRectangulo;
    miRectangulo.calcularArea();
    miRectangulo.calcularPerimetro();
    getch();
    return 0;
}