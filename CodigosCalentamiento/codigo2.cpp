#include <iostream>
#include <conio.h>
using namespace std;

struct PedirDatos{
    int edad;
    char sexo[1];
    float altura;
}persona;

int main(){
    cout<<"Edad: "; cin>>persona.edad;
    cout<<"Sexo: ";cin>>persona.sexo;
    cout<<"Altura: "; cin>>persona.altura;
    cout<<"Imprimiendo datos...\n";
    cout<<"Edad: "<<persona.edad<<endl;
    cout<<"Sexo: "<<persona.sexo<<endl;
    cout<<"Altura: "<<persona.altura<<endl;
    getch();
    return 0;
}