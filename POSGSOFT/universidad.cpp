
#include "universidad.h"
/*Se coloca dos enums para saber la ocupacion del jurado y el tipo de trabajo*/
enum trabajo{
    INTERNO = 1,
    EXTERNO = 2
};

enum TipoTrabajo{
    APLICADO = 1,
    INVESTIGACION = 2
};

/*Esta funcion es recorrer la lista de estudiantes. Desde begin (inicio) hasta que el it sea diferente al final de la lista. Luego se imprime los estudiantes(Funcion en estudiantes)*/
void Universidad::mostrarEstudiantes( ){
    for(list<Estudiante>::iterator it = listaEstudiantes.begin(); it != listaEstudiantes.end(); it++ )
    it->mostrarEstudiante();
}

/*Creamos una funcion de crear director donde le preguntamos todos lo datos necesarios y les hacemos push_back a la listaDirector, o sea, se cargan a la lista*/

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

/*Esta funcion es recorrer la lista de directores. Desde begin (inicio) hasta que el it sea diferente al final de la lista. Luego se imprime los directores(Funcion en director)*/

void Universidad::mostrarTodosDirectores(){
    for(list<Director>::iterator it = listaDirector.begin(); it != listaDirector.end(); it++ )
        it->mostrarDirector();
}

/*Creamos una funcion de crear jurado donde le preguntamos todos lo datos necesarios y les hacemos push_back a la listaJurado, o sea, se cargan a la lista*/

void Universidad::crearJurado( ){
    string nombreJurado;
    trabajo tipo;
    string identificacion;
    string email;
    string celular;
    cout << "Ingrese el nombre del nuevo jurado: " << endl;
    fflush(stdin);
    getline( cin, nombreJurado );
    do{
        cout << "Ingrese el tipo de trabajo que tiene el nuevo jurado: " << endl;
        cout << "1. Interno" << endl;
        cout << "2. Externo" << endl;
        scanf("%d", &tipo);
    }while( tipo <= 0 || tipo > 2 );
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
    /*Creamos un objeto de tipo juerado*/
    listaJurados.push_back(Jurado(nombreJurado,tipo, identificacion,email,celular));  
}

/*Esta funcion es recorrer la lista de jurados. Desde begin (inicio) hasta que el it sea diferente al final de la lista. Luego se imprime los jurados(Funcion en jurado)*/

void Universidad::mostrarJurados( ){
    for( list<Jurado>::iterator it = listaJurados.begin(); it != listaJurados.end(); it++ ){
        it->mostrarJurado( );
    }
}

/*Constructor de Universidad*/

Universidad::Universidad( ){
    this->nombre = "Pontificia Universidad Javeriana Cali";
}

/*Creamos una funcion de tipo Estudiante para retornar el estudiante (*it)*/

Estudiante Universidad::getListaEstudiante(){
    list<Estudiante>::iterator it = listaEstudiantes.begin();
    return *it;
}

/*Creamos una funcion de tipo Director para retornar el director (*it)*/

Director Universidad::getListaDirectores(){
    list<Director>::iterator it = listaDirector.begin();
    return *it;
}


void Universidad::crearEstudiante( ){
    /*Aqui vamos a crear un objeto de tipo estudiante, primero pedimos todos los datos necesarios*/
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
    listaEstudiantes.push_back(Estudiante(nombreEstudiante, identificacion,email,celular, actaVacia, id ));
    return;
}


/*Creamos una funcion de tipo Director el cual va a buscar el director por medio de un for desde begin (inicio) hasta que el it sea diferente al final de la lista. Y cuando ese i sea igual al numDirector es por que lo encontro y lo retorna*/

Director Universidad::buscarDirector( int numDirector ){
    int i = 1;
    for( list<Director>::iterator it = listaDirector.begin();it != listaDirector.end(); it++ ){
        if(i == numDirector){
            return *it;
        }
        i++;
    }   
}

/*Creamos una funcion de tipo Estudiante el cual va a buscar el estudiante por medio de un for desde begin (inicio) hasta que el it sea diferente al final de la lista. Y cuando ese i sea igual al numEstudiante es por que lo encontro y lo retorna*/

Estudiante Universidad::buscarEstudiante( int numEstudiante ){
    int i = 1;
    for( list<Estudiante>::iterator it = listaEstudiantes.begin();it != listaEstudiantes.end(); it++ ){
        if(i == numEstudiante){
            return *it;
        }
        i++;
    }   
}

