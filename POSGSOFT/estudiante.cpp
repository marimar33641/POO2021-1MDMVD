#include "estudiante.h"

//Constructor estudiante
Estudiante::Estudiante(  ){
}

Estudiante::Estudiante( string nombre, string identificacion, string email, string celular, Acta actaEstudiante, string id){
    this->nombre = nombre;
    this->identificacion = identificacion;
    this->email = email;
    this->celular = celular;
    this->actaEstudiante = actaEstudiante;
    this->id = id;
}
void Estudiante::mostrarEstudiante(  ){
    cout<<"===================="<<endl;
    cout<< "Nombre: "<< this-> nombre<<endl;
    cout<< "Id: "<< this-> identificacion<<endl;
    cout<< "Email: " << this->email<< endl;
    cout<< "Celular: " << this->celular<<endl;
    cout << "ID: " << this->id << endl;
}

void Estudiante::recibirDatos(  string nombreTrabajo, string fecha, Director director, int tipoTrabajo, Jurado juradoUno, Jurado juradoDos, float notaFinal, int estado ){
    actaEstudiante.setTituloActa( nombreTrabajo );
    actaEstudiante.setFechaActa( fecha );
    actaEstudiante.setDirector( director );
    actaEstudiante.setTipoTrabajo( tipoTrabajo );
    actaEstudiante.setJuradoUno( juradoUno );
    actaEstudiante.setJuradoDos( juradoDos );
    actaEstudiante.setNotaFinal( 0 );
    actaEstudiante.setEstado( -1 );
}

void Estudiante::setActa( Acta nuevaActa ){
    this->actaEstudiante = nuevaActa;
    this->actaEstudiante.mostrarActa();
}

void Estudiante::ingresarCriterios(  ){
    list<Criterio> listaCriterios;
    int contador = 1, aunmetarCriterio = 1;
    string nombreCriterio, observaciones, facultad, numeroActa;
    cout << "Ingrese el nombre de la facultad: " << endl;
    fflush(stdin);
    getline(cin, facultad);
    cout << "Ingrese el numero de acta: " << endl;
    fflush(stdin);
    getline(cin, numeroActa);
    int jurado, i, estado;
    float calificacionj1, calificacionj2, ponderacion, notaFinal = 0, calificacionFinal = 0;
    float totalPonderado = 0;
    cout<<"Aqui paso mi ex\n";
    do{
            if( contador == 1 ){
                nombreCriterio = "Desarrollo y profundidad en el tratamiento del tema\n";
            }
            else if( contador == 2 ){
                nombreCriterio = "Desafío académico y científico del tema\n";
            }
            else if( contador == 3){
                nombreCriterio = "Cumplimiento de los objetivos propuestos\n";
            }
            else if( contador == 4 ){
                nombreCriterio = "Creatividad e innovación de las soluciones y desarrollos propuestos\n";
            }
            else if( contador == 5 ){
                nombreCriterio = "Validez de los resultados y conclusiones\n";
            }
            else if(contador == 6){
                nombreCriterio = "Manejo y procesamiento de la información y bibliografía\n";
            }
            else if( contador == 7 ){
                nombreCriterio = "Calidad y presentación del documento escrito\n";
                
            }
            else if(contador == 8){
                nombreCriterio = "Presentación oral\n";
            }
            else if(totalPonderado < 100){
                cout << "Desea ingresar un nuevo criterio?"<<endl << "1.Si" << endl << "2.No";
                cin>>aunmetarCriterio;
                cout << "Si la suma de ponderados es menor que 100 y tu respuesta es 2, el ultimo ponderado se le sumara lo suficiente para que la suma sea 100 " << endl;
                /*
                Aumentar criterio en 1 es que agregará un nuevo criterio
                en 2 significa que ha terminado
                */
                if( aunmetarCriterio == 1 ){
                    cout << "Ingrese el nombre del nuevo criterio: " << endl;
                    fflush( stdin );
                    getline( cin, nombreCriterio );                                                                           
                }
                else{
                    aunmetarCriterio = 2;
                }
            }
            else{
                aunmetarCriterio = 2;
            }
            if(aunmetarCriterio != 1 && totalPonderado < 100){
                notaFinal -= ( ponderacion * ( calificacionj1 / 100 ) ) / 2;
                notaFinal -= ( ponderacion * ( calificacionj2 / 100 ) ) / 2;
                ponderacion = 100 - (totalPonderado - ponderacion);
                notaFinal += ( ponderacion * ( calificacionj1 / 100 ) ) / 2;
                notaFinal += ( ponderacion * ( calificacionj2 / 100 ) ) / 2;
                listaCriterios.pop_back(); //Borra el ultimo
                listaCriterios.push_back(Criterio(nombreCriterio, calificacionFinal , ponderacion, observaciones, jurado));
            }
            if(aunmetarCriterio == 1){
                cout<< contador <<". " << nombreCriterio;
                contador++;
                cout << "Ingrese la calificacion del criterio (Jurado 1): "<<endl;
                cin >> calificacionj1;
                cout << "(Jurado 2): "<<endl;
                cin >> calificacionj2;
            
                do{
                    cout << "Ingrese el ponderado de el criterio: (la suma hasta ahora es: " << totalPonderado << ")" << endl;
                    cin >> ponderacion;
                    if(totalPonderado + ponderacion > 100){
                        cout<< "La suma de ponderaciones no puede ser mayor a 100" << endl;
                    }
                    }while( totalPonderado + ponderacion > 100 );
                    totalPonderado += ponderacion;
                notaFinal += ( ponderacion * ( calificacionj1 / 100 ) ) / 2;
                notaFinal += ( ponderacion * ( calificacionj2 / 100 ) ) / 2;
                cout << "Ingrese las observaciones pertinentes: " << endl;
                fflush(stdin);
                getline(cin, observaciones);
                jurado = 1;
                //Comprobacion de que la suma ponderado es igual a 100
                
                //Se añade en la lista de criterios
                cout<<"calificacion 1: "<< calificacionj1 << endl;
                cout<<"calificacion 2: "<< calificacionj2 << endl;
                calificacionFinal = (calificacionj1 + calificacionj2)/2;

                listaCriterios.push_back(Criterio(nombreCriterio, calificacionFinal , ponderacion, observaciones, jurado));
        
            }     
        }while( aunmetarCriterio == 1 );
        actaEstudiante.setListaCriterios(listaCriterios);
        actaEstudiante.setNotaFinal(notaFinal);
        do{
            cout << "Desea cerrar el acta?" << endl << "1. Si" << endl << "2.No" << endl;
            cin >> estado;
        } while ( estado != 1 && estado != 2 );
        actaEstudiante.setEstado(estado);
        crearTxt( facultad, numeroActa, notaFinal );
    } 

