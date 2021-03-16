#include "folderActas.h"

enum TipoTrabajo{
    APLICADO = 1,
    INVESTIGACION = 2
};

FolderActas::FolderActas(  ){
    this->facultad = facultad;
    this->listaEstudiantes = listaEstudiantes;
}

FolderActas::FolderActas( list <Director>, list<Jurado> ,string facultad, list <Estudiante> listaEstudiantes  ){
    this->facultad = facultad;
    this->listaEstudiantes = listaEstudiantes;
};

Estudiante FolderActas::crearEstudiante( ){
    string nombreEstudiante;
    string identificacion;
    string email;
    string celular;
    string id;
    cout << "Ingrese el nombre del estudiante: " << endl;
    fflush(stdin);
    getline( cin, nombreEstudiante );
    cout << "Ingrese el ID del estudiante: " << endl;
    fflush(stdin);
    getline( cin, id );
    cout << "Ingrese la Cedula/TT del estudiante: " << endl;
    fflush(stdin);
    getline(cin, identificacion);
    cout<< "Ingrese el email: " << endl;
    fflush(stdin);
    getline(cin, email);
    cout<< "Ingrese el celular: "<<endl;
    fflush(stdin);
    getline(cin, celular);
    listaEstudiantes.push_back(Estudiante(nombreEstudiante, identificacion,email,celular, Acta(), id ));
    list<Estudiante>::iterator it = listaEstudiantes.end();
    return *it;
}

Director FolderActas::buscarDirector( int numDirector ){
    int i;
    list<Director>::iterator it = listaDirector.begin();
    for( i = 0; i < numDirector; i++ ){
        it++;
    }  
    return *it;      
    
}

Jurado FolderActas::buscarJurado( int numJurado ){
    int i;
    list<Jurado>::iterator it = listaJurados.begin();
    for( i = 0; i < numJurado; i++ ){
        it++;
    }  
    return *it;
}


void FolderActas::mostrarDirectores(  ){
    for( list<Director>::iterator it = listaDirector.begin(); it != listaDirector.end(); it++ ){
        cout<<"1. ";
        it->mostrarDirector( );
    }
}

void FolderActas::crearNuevaActa( ){
    Estudiante estudiante;
    Director director;
    Jurado juradoUno;
    Jurado juradoDos;
    string fecha, nombreTrabajo;
    Acta acta;
    list<Criterio> listaCriteriosVacia;
    int tipoTrabajo, estado, numeroDirector, numeroJuradoUno, NumeroJuradoDos;
    estudiante = crearEstudiante();
    cout << "Ingrese la fecha: " <<endl;
    getline(cin, fecha);
    cout<< "Ingrese el titulo del trabajo: "<<endl;
    getline( cin, nombreTrabajo );
    cout << "Ingrese el tipo de trabajo: " << endl << "1.Interno" << endl << "2.Externo" << endl;
    cout << "opc = ";
    cin >> tipoTrabajo;
    mostrarDirectores();
    cout << "Ingrese el numero de director que dirigio este trabajo: " << endl;
    cin >> numeroDirector;
    director = buscarDirector( numeroDirector );

    cout << "Ingrese el numero del jurado numero 1: " << endl;
    cin >> numeroJuradoUno;
    juradoUno = buscarJurado(numeroJuradoUno);
    cout << "Ingrese el numero del jurado numero 2: " << endl;
    cin>>numeroJuradoUno;
    juradoDos = buscarJurado(NumeroJuradoDos);

    list<Estudiante>::iterator it = listaEstudiantes.end();
    Acta acta(nombreTrabajo, fecha, director, tipoTrabajo, juradoUno, juradoDos, 0 , -1, listaCriteriosVacia); 
    it->setActa(acta);
    it->ingresarCriterios();
    
    
    return;
}

void FolderActas::diligenciarCalifaciones(  ){
    return;
}
void FolderActas::calcularNota(  ){
    return;
}

void FolderActas::ingresarInformacionAdicional(  ){
    return;
}

void FolderActas::cerrarActa(  ){
    return;
}

void FolderActas::guardarInformacionActa(  ){
    return;
}

void FolderActas::mostrarInformacionActa(  ){
    return;
}

void FolderActas::listarActas(  ){
    return;
}

void FolderActas::consultarListaCriterios(  ){
    return;
}

void FolderActas::eliminarActas(  ){
    return;
}