/*Creamos una funcion de tipo Jurado el cual va a buscar el jurado por medio de un for desde begin (inicio) hasta que el it sea diferente al final de la lista. Y cuando ese i sea igual al numJurado es por que lo encontro y lo retorna*/

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
    /*Funcion que recorre la lista de jurados y retorna el que este en la posicion de num jurado*/
    int i = 1;
    for( list<Jurado>::iterator it = listaJurados.begin(); it != listaJurados.end(); it++ ){
        if( i == numJurado ){
            return *it;
        }
        i++;
    }
}

void Universidad::mostrarDirectores(  ){
    /*Funcion que muestra todos los jurados*/
    int i = 1;
    for( list<Director>::iterator it = listaDirector.begin(); it != listaDirector.end(); it++ ){
        cout<< i <<". ";
        it->mostrarDirector( );
        i++;
    }
}

void Universidad::crearNuevaActa( ){
    /*Pedimos todos los datos necesacion para crear un acta*/
    Director director;
    Jurado juradoUno;
    Jurado juradoDos;
    string fecha_;
    string nombreTrabajo;
    list<Criterio> listaCriteriosVacia;
    int tipoTrabajo, estado, numeroDirector, numeroJuradoUno = 0, numeroJuradoDos = 0, contador = 1;
    /*Creamos un nuevo estudiante quien sera el dueño del acta*/
    crearEstudiante();
    // Pedimos todos los datos que necesita un acta
    //enviamos una lista de criterios vasia que liego vamos a modificar
    cout << "Ingrese la fecha: " <<endl;
    fflush(stdin);
    getline(cin, fecha_);
    cout<< "Ingrese el titulo del trabajo: "<<endl;
    fflush(stdin);
    getline( cin, nombreTrabajo );
    cout << "Ingrese el tipo de trabajo: " << endl << "1.Aplicado" << endl << "2.Investigacion" << endl;
    cout << "opc = ";
    cin >> tipoTrabajo;
    /*Mostramos los directores para que elija*/
    mostrarDirectores();
    cout << "Ingrese el numero de director que dirigio este trabajo: " << endl;
    cin >> numeroDirector;

    /*Igualamos la variable director a la funcion donde se busca el director y le mandamos el numero que digito el usuario*/

    director = buscarDirector( numeroDirector );
    /*Mostramos los jurados para que elija*/
    mostrarJurados();
    cout << "Ingrese el numero del jurado numero 1: " << endl;
    cin >> numeroJuradoUno;
    /*Igualamos la variable jurado1 a la funcion donde se busca el jurado y le mandamos el numero que digito el usuario*/
    juradoUno = buscarJuradoUno(numeroJuradoUno);
    cout << "Ingrese el numero del jurado numero 2: " << endl;
    cin>>numeroJuradoDos;
    /*Igualamos la variable jurado2 a la funcion donde se busca el jurado y le mandamos el numero que digito el usuario*/
    juradoDos = buscarJuradoDos(numeroJuradoDos);

    /*Hacemos un for desde begin (inicio) hasta que el it sea diferente al final de la lista.Y si el contador es igual al tamaño de la listaEstudiantes va a ir a la funcion de recibirDatos e ingresarCriterios (funciones en estudiantes). Esto se hace para avanzar al otro de la lista*/
    for( list<Estudiante>::iterator it = listaEstudiantes.begin(); it != listaEstudiantes.end(); it++ ){
        if( contador == listaEstudiantes.size() ){
            it->recibirDatos( nombreTrabajo, fecha_, director, tipoTrabajo, juradoUno, juradoDos, 0, -1 );
            it->ingresarCriterios();
        }
        contador++;
    }
}

void Universidad::mostrarActa(){
    /*Mostramos todos los estudiantes y pedimos que ingrese el numero del estudiante que desea ver*/
    int i = 1, numeroEstudiante;
    Estudiante EstudianteMirar;
    for( list<Estudiante>::iterator it = listaEstudiantes.begin(); it != listaEstudiantes.end(); it++ ){
        cout << i << ". ";
        it->mostrarEstudiante();
        i++;
    }
    /*Comprobamos que ingrese un numero valido*/
    do{
        cout << "Ingrese el numero del estudiante de quien desea ver el acta: "<< endl;
        cin >> numeroEstudiante;
        if(numeroEstudiante <= 0 || numeroEstudiante > listaEstudiantes.size()){
            cout << "Numero invalido" << endl;
        }
    }while(numeroEstudiante <= 0 || numeroEstudiante > listaEstudiantes.size());
    EstudianteMirar =  buscarEstudiante( numeroEstudiante );
    EstudianteMirar.mostrarActa();
}

