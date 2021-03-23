#include "acta.h"

/*Creamos el constructor por defecto*/
Acta::Acta( ){

}

/*Creamos el constructor con sus parametros*/
Acta::Acta( string titulo, string fecha , Director director , int tipoTrabajo, Jurado jurado1, Jurado jurado2, float notafinal , int estado, list<Criterio> listaCriterios ){
    this-> titulo = titulo;
    this-> fecha = fecha;
    this-> director = director;
    this-> tipoTrabajo = tipoTrabajo;
    this-> jurado1 = jurado1;
    this-> jurado2 = jurado2;
    this-> notaFinal = notaFinal;
    this-> estado = estado;
    this-> listaCriterios = listaCriterios;
}
/*Hacemos set de todos los atributos que hay en Acta */
void Acta::setTituloActa( string titulo ){
    this->titulo = titulo;
}

void Acta::setFechaActa( string fecha ){
    this->fecha = fecha;
}

void Acta::setDirector( Director director ){
    this-> director = director;
}

void Acta::setTipoTrabajo( int tipoTrabajo ){
    this->tipoTrabajo = tipoTrabajo;
}

void Acta::setJuradoUno( Jurado juradoUno ){
    this->jurado1 = juradoUno;
}

void Acta::setJuradoDos( Jurado juradoDos ){
    this->jurado2 = juradoDos;
}

void Acta::setNotaFinal( float notaFinal ){
    this->notaFinal = notaFinal;
}

/*Hacemos get de todos los atributos de Acta*/
float Acta::getNotaFinal(){
    return this->notaFinal;
}

void Acta::setEstado( int estado ){
    this->estado = estado;
}

void Acta::setListaCriterios( list<Criterio> listaCriterios ){
    this->listaCriterios = listaCriterios;
}

string Acta::getFecha(){
    return this->fecha;
}

string Acta::getTitulo(){
    return this->titulo;
}

int Acta::getModalidad(){
    return this->tipoTrabajo;
}

string Acta::getNombreJuradoUnoActa( ){
    return this->jurado1.getNombreJurado();
}

string Acta::getNombreJuradoDosActa( ){
    return this-> jurado2.getNombreJurado();
}

string Acta::getNombreDirectorActa(){
    return this->director.getNombreDirector();
}

list <Criterio> Acta::getListaCriterios(){
    return this->listaCriterios;
}

/*Se muestra lo que hay en acta*/

void Acta::mostrarActa(  ){
    cout<<"===================="<<endl;
    cout<<"Titulo: "<<titulo<<endl;
    cout<<"Fecha: "<<fecha<<endl;
    cout<<"Tipo de trabajo: "<<tipoTrabajo<<endl;
}

/*Se crea un menu de modificarInformacionActaGeneral*/

void Acta :: menuModificarActaGeneral(){
    cout<<"1. Modificar Titulo "<<endl;
    cout<<"2. Modificar Fecha "<<endl;
    cout<<"3.Modificar tipo de trabajo (aplicado / Investigacion)"<<endl;
    cout<<"4.Modificar estado (abierto / cerrado) "<< endl;
    cout << "0. Salir" << endl;
}

void Acta::modificarInformacionActaGeneral(){
    /*Damos las opciones para modificar en acta y pedimos los datos que se quieran modificar*/
    int opc;
    string nuevoDato;
    int nuevoDatoInt;
    do{
        menuModificarActaGeneral();
        cin>>opc;
        switch (opc){
        case 1:
            cout<< "Ingrese el nuevo titulo: ";
            fflush( stdin );
            getline( cin, nuevoDato );
            setTituloActa(nuevoDato);
            break;
        case 2:
            cout<< "Ingrese la fecha: ";
            fflush( stdin );
            getline( cin, nuevoDato );
            setFechaActa( nuevoDato );
            break;
        case 3:
            do{
                cout<<"Ingrese el nuevo tipo de trabajo: " << endl << "1. Aplicado" << endl << "2. Investigacion" << endl << "opc = ";
                cin>>nuevoDatoInt;
            }while(nuevoDatoInt <= 0 || nuevoDatoInt > 2);
            setTipoTrabajo( nuevoDatoInt );
            break;
        case 4:
            cout<<"Desea Cerrar el acta?: " << endl << "1. Si "<< endl << "2.No" << endl;
            cout<<"Opc: ";
            cin>>nuevoDatoInt;
            setEstado( nuevoDatoInt );
            break;
        case 0:
            cout << "Salio de modificar Acta Informacion general" << endl;
            break;
        default:
            cout << "Numero invalido" << endl;
            break;
        }
    }while(opc != 0);
}

/*Se crea un menu de menuModificarInformacionCriterios*/

void Acta :: menuModificarInformacionCriterios(){
    /*Mostramos todos los nombres de los criterios para que el usuario ingrese el que quiere modificar*/
    int i = 1;
    for( list<Criterio>::iterator it = listaCriterios.begin(); it != listaCriterios.end(); it++ ){
        cout << i << ". ";
        it->mostrarNombreCriterio();
        i++;
    }
    cout << "0. Salir" << endl;
    cout<<"Ingrese el numero que desea modificar: ";
}

float Acta :: modificarInformacionCriterios(){
    int opc, i, opc2;
    float nuevaCalificacion = 0, notaFinalNueva = 0;
    string nuevaObservacion;
    do{
        menuModificarInformacionCriterios();
        cin>>opc;
        if(opc != 0){
            list<Criterio> :: iterator it = listaCriterios.begin();
            for(i = 1; i < opc; i++){
                it++;
            }
            cout << "Desea modificar:" << endl << "1. Calificacion" << endl << "2. Observaciones" << endl << "opc: ";
            cin >> opc2;
            if( opc2 == 1 ){
                cout<<"Digite la nueva calificacion: ";
                cin>>nuevaCalificacion;
                it->setCalificacionCriterio( nuevaCalificacion );
                for( list<Criterio>::iterator it = listaCriterios.begin();it != listaCriterios.end(); it++ ){
                    notaFinalNueva += (it->getPonderacion() * it->getCalificacion()) / 100;
                } 
                setNotaFinal(notaFinalNueva);    
            }
            else if( opc2 == 2 ){
                cout<<"Digite la nueva observacion: ";
                fflush( stdin );
                getline( cin, nuevaObservacion );
                it->setObservacionCriterio( nuevaObservacion );
            }
            notaFinalNueva = 0;
        }
    }while(opc != 0);
    
}

float Acta::calcularNotaFinal(){
    /*Recorremos todos los criterios y vemos las notas para realizar la operacion que se necesita para calcular la nota*/
    float notaFinalNueva = 0;
    for( list<Criterio>::iterator it = listaCriterios.begin();it != listaCriterios.end(); it++ ){
        notaFinalNueva += it->getPonderacion() * it->getCalificacion() / 100;
    }
    return notaFinalNueva;
}

int Acta :: getEstado(){
    return this->estado;
}

string Acta::getJuradoActaUno(){
    return this->jurado1.getIdentificacion();
}

string Acta::getJuradoActaDos(){
    return this->jurado2.getIdentificacion();
}

string Acta::getDirectorActa(){
    return this->director.getIdentificacion();
}

int Acta::getExisteCorreciones(){
    int i;
    list<Criterio> :: iterator it = listaCriterios.begin();
    for(i = 1; i < listaCriterios.size() ; i++ ){
        it++;
    }   
    if(it->getCalificacion() == -2){
        return 1;
    }
    else{
        return 0;
    }
}

