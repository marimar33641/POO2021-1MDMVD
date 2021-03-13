#include "folderActas.h"

enum TipoTrabajo{
    APLICADO = 1,
    INVESTIGACION = 2
};

FolderActas::FolderActas(  ){
    this->facultad = facultad;
    this->listaEstudiantes = listaEstudiantes;
}

FolderActas::FolderActas( string facultad, list <Estudiante> listaEstudiantes  ){
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

Director FolderActas::buscarDirector(){
    
}

void FolderActas::crearNuevaActa( list<Director> listaDirectores, list<Jurado> listaJurados ){
    Estudiante estudiante;
    Director director;
    string fecha, nombreTrabajo;
    estudiante = crearEstudiante();
    cout << "Ingrese la fecha: " <<endl;
    getline(cin, fecha);
    cout<< "Ingrese el titulo: "<<endl;
    getline( cin, nombreTrabajo );
    director = buscarDirector();
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