void Universidad :: modificarActaUniversidad(){
    /*Mostramos todos los estudiante para que escoja de cual desea modificar el acta y luego llegamos ahí por medio de un iterador y un for y llamamos a modificarActa que esta en estudiante*/
    int i = 1, numeroEstudiante;
    for( list<Estudiante>::iterator it = listaEstudiantes.begin(); it != listaEstudiantes.end(); it++ ){
        cout << i << ". ";
        it->mostrarEstudiante();
        i++;
    }
    do{
        cout << "Ingrese el numero del estudiante para modificar: "<< endl;
        cin >> numeroEstudiante;
    }while( numeroEstudiante <= 0 || numeroEstudiante > listaEstudiantes.size() );
    list<Estudiante>::iterator it = listaEstudiantes.begin();
    for( i = 1; i < numeroEstudiante; i++ ){
        it++;
    }
    /*Si el getEstadoEstudiante ==  1 es por que el acta esta cerrada, de lo contrario se lleva a la funcion de modificarActa(Funcion en Estudiante)*/
    if(it->getEstadoEstudiante() == 2){
        it->modificarActa();
    }
    else{
        cout << "El acta esta cerrada D:" << endl;
    }
}

void Universidad:: listarActasPorEstado(){
    /*Preguntamos si quiere listar las actas cerradas o abiertas*/
    /*tenemos que las listas que tengan un estado de 2 son las abiertas y si tienen un estado de 1 estan cerradas*/
    int opc;
    do{
        cout << "Desea listar las actas: " << endl<< "1. Abiertas" << endl << "2.Cerradas" << endl<< "opc = ";
        cin >> opc;
        if(opc != 1 && opc != 2){
            cout << "Numero invalido" << endl;
        }
    }while(opc != 1 && opc != 2);

    if( opc == 1 ){
        for( list<Estudiante>::iterator it = listaEstudiantes.begin(); it != listaEstudiantes.end(); it++ ){
            if( it->getEstadoEstudiante() == 2 ){
                it->mostrarEstudiante();
            } 
        }
    }
    else{
        for( list<Estudiante>::iterator it = listaEstudiantes.begin(); it != listaEstudiantes.end(); it++ ){
            if( it->getEstadoEstudiante() == 1 ){
                it->mostrarEstudiante();
            } 
        }
    }
}

void Universidad::borrarActa(){
    int opc,i;
    mostrarEstudiantes();
    cout << "Ingrese el numero del estudiante a eliminar: " << endl;
    cout << "opc = ";
    cin >> opc;
    /*Recorremos la lista de estudiantes hasta llegar al numero de estudiante que deseamos eliminar que seria el opc que escogió el usuario*/
    list<Estudiante> :: iterator it = listaEstudiantes.begin();
    for(i = 1; i < listaEstudiantes.size(); i++ ){
        it++;
        if( i == opc ){
            listaEstudiantes.erase(it);
            break;
        }
    }
}

void Universidad::listarActasPorTipoTrabajo(){
    /*preguntamos si quiere listar las actas Aplicadas o Investigacion*/
    /*tenemos que las listas que tengan un estado de 2 son las abiertas y si tienen un estado de 1 estan cerradas*/
    int opc;
    do{
        cout << "Desea listar las actas: " << endl<< "1. Aplicado" << endl << "2.Investigacion" << endl<< "opc = ";
        cin >> opc;
        if(opc != 1 && opc != 2){
            cout << "Numero invalido" << endl;
        }
    }while(opc != 1 && opc != 2);

    if( opc == 1 ){
        for( list<Estudiante>::iterator it = listaEstudiantes.begin(); it != listaEstudiantes.end(); it++ ){
            if( it->getTipoTrabajoEstudiante() == 1 ){
                it->mostrarEstudiante();
            } 
        }
    }
    else{
        for( list<Estudiante>::iterator it = listaEstudiantes.begin(); it != listaEstudiantes.end(); it++ ){
            if( it->getTipoTrabajoEstudiante() == 2 ){
                it->mostrarEstudiante();
            } 
        }
    }
}

/*Funcion para mostrar los jurados por su tipo.*/


