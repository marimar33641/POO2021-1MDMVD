#include <iostream>
#include <conio.h>
using namespace std;

class Rectangulo{
    private:
        float largo, ancho; //Atributos de la instancia
    public:
        Rectangulo( float , float ); //Constructor
        void calcularPerimetro();
        void calcularArea();
        float getLargo(  ); //Me permite ver el valor de largo
        void setLargo(float); //Me permite cambiar el valor de largo
};

//TO-DO Pedir datos al usuario

//Asi se usa cuando cambio el nombre de las variables en los parametros

/*Rectangulo::Rectangulo( float largo1, float ancho1 ){ //Inicializar lo del constructor
    //Inicializar las variables de instancias
        //Todo lo que tenga que inicializar
    largo = largo1;
    ancho = ancho1;
    cout<<"Entre y me cree"<<endl;
}
*/

//No cambiar el nombre de las variables de instancia
Rectangulo::Rectangulo( float largo, float ancho ){ //Inicializar lo del constructor
    //Inicializar las variables de instancias
        //Todo lo que tenga que inicializar
    this->largo = largo;
    this->ancho = ancho;
    cout<<"Entre y me cree"<<endl;
}
//
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
    //Instanciar --> crear objetos de una clase
    //Mi primer objeto
    Rectangulo miRectangulo( 2,2 ); //Sobrecarga....
    //Calculo el area
    miRectangulo.calcularArea(  );
    //Cambio el largo a otro valor
    miRectangulo.setLargo( 50 );
    //Calculo el area x2 con el largo cambiado
    miRectangulo.calcularArea(  );
    //Puedo ver el largo 
    miRectangulo.getLargo(  );
    //Calculo el perimetro
    cout<<"El largo es: "<< miRectangulo.getLargo()<<endl;
    cout<<"OTRO"<<endl;
    Rectangulo miRectanguloNuevo( 1,5 );
    miRectanguloNuevo.calcularArea(  );
    //Calculo el perimetro
    miRectanguloNuevo.calcularPerimetro(   );
    getch();
    return 0;
}