
#include "universidad.h"

enum trabajo{
    INTERNO = 1,
    EXTERNO = 2
};

enum TipoTrabajo{
    APLICADO = 1,
    INVESTIGACION = 2
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

Universidad::Universidad( ){
    this->nombre = "Pontificia Universidad Javeriana Cali";

}

Estudiante Universidad::getListaEstudiante(){
    list<Estudiante>::iterator it = listaEstudiantes.begin();
    return *it;
}

Director Universidad::getListaDirectores(){
    list<Director>::iterator it = listaDirector.begin();
    return *it;
}

/* 
Folder.cpp
*/


void Universidad::crearEstudiante( ){
    string nombreEstudiante;
    string identificacion;
    string email;
    string celular;
    string id;
    Acta actaVacia;
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
    cout<<"No se xd\n";
    listaEstudiantes.push_back(Estudiante(nombreEstudiante, identificacion,email,celular, actaVacia, id ));
    cout<<"Aqui k paso\n";
    return;
}

Director Universidad::buscarDirector( int numDirector ){
    int i = 1;
    for( list<Director>::iterator it = listaDirector.begin();it != listaDirector.end(); it++ ){
        if(i == numDirector){
            return *it;
        }
        i++;
    }   
}

Jurado Universidad::buscarJuradoUno( int numJurado ){
    int i = 1;
    for( list<Jurado>::iterator it = listaJurados.begin(); it != listaJurados.end(); it++ ){
        if( i == numJurado ){
            return *it;
        }
        i++;
    }
}

Jurado Universidad::buscarJuradoDos( int numJurado ){
    int i = 1;
    for( list<Jurado>::iterator it = listaJurados.begin(); it != listaJurados.end(); it++ ){
        if( i == numJurado ){
            return *it;
        }
        i++;
    }
}

void Universidad::mostrarDirectores(  ){
    for( list<Director>::iterator it = listaDirector.begin(); it != listaDirector.end(); it++ ){
        cout<<"1. ";
        it->mostrarDirector( );
    }
}

void Universidad::crearNuevaActa( ){
    Director director;
    Jurado juradoUno;
    Jurado juradoDos;
    string fecha_;
    string nombreTrabajo;
    list<Criterio> listaCriteriosVacia;
    int tipoTrabajo, estado, numeroDirector, numeroJuradoUno = 0, numeroJuradoDos = 0, contador = 1;
    crearEstudiante();
    cout << "Ingrese la fecha: " <<endl;
    fflush(stdin);
    getline(cin, fecha_);
    cout<< "Ingrese el titulo del trabajo: "<<endl;
    fflush(stdin);
    getline( cin, nombreTrabajo );
    cout << "Ingrese el tipo de trabajo: " << endl << "1.Aplicado" << endl << "2.Investigacion" << endl;
    cout << "opc = ";
    cin >> tipoTrabajo;
    
    mostrarDirectores();
    cout << "Ingrese el numero de director que dirigio este trabajo: " << endl;
    cin >> numeroDirector;
    director = buscarDirector( numeroDirector );
    mostrarJurados();
    cout << "Ingrese el numero del jurado numero 1: " << endl;
    cin >> numeroJuradoUno;
    juradoUno = buscarJuradoUno(numeroJuradoUno);
    cout << "Ingrese el numero del jurado numero 2: " << endl;
    cin>>numeroJuradoDos;
   // cout<<"Jurado2"
    juradoDos = buscarJuradoDos(numeroJuradoDos);
    cout<<"Jurado 1: \n", numeroJuradoUno;
    cout<<"Jurado 2: \n", numeroJuradoDos;
    cout << "Termino los dos jurados" << endl;
    
    //list<Estudiante>::iterator it = listaEstudiantes.begin();
    cout<<"Lista: "<< listaEstudiantes.size();
    for( list<Estudiante>::iterator it = listaEstudiantes.begin(); it != listaEstudiantes.end(); it++ ){
        cout<<"Contador1: "<< contador<<endl; 
        if( contador == listaEstudiantes.size() ){
            cout<<"Contador: "<<contador<<endl;
            it->recibirDatos( nombreTrabajo, fecha_, director, tipoTrabajo, juradoUno, juradoDos, 0, -1 );
            it->ingresarCriterios();
        }
        contador++;
    }
    cout << "paso\n";
    cout << "Termino construir acta" << endl;
    //it->setActa(acta);
    //cout<<"Fecha: "<<fecha<<endl;
    //it->recibirDatos( nombreTrabajo, fecha_, director, tipoTrabajo, juradoUno, juradoDos, 0, -1 );
    
    
    cout << "Termono set" << endl;
    //it->ingresarCriterios();
}

void Universidad::diligenciarCalifaciones(  ){
    return;
}
void Universidad::calcularNota(  ){
    return;
}

void Universidad::ingresarInformacionAdicional(  ){
    return;
}

void Universidad::cerrarActa(  ){
    return;
}

void Universidad::guardarInformacionActa(  ){
    return;
}

void Universidad::mostrarInformacionActa(  ){
    return;
}

void Universidad::listarActas(  ){
    return;
}

void Universidad::consultarListaCriterios(  ){
    return;
}

void Universidad::eliminarActas(  ){
    return;
}

string Universidad :: getFacultad(){
    return this->facultad;
}



