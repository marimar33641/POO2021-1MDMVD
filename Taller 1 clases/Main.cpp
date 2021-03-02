#include <iostream>
#include <conio.h>
#include <math.h>
#include "Rectangulo.h"
#include "Triangulo.h"
#include "Circulo.h"

const int CAP = 10;
using namespace std;

void crearCirculo( Circulo circulo[ CAP ], int contadorCirculos ){
    int radio;
    cout<<"Digite el radio: "; cin>>radio;
    circulo[ contadorCirculos ].setRadio( radio );
}

void crearRectangulo( Rectangulo rectangulo[ CAP ], int contadorRectangulos ){
    float largo, ancho; 
    cout<<"Digite el largo: "; cin>>largo;
    cout<<"Digite el ancho: "; cin>>ancho;
    rectangulo[ contadorRectangulos ].setLargo( largo );
    rectangulo[ contadorRectangulos ].setAncho( ancho );
}

void crearTriangulo( Triangulo triangulos[ CAP ], int contadorTriangulos ){
    float altura, base; 
    cout<<"Digite la altura: "; cin>>altura;
    cout<<"Digite la base: "; cin>>base;
    triangulos[ contadorTriangulos ].setAlturaTriangulo( altura );
    triangulos[ contadorTriangulos ].setBaseTriangulo( base );
}

void menu(){
    cout<<"1.Crear Rectangulo\n2.Crear Circulo\n3.Crear Triangulos\n4.Mostrar Figuras\n0.Salir\n";
}


void mostrarFiguras( Circulo circulo[ CAP ], Rectangulo rectangulo[ CAP ], int contadorCirculos, int contadorRectangulos, Triangulo triangulos[ CAP ], int contadorTriangulos ){
    int opcion, i;
    cout<<"1.Mostrar Circulos\n2.Mostrar Rectagulos\n3.Mostrar Triangulos\nOpcion: "; cin>>opcion;
    if( opcion == 1 ){
        for( i = 0; i < contadorCirculos; i++ ){
            cout<<"\n------------------------------\n";
            cout<<"Circulo No. "<< i + 1<<"\n ";
            cout<<"Radio: "<<circulo[ i ].getCirculo()<<"\n";
            circulo[ i ].calcularAreaCirculo();
            circulo[ i ].calcularPerimetroCirculo();
            cout<<"\n------------------------------\n";
        }
    }
    else if( opcion == 2 ){
        for( i = 0; i < contadorRectangulos; i++ ){
            cout<<"\n------------------------------\n";
            cout<<"Rectangulo No. "<< i + 1<<"\n";
            cout<<"Largo: "<<rectangulo[ i ].getLargo()<<"\n";
            cout<<"Ancho:: "<<rectangulo[ i ].getAncho()<<"\n";
            rectangulo[ i ].calcularAreaRectangulo();
            rectangulo[ i ].calcularPerimetroRectangulo();
            cout<<"\n------------------------------\n";
        }
    }
    else if( opcion == 3 ){
        for( i = 0; i < contadorTriangulos; i++ ){
            cout<<"\n------------------------------\n";
            cout<<"Rectangulo No. "<< i + 1<<"\n";
            cout<<"Altura: "<<triangulos[ i ].getAlturaTriangulo()<<"\n";
            cout<<"Base: "<<triangulos[ i ].getBaseTriangulo()<<"\n";
            triangulos[ i ].calcularAreaTriangulo();
            triangulos[ i ].calcularPerimetroTriangulo();
            cout<<"\n------------------------------\n";
        }
    }
    else{
        cout<<"Opcion mal digitada\n";
    } 
}

int main(){
    //Creo mi primer objeto
    Rectangulo rectangulos[ CAP ];
    Circulo circulos[ CAP ];
    Triangulo triangulos[ CAP ];
    int opcion, contadorCirculos = 0, contadorRectagulos = 0, contadorTriangulo = 0;
    do{
        menu();
        cout<<"Opcion: ";cin>>opcion;
        if( opcion == 1 ){
            if( contadorRectagulos < CAP ){
                crearRectangulo( rectangulos, contadorRectagulos );
                cout<<"Rectangulo creado con exito :D\n";
                contadorRectagulos++;
            }
            else{
                cout<<"No hay espacio\n";
            }
        }
        else if( opcion == 2 ){
            if( contadorCirculos < CAP ){
                crearCirculo( circulos, contadorCirculos );
                cout<<"Circulo creado con exito :D\n";
                contadorCirculos++;
            }
            else{
                cout<<"No hay espacio\n";
            }
        }
        else if( opcion == 3 ){
            if( contadorTriangulo < CAP ){
                crearTriangulo( triangulos, contadorTriangulo );
                cout<<"Triangulo creado con exito :D\n";
                contadorTriangulo++;
            }
            else{
                cout<<"No hay espacio\n";
            }

        }
        else if( opcion == 4 ){
            if( ( contadorCirculos == 0 ) && ( contadorRectagulos == 0 ) && ( contadorTriangulo == 0 ) ){
                cout<<"Vacio\n";
            }
            else{
                mostrarFiguras( circulos, rectangulos, 
                contadorCirculos, contadorRectagulos, triangulos, contadorTriangulo );
            }
        }
        if( ( contadorCirculos == 10 ) && ( contadorRectagulos == 10 ) && ( contadorTriangulo == 10 ) ){
            cout<<"Ya no hay mas espacio en ningun arreglo\nGRACIAS POR UTILIZAR NUESTRO SOFTWARE :D\n";
            exit(-1);
            }
    }while( opcion != 0 );
    getch();
    return 0;
}