void Estudiante::crearTxt( string facultad, string numeroActa, float notaFinal ){
    string nombreArchivo;
    list <Criterio> listaCriteriosEstudiante;
    int i = 1, notaFinalEntera;
    int decimales;
    ofstream archivo;
    cout << "Ingrese el nombre del archivo: " << endl;
    fflush(stdin);
    getline(cin, nombreArchivo);
    nombreArchivo = nombreArchivo + ".txt";
    archivo.open(nombreArchivo.c_str(), ios::out);
    if( archivo.fail() ){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    else{
        archivo << facultad << endl;
        archivo << "ACTA: " << numeroActa << endl;
        archivo << "Fecha: " << actaEstudiante.getFecha() << endl;
        archivo << "ACTA DE EVALUACION DE TRABAJO DE GRADO" << endl << endl;
        archivo << "Trabajo de grado denominado "<<actaEstudiante.getTitulo() <<endl;
        archivo << endl << "Autor: " << nombre << "   ID: " << id << endl << endl;
        archivo << "Director: " << actaEstudiante.getNombreDirectorActa() << endl << endl;
        if(actaEstudiante.getModalidad() == 1){
            archivo << "Modalidad: Aplicado "<<endl<<endl;
        }
        else{
            archivo << "Modalidad: Investigacion "<<endl<<endl;
        }
        archivo << "Jurado 1: " << actaEstudiante.getNombreJuradoUnoActa() << endl << endl;
        archivo << "Jurado 2: " << actaEstudiante.getNombreJuradoDosActa() << endl << endl;
        cout << "En atención al desarrollo de este Trabajo de Grado y al documento y sustentación que presentó el(la) autor(a), los Jurados damos las siguientes calificaciones parciales y observaciones  (los criterios a evaluar y sus ponderaciones se estipulan en el artículo 7.1 de las Directrices para Trabajo de Grado de Maestría)" << endl << endl;
        listaCriteriosEstudiante = actaEstudiante.getListaCriterios();
        for( list<Criterio>::iterator it = listaCriteriosEstudiante.begin(); it != listaCriteriosEstudiante.end(); it++ ){
            
            archivo << i << ". ";
            archivo << it->getNombreCriterio() << endl;
            archivo << "Calificacion Parcial: " << it->getCalificacion() << endl;
            archivo << "Ponderacion: " << it->getPonderacion() << "%" << endl; 
            archivo << "Observaciones: " << it-> getObservaciones() << endl;
            archivo << "------------------------------------------------------------------" << endl;
            archivo << "------------------------------------------------------------------" << endl;
            i++;
        }
        archivo << "Como resultado de estas calificaciones parciales y sus ponderaciones, la calificación del Trabajo de Grado es: " << notaFinal << endl << endl;
        archivo << notaFinal << endl;
        archivo << "Numero" << endl;
        notaFinalEntera = notaFinal;
        switch (notaFinalEntera){
        case 1:
            archivo << "Uno Punto ";
            break;
        case 2:
            archivo << "Dos Punto ";
            break;
        case 3:
            archivo << "Tres Punto ";
            break;
        case 4:
            archivo << "Cuatro Punto ";
            break;
        case 5:
            archivo << "Cinco Punto ";
            break;
        case 0:
            archivo << "Cero Punto ";
        }
        decimales = (notaFinal - notaFinalEntera)*10;
        switch (decimales){
        case 1:
            archivo << "Uno";
            break;
        case 2:
            archivo << " Dos ";
            break;
        case 3:
            archivo << "Tres ";
            break;
        case 4:
            archivo << "Cuatro ";
            break;
        case 5:
            archivo << "Cinco";
            break;
        case 6:
            archivo << "Seis";
            break;
        case 7:
            archivo << "Siete";
            break;
        case 8:
            archivo << "Ocho";
            break;
        case 9:
            archivo << "Nueve";
            break;
        case 0:
            archivo << "Cero";
        }
        archivo << endl;
        archivo << "Letras"<<endl;
    }
    archivo.close();
}
