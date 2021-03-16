#include "estudiante.h"

//Constructor estudiante
Estudiante::Estudiante(  ){
    this->nombre = "NA"; 
    this->identificacion = "NA";
    this->email = "NA";
    this->celular = "NA";
    this->actaEstudiante = actaEstudiante;
    this->id = "NA";
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

void Estudiante::setActa( Acta acta ){
    this->actaEstudiante = acta;
}

void Estudiante::ingresarCriterios(  ){
    list<Criterio> listaCriterios;
    int contador = 1, aunmetarCriterio = 1;
    string nombreCriterio, observaciones;
    int jurado, i, estado;
    float calificacion, ponderacion, notaFinal = 0;
    float totalPonderado = 0;

    for( i = 0 ; i < 2; i++ ){
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
            else{
                
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
            }
            contador++;
            cout<< contador <<". " << nombreCriterio;
            cout << "Ingrese la calificacion del criterio :"<<endl;
            cin >> calificacion;
            if (i == 1){
                do{
                    cout << "Ingrese el ponderado de el criterio: (la suma hasta ahora es: " << totalPonderado << ")" << endl;
                    cin >> ponderacion;
                    if(totalPonderado + ponderacion > 100){
                        cout<< "La suma de ponderaciones no puede ser mayor a 100" << endl;
                    }
                }while( totalPonderado + ponderacion > 100 );
                totalPonderado += ponderacion;
            }
            notaFinal += ( ponderacion * ( calificacion / 100 ) ) / 2;
            

            cout << "Ingrese las observaciones pertinentes: " << endl;
            fflush(stdin);
            getline(cin, observaciones);
            jurado = i;
            //Comprobacion de que la suma ponderado es igual a 100
            if(aunmetarCriterio == 2 && totalPonderado < 100){
                ponderacion += 100 - totalPonderado;
            }
            //Se añade en la lista de criterios
            listaCriterios.push_back(Criterio(nombreCriterio, calificacion, ponderacion, observaciones, jurado));
        
        }while( aunmetarCriterio == 1 );
        actaEstudiante.setListaCriterios(listaCriterios);
        actaEstudiante.setNotaFinal(notaFinal);
        do{
            cout << "Desea cerrar el acta?" << endl << "1. Si" << endl << "2.No" << endl;
            cin >> estado;
        } while ( estado != 1 && estado != 2 );
        actaEstudiante.setEstado(estado);
    } 

}