/*Se hace un for de la lista de jurados y si el estado es igual a 1, se muestra el jurado con sus respectivos datos */

void Universidad::listarJuradoPorLugarTrabajo(){
    /*Si es interno el estado es igual a 1, si externo es igual a 2*/
    int opc;
    do{
        cout << "Ingrese que tipo de jurado desea ver" << endl << "1. interno" << endl << "2.Externo" << endl; "opc = ";
        cin >> opc;
        if(opc <= 0 || opc > 2){
            cout << "Numero invalido" << endl;
        }
    }while(opc <= 0 || opc > 2);
    if(opc == 1){
        for( list<Jurado>::iterator it = listaJurados.begin(); it != listaJurados.end(); it++ ){
            if(it->getEstado() == 1){
                it->mostrarJurado();
            } 
        }
    }
    else{
        for( list<Jurado>::iterator it = listaJurados.begin(); it != listaJurados.end(); it++ ){
            if(it->getEstado() == 2){
                it->mostrarJurado();
            } 
        }
    }
}

/*Creamos una funcion el cual recorremos la lista de estudiantes y hacemos que si el directorABuscar ( la id de ese director que el usuario ingreso) es igual al que esta en la lista, si es así pues se muestra la acta con los datos del estudiante.*/

void Universidad::listarActasPorDirector(){
    mostrarTodosDirectores();
    int opc;
    Director directorABuscar;
    cout << "Ingrese el numero del director: "<<endl;
    cin>>opc;
    directorABuscar = buscarDirector( opc );
    for( list<Estudiante>::iterator it = listaEstudiantes.begin(); it != listaEstudiantes.end(); it++ ){
        if( directorABuscar.getIdentificacion() == it->getDirector() ){
            it->mostrarEstudiante();
        }
    }
}

/*Creamos una funcion el cual recorremos la lista de estudiantes y hacemos que si el juradoABuscar ( la id de ese jurado que el usuario ingreso) es igual al que esta en la lista, si es así pues se muestra la acta con los datos del estudiante.*/


void Universidad :: listarActasPorJurado(){
    int opc;
    Jurado JuradoABuscar;
    mostrarJurados();
    cout << "Ingrese el numero del jurado: " << endl;
    cin >> opc;
    JuradoABuscar = buscarJuradoUno( opc );
    for( list<Estudiante>::iterator it = listaEstudiantes.begin(); it != listaEstudiantes.end(); it++ ){
        if(JuradoABuscar.getIdentificacion() == it->getJuradoUno() || JuradoABuscar.getIdentificacion() == it->getJuradoDos()){
            it->mostrarEstudiante();
        }
    }
}
void Universidad ::menuListarActasPorNota(){
    cout << "1. Ver actas Aprobadas "<<endl;
    cout << "2. Ver actas Pendientes" << endl;
    cout << "3. Ver actas Rechazadas" << endl;
    cout << "0. Salir" << endl;
    cout << "Opc: ";
}

void Universidad :: listarActasPorNota(){
    int opc;
    do{
        menuListarActasPorNota();
        cin >> opc;
        switch (opc)
        {
        case 1: 
            verActasPorNota( opc );
            break;
        case 2:
            verActasPorNota( opc );
            break;
        case 3:
            verActasPorNota( opc );
            break;
        case 0:
            cout << "Salio de ver actas por Nota" << endl;
            break;
        default:
            cout << "Numero invalido" << endl;
            break;
        }
    }while(opc != 0);
    
}

/*Creamos una funcion donde se ve las actas por nota (Pendiente, rechazadas, aprobadas). Si es 1 es aprobada, 2 Pendiente y 3 rechazada. Dependiendo de lo que se elija se muestra la informacion del estudiante*/

void Universidad :: verActasPorNota( int opc ){
    for( list<Estudiante>::iterator it = listaEstudiantes.begin(); it != listaEstudiantes.end(); it++ ){
        if( opc == 1 && it->getNotaFinal() >= 3.5 && it->getExisteCorrecionesEstudiante() == 0 ){
            it->mostrarEstudiante();
        } 
        else if( opc == 2 && it->getNotaFinal() >= 3.5 && it->getExisteCorrecionesEstudiante() == 1 ){
            it->mostrarEstudiante(); 
        }
        else if( opc == 3 && it->getNotaFinal() < 3.5 ) {
            it->mostrarEstudiante(); 
        }
    }
}