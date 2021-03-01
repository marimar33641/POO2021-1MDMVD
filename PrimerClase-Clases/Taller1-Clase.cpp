#include <iostream>
#include <conio.h>
#include <math.h>
const int CAP = 10;
using namespace std;

class Circulo{
    private:
        float radio;
    public:
        Circulo(  );
        Circulo( float );
        void calcularAreaCirculo(  );
        void calcularPerimetroCirculo(  );
        float getCirculo(  );
        void setRadio( float );
};

class Rectangulo{
    private:
        float largo, ancho;
    public:
        Rectangulo(  );
        Rectangulo( float, float );
        void calcularPerimetroRectangulo(  );
        void calcularAreaRectangulo(  );
        float getLargo(  ); 
        float getAncho(  );
        void setLargo( float ); 
        void setAncho( float );

};

class Triangulo{
    private:
        float base, altura;
    public:
        Triangulo();
        Triangulo( float, float );
        void calcularPerimetroTriangulo(  );
        void calcularAreaTriangulo(  );
        float getAlturaTriangulo(  ); 
        float getBaseTriangulo(  );
        void setAlturaTriangulo( float ); 
        void setBaseTriangulo( float );
};

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

void crearTriangulo( Triangulo triangulos[ CAP ], int contadorTriangulos ){
    float altura, base; 
    cout<<"Digite la altura: "; cin>>altura;
    cout<<"Digite la base: "; cin>>base;
    triangulos[ contadorTriangulos ].setAlturaTriangulo( altura );
    triangulos[ contadorTriangulos ].setBaseTriangulo( base );
}

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

void crearCirculo( Circulo circulo[ CAP ], int contadorCirculos ){
    int radio;
    cout<<"Digite el radio: "; cin>>radio;
    circulo[ contadorCirculos ].setRadio( radio );
}

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

void crearRectangulo( Rectangulo rectangulo[ CAP ], int contadorRectangulos ){
    float largo, ancho; 
    cout<<"Digite el largo: "; cin>>largo;
    cout<<"Digite el ancho: "; cin>>ancho;
    rectangulo[ contadorRectangulos ].setLargo( largo );
    rectangulo[ contadorRectangulos ].setAncho( ancho );
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
    int opcion, radio = 0, largo = 0, ancho = 0, contadorCirculos = 0, contadorRectagulos = 0, contadorTriangulo = 0;
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
