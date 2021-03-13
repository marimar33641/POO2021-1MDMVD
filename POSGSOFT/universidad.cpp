
#include "universidad.h"

enum trabajo{
    INTERNO = 1,
    EXTERNO = 2
};

void Universidad::crearFolderActas( ){

};

void Universidad::mostrarEstudiantes( ){
    for(list<Estudiante>::iterator it = listaEstudiantes.begin(); it != listaEstudiantes.end(); it++ )
    it->mostrarEstudiante();
}

void Universidad::crearDirector( ){
    string nombreDirector;
    string identificacion;
    string email;
    string celular;
    cout << "Ingrese el nombre del director: " << endl;
    fflush(stdin);
    getline( cin, nombreDirector );
    cout << "Ingrese la identificacion del director: " << endl;
    fflush(stdin);
    getline(cin, identificacion);
    cout<< "Ingrese el email: " << endl;
    fflush(stdin);
    getline(cin, email);
    cout<< "Ingrese el celular: "<<endl;
    fflush(stdin);
    getline(cin, celular);
    listaDirector.push_back(Director(nombreDirector, identificacion,email,celular));
}

void Universidad::mostrarTodosDirectores(){
    for(list<Director>::iterator it = listaDirector.begin(); it != listaDirector.end(); it++ )
    it->mostrarDirector();
}


void Universidad::crearJurado( ){
    string nombreJurado;
    trabajo tipo;
    string identificacion;
    string email;
    string celular;
    cout << "Ingrese el nombre del nuevo jurado: " << endl;
    fflush(stdin);
    getline( cin, nombreJurado );
    cout << "Ingrese el tipo de trabajo que tiene el nuevo jurado: " << endl;
    cout << "1. Interno" << endl;
    cout << "2. Externo" << endl;
    scanf("%d", &tipo);
    cout << "Ingrese el nombre del jurado: " << endl;
    fflush(stdin);
    cout << "Ingrese la identificacion del jurado: " << endl;
    getline(cin, identificacion);
    cout<< "Ingrese el email: " << endl;
    fflush(stdin);
    getline(cin, email);
    cout << "Ingrese el celular del jurado:" << endl;
    fflush(stdin);
    getline(cin, celular);
    listaJurados.push_back(Jurado(nombreJurado,tipo, identificacion,email,celular));  
}
void Universidad::mostrarJurados( ){
    for( list<Jurado>::iterator it = listaJurados.begin(); it != listaJurados.end(); it++ ){
        it->mostrarJurado( );
    }
}

Universidad :: Universidad( ){
    this->nombre = "Pontificia Universidad Javeriana Cali";
}

