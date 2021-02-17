#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

struct datos{
    char nombre[20];
    char apellidos[20];
    long long int telefono;
}datosPersona;

int crearDirectorio(){
    int opcion;
    ofstream file;
    file.open("reporte.dat", ios::out );
    if( file.fail() ){
        cout<<"No se pudo abrir el archivo\n";
        exit(1);
    }
    file<<"   Nombre"<<"   Apellido "<<"   Numero\n";
    do{
        fflush(stdin);
        cout<<"Nombre/s: ";gets( datosPersona.nombre);
        cout<<"Apellidos: ";gets( datosPersona.apellidos );
        cout<<"Telefono: ";cin>>datosPersona.telefono;
        file<<"=======  =======  ========\n";
        file<<datosPersona.nombre<<"   "<<datosPersona.apellidos<<"   "<<datosPersona.telefono<<"\n";
        cout<<"\n";
        cout<<"Desea agregar mas contactos?1.Si\n2.No\nOpcion: ";cin>>opcion;
    }while( opcion != 2 );
}

void mostrarDatos(){
    ifstream file;
    string linea;
    file.open("reporte.dat", ios::in );
    if( file.fail() ){
        cout<<"No se pudo abrir el archivo\n";
        exit(1);
    }
    while( getline(file, linea ) ){
        cout<<linea<<"\n";
    }
    cout<<"\n";
}

int aniadirDatos(){
    ofstream file;
    file.open("reporte.dat", ios::app );
    if( file.fail() ){
        cout<<"No se pudo abrir el archivo\n";
        exit(1);
    }
    fflush(stdin);
    cout<<"Nombre/s: ";gets( datosPersona.nombre);
    cout<<"Apellidos: ";gets( datosPersona.apellidos );
    cout<<"Telefono: ";cin>>datosPersona.telefono;
    file<<"=======  =======  ========\n";
    file<<datosPersona.nombre<<"   "<<datosPersona.apellidos<<"   "<<datosPersona.telefono<<"\n";
    cout<<"\n";
    file.close();
}

void menu(){
    cout<<"1.Crear directorio\n";
    cout<<"2.Aniadir\n";
    cout<<"3.Mostrar\n";
    cout<<"4.Generar reporte\n";
    cout<<"0.Salir\n";
    cout<<"Opcion: ";
    return;
}

void generarReporte(){
    ofstream file;
    file.open("reporte.dat", ios::app );
    if( file.fail() ){
        cout<<"No se pudo abrir el archivo\n";
        exit(1);
    }
    system( "notepad reporte.dat" );
}

int main(){
    int opcion,bandera = 0, n = 0, i;
    do{
        menu();
        cin>>opcion;
        switch (opcion){
        case 1:
            crearDirectorio();
            break;
        case 2:
            aniadirDatos();
            break;
        case 3:
            printf("-----------------------------\n");
            mostrarDatos();
            printf("-----------------------------\n");
            break;
        case 4:
            generarReporte();
            break;
        default:
            break;
        }
    }while( opcion != 0 );
    getch();
    return 0;
}