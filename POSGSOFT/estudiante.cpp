#include "estudiante.h"

//Constructor estudiante
Estudiante::Estudiante()
{
}

Estudiante::Estudiante(string nombre, string identificacion, string email, string celular, Acta actaEstudiante, string id)
{
    this->nombre = nombre;
    this->identificacion = identificacion;
    this->email = email;
    this->celular = celular;
    this->actaEstudiante = actaEstudiante;
    this->id = id;
}
void Estudiante::mostrarEstudiante()
{
    /*Funsion para mostrar la informacion basica de un estudiante*/
    cout << "====================" << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Id: " << this->identificacion << endl;
    cout << "Email: " << this->email << endl;
    cout << "Celular: " << this->celular << endl;
    cout << "ID: " << this->id << endl;
}

void Estudiante::recibirDatos(string nombreTrabajo, string fecha, Director director, int tipoTrabajo, Jurado juradoUno, Jurado juradoDos, float notaFinal, int estado)
{
    /*Aqui recibimos todos los datos de un acta, le enviamos nota final como 0 y estado como -1 puesto qeu todavia no obtenemos estos datos*/
    /*Esto lo traemos para poder modificar el objeti de tipo acta mediante los sets*/
    actaEstudiante.setTituloActa(nombreTrabajo);
    actaEstudiante.setFechaActa(fecha);
    actaEstudiante.setDirector(director);
    actaEstudiante.setTipoTrabajo(tipoTrabajo);
    actaEstudiante.setJuradoUno(juradoUno);
    actaEstudiante.setJuradoDos(juradoDos);
    actaEstudiante.setNotaFinal(0);
    actaEstudiante.setEstado(-1);
}

void Estudiante::setActa(Acta nuevaActa){

    this->actaEstudiante = nuevaActa;
    this->actaEstudiante.mostrarActa();
}

void Estudiante::ingresarCriterios(){
    /*Funsion que pode todas las cosas que tiene un criterio y va creando objetos de este tipo y las va ingresando en una lista*/
    list<Criterio> listaCriterios;
    int contador = 1, aunmetarCriterio = 1, opcionObservacion = 0;
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
    cout << "Aqui paso mi ex\n";
    do
    {
        /*Estos son los criterios por defecto que si o si se van a pedir, luego se pueden agragar mas*/
        if (contador == 1)
        {
            nombreCriterio = "Desarrollo y profundidad en el tratamiento del tema\n";
        }
        else if (contador == 2)
        {
            nombreCriterio = "Desafio academico y cientifico del tema\n";
        }
        else if (contador == 3)
        {
            nombreCriterio = "Cumplimiento de los objetivos propuestos\n";
        }
        else if (contador == 4)
        {
            nombreCriterio = "Creatividad e innovacion de las soluciones y desarrollos propuestos\n";
        }
        else if (contador == 5)
        {
            nombreCriterio = "Validez de los resultados y conclusiones\n";
        }
        else if (contador == 6)
        {
            nombreCriterio = "Manejo y procesamiento de la informacion y bibliografia\n";
        }
        else if (contador == 7)
        {
            nombreCriterio = "Calidad y presentacion del documento escrito\n";
        }
        else if (contador == 8)
        {
            nombreCriterio = "Presentacion oral\n";
        }
        else if (totalPonderado < 100)
        {
            cout << "Desea ingresar un nuevo criterio?" << endl
                 << "1.Si" << endl
                 << "2.No" << endl;
            cout << "Opc: ";
            cin >> aunmetarCriterio;
            cout << "Si la suma de ponderados es menor que 100 y tu respuesta es 2, el ultimo ponderado se le sumara lo suficiente para que la suma sea 100 " << endl;
            /*
                Aumentar criterio en 1 es que agregará un nuevo criterio
                en 2 significa que ha terminado
                */
            if (aunmetarCriterio == 1){
                cout << "Ingrese el nombre del nuevo criterio: " << endl;
                fflush(stdin);
                getline(cin, nombreCriterio);
            }
            else
            {
                aunmetarCriterio = 2;
            }
        }
        else{
            aunmetarCriterio = 2;
        }
        if (aunmetarCriterio != 1 && totalPonderado < 100){
            /*En caso de que ya no quiera agragar un nuevo criterio, y la suma de ponderado sea menor que 100 esta funcion hace que el ultimo criterio tenga la ponderacion necesaria para que la suma sea 100 y de paso modificamos la nota final*/
            notaFinal -= (ponderacion * (calificacionj1 / 100)) / 2;
            notaFinal -= (ponderacion * (calificacionj2 / 100)) / 2;
            ponderacion = 100 - (totalPonderado - ponderacion);
            notaFinal += (ponderacion * (calificacionj1 / 100)) / 2;
            notaFinal += (ponderacion * (calificacionj2 / 100)) / 2;
            listaCriterios.pop_back(); //Borra el ultimo
            listaCriterios.push_back(Criterio(nombreCriterio, calificacionFinal, ponderacion, observaciones, jurado));
        }
        if (aunmetarCriterio == 1)
        {
            cout << contador << ". " << nombreCriterio;
            contador++;
            cout << " Ingrese la calificacion del criterio (Jurado 1): " << endl;
            cin >> calificacionj1;
            cout << " (Jurado 2): " << endl;
            cin >> calificacionj2;

            do
            {
                cout << " Ingrese el ponderado de el criterio: (la suma hasta ahora es: " << totalPonderado << ")" << endl;
                cin >> ponderacion;
                if (totalPonderado + ponderacion > 100)
                {
                    cout << " La suma de ponderaciones no puede ser mayor a 100" << endl;
                }
            } while (totalPonderado + ponderacion > 100);
            totalPonderado += ponderacion;
            notaFinal += (ponderacion * (calificacionj1 / 100)) / 2;
            notaFinal += (ponderacion * (calificacionj2 / 100)) / 2;
            cout << " Ingrese las observaciones pertinentes: " << endl;
            fflush(stdin);
            getline(cin, observaciones);
            jurado = 1;
            //Comprobacion de que la suma ponderado es igual a 100

            //Se añade en la lista de criterios
            cout << "calificacion 1: " << calificacionj1 << endl;
            cout << "calificacion 2: " << calificacionj2 << endl;
            calificacionFinal = (calificacionj1 + calificacionj2) / 2;

            listaCriterios.push_back(Criterio(nombreCriterio, calificacionFinal, ponderacion, observaciones, jurado));
        }
    } while (aunmetarCriterio == 1);
    /*Cuando termonamos todos los criterios agregamos un objeto de tipo criterio que se llama observacines extra, de este modo fasilitamos la funcion de observaciones extra*/
    do{
        /*Comprobamos que no envie un dato erroneo*/
        cout << "Desea colocar observaciones extra?" << endl
             << "1.Si" << endl
            << "2.No" << endl
            << "Opc: ";
        cin >> opcionObservacion;
        if(opcionObservacion <= 0 || opcionObservacion > 2){
            cout << "Numero invalido" << endl;
        }
    }while(opcionObservacion <= 0 || opcionObservacion > 2);
    //si desea poner observaciones extra entramos aqui
    if (opcionObservacion == 1)
    {
        /*Ponemos ponderacion en 0 para que la nota de este objeto no afecte y calificacion final en -1 para tener un estandar de los criterios que no tienen nota*/
        nombreCriterio = "Observaciones Extra";
        ponderacion = 0;
        calificacionFinal = -1;
        cout << "Ingrese las obvservaciones: " << endl;
        fflush(stdin);
        getline(cin, observaciones);
        listaCriterios.push_back(Criterio(nombreCriterio, calificacionFinal, ponderacion, observaciones, jurado));
    }
    /*Para colocar las correciones hacemos lo mismo que para crear observaciones extra*/
    do{
        /*Comprobamos que ingrese un numero correcto*/
        cout << "Desea colocar Correciones?" << endl
            << "1.Si" << endl
            << "2.No" << endl
            << "Opc: ";
        cin >> opcionObservacion;
        if(opcionObservacion <= 0 || opcionObservacion > 2){
            cout << "Numero invalido" << endl;
        }
    }while(opcionObservacion <= 0 || opcionObservacion > 2);;
    if (opcionObservacion == 1)
    {
        /*Si desea hacer correciones entra aqui*/
        /*Calificacion final esta en -2 para saber si existen correciones y de paso hace el estandar y ponderacion esta en 0 para que su nota no afecte a la nota final*/
        nombreCriterio = "La calificacion final queda sujeta a que se implementen las siguientes correciones: ";
        ponderacion = 0;
        calificacionFinal = -2;
        cout << "Ingrese las correciones: " << endl;
        fflush(stdin);
        getline(cin, observaciones);
        listaCriterios.push_back(Criterio(nombreCriterio, calificacionFinal, ponderacion, observaciones, jurado));
    }
    /*Enviamos la lista de criterios finalmente a nuestro objeto de tipo acta*/
    actaEstudiante.setListaCriterios(listaCriterios);
    actaEstudiante.setNotaFinal(notaFinal);
    do
    {
        /*Comprobamos que no envie un dato erroneo*/
        cout << "Desea cerrar el acta?" << endl
             << "1. Si" << endl
             << "2.No" << endl;
        cin >> estado;
    } while (estado != 1 && estado != 2);
    actaEstudiante.setEstado(estado);
    crearTxt(facultad, numeroActa, notaFinal);
}

void Estudiante::crearTxt(string facultad, string numeroActa, float notaFinal)
{
    /*Creamos un archivo con el nombre que decida el usuario u le agragamos la extencion .txt*/
    string nombreArchivo;
    list<Criterio> listaCriteriosEstudiante;
    int i = 1, notaFinalEntera;
    int decimales;
    ofstream archivo;
    cout << "Ingrese el nombre del archivo: " << endl;
    fflush(stdin);
    getline(cin, nombreArchivo);
    nombreArchivo = nombreArchivo + ".txt";
    archivo.open(nombreArchivo.c_str(), ios::out);
    //validamos que se pudo abrir el archivo
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    else
    {
        archivo << facultad << endl;
        archivo << "ACTA: " << numeroActa << endl;
        archivo << "Fecha: " << actaEstudiante.getFecha() << endl;
        archivo << "ACTA DE EVALUACION DE TRABAJO DE GRADO" << endl
                << endl;
        archivo << "Trabajo de grado denominado " << actaEstudiante.getTitulo() << endl;
        archivo << endl
                << "Autor: " << nombre << "   ID: " << id << endl
                << endl;
        archivo << "Director: " << actaEstudiante.getNombreDirectorActa() << endl
                << endl;
        if (actaEstudiante.getModalidad() == 1)
        {
            archivo << "Modalidad: Aplicado " << endl
                    << endl;
        }
        else
        {
            archivo << "Modalidad: Investigacion " << endl
                    << endl;
        }
        archivo << "Jurado 1: " << actaEstudiante.getNombreJuradoUnoActa() << endl
                << endl;
        archivo << "Jurado 2: " << actaEstudiante.getNombreJuradoDosActa() << endl
                << endl;
        cout << "En atencion al desarrollo de este Trabajo de Grado y al documento y sustentación que presento el(la) autor(a), los Jurados damos las siguientes calificaciones parciales y observaciones  (los criterios a evaluar y sus ponderaciones se estipulan en el artículo 7.1 de las Directrices para Trabajo de Grado de Maestria)" << endl
             << endl;
        /*Recorremos la lista de criterios para mostrar uno por uno y ponerlo en el txt*/
        listaCriteriosEstudiante = actaEstudiante.getListaCriterios();
        for (list<Criterio>::iterator it = listaCriteriosEstudiante.begin(); it != listaCriteriosEstudiante.end(); it++)
        {

            archivo << i << ". ";
            archivo << it->getNombreCriterio() << endl;
            if (it->getCalificacion() != -1 && it->getCalificacion() != -2)
            {
                archivo << "Calificacion Parcial: " << it->getCalificacion() << endl;
            }
            if (it->getPonderacion() != 0)
            {
                archivo << "Ponderacion: " << it->getPonderacion() << "%" << endl;
            }
            archivo << "Observaciones: " << it->getObservaciones() << endl;
            archivo << "------------------------------------------------------------------" << endl;
            archivo << "------------------------------------------------------------------" << endl;
            i++;
        }

        archivo << "Como resultado de estas calificaciones parciales y sus ponderaciones, la calificación del Trabajo de Grado es: " << notaFinal << endl
                << endl;
                /*Sacamos la nota final y de paso la igualamos a una variable int, para tener el primer numero y asi poder tenerlo en letras*/
        archivo << notaFinal << endl;
        archivo << "Numero" << endl;
        notaFinalEntera = notaFinal;
        switch (notaFinalEntera)
        {
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
        /*Sacamos las decimales con esta operacion y tendriamos todo lo necesario para poner en el txt la nota en letras*/
        decimales = (notaFinal - notaFinalEntera) * 10;
        switch (decimales)
        {
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
        archivo << "Letras" << endl;
    }
    //cerramos el archivo
    archivo.close();
    archivo << endl;
    archivo << "------------------------------------------------------------------" << endl;
    list<Criterio>:: iterator it = listaCriteriosEstudiante.begin();
    for(i = 1; i < listaCriteriosEstudiante.size(); i++){
        it++;
    }

    if( notaFinal >= 3.5 && it->getCalificacion() != -2){
        archivo << "Aprobado" << endl;
    }

    else if( notaFinal >= 3.5 && it->getCalificacion() == -2 ){
        archivo << "Pendiente" << endl;
    }
    else{
        archivo << "Reprobado" << endl;
    }
}

void Estudiante::mostrarActa(){
    /*Hacemos lo mismo que crear txt pero cambiamos la palabra archivo por cout, ademas de obviamente no crear el archivo*/
    string nombreArchivo;
    list<Criterio> listaCriteriosEstudiante;
    int i = 1, notaFinalEntera;
    int decimales;
    float notaFinal;
    notaFinal = actaEstudiante.getNotaFinal();
    cout << "Fecha: " << actaEstudiante.getFecha() << endl;
    cout << "ACTA DE EVALUACION DE TRABAJO DE GRADO" << endl
            << endl;
    cout << "Trabajo de grado denominado " << actaEstudiante.getTitulo() << endl;
    cout << endl
            << "Autor: " << nombre << "   ID: " << id << endl
            << endl;
    cout << "Director: " << actaEstudiante.getNombreDirectorActa() << endl
            << endl;
    if (actaEstudiante.getModalidad() == 1)
    {
        cout << "Modalidad: Aplicado " << endl
                << endl;
    }
    else
    {
        cout << "Modalidad: Investigacion " << endl
                << endl;
    }
    cout << "Jurado 1: " << actaEstudiante.getNombreJuradoUnoActa() << endl
            << endl;
    cout << "Jurado 2: " << actaEstudiante.getNombreJuradoDosActa() << endl
            << endl;
    cout << "En atención al desarrollo de este Trabajo de Grado y al documento y sustentación que presentó el(la) autor(a), los Jurados damos las siguientes calificaciones parciales y observaciones  (los criterios a evaluar y sus ponderaciones se estipulan en el artículo 7.1 de las Directrices para Trabajo de Grado de Maestría)" << endl
         << endl;
    listaCriteriosEstudiante = actaEstudiante.getListaCriterios();
    for (list<Criterio>::iterator it = listaCriteriosEstudiante.begin(); it != listaCriteriosEstudiante.end(); it++)
    {

        cout << i << ". ";
        cout << it->getNombreCriterio() << endl;
        if (it->getCalificacion() != -1 && it->getCalificacion() != -2)
        {
            cout << "Calificacion Parcial: " << it->getCalificacion() << endl;
        }
        if (it->getPonderacion() != 0)
        {
            cout << "Ponderacion: " << it->getPonderacion() << "%" << endl;
        }
        cout << "Observaciones: " << it->getObservaciones() << endl;
        cout << "------------------------------------------------------------------" << endl;
        cout << "------------------------------------------------------------------" << endl;
        i++;
    }
    cout << "Como resultado de estas calificaciones parciales y sus ponderaciones, la calificación del Trabajo de Grado es: " << notaFinal << endl
            << endl;
    cout << notaFinal << endl;
    cout << "Numero" << endl;
    notaFinalEntera = notaFinal;
    switch (notaFinalEntera)
    {
    case 1:
        cout << "Uno Punto ";
        break;
    case 2:
        cout << "Dos Punto ";
        break;
    case 3:
        cout << "Tres Punto ";
        break;
    case 4:
        cout << "Cuatro Punto ";
        break;
    case 5:
        cout << "Cinco Punto ";
        break;
    case 0:
        cout << "Cero Punto ";
    }
    decimales = (notaFinal - notaFinalEntera) * 10;
    switch (decimales)
    {
    case 1:
        cout << "Uno";
        break;
    case 2:
        cout << " Dos ";
        break;
    case 3:
        cout << "Tres ";
        break;
    case 4:
        cout << "Cuatro ";
        break;
    case 5:
        cout << "Cinco";
        break;
    case 6:
        cout << "Seis";
        break;
    case 7:
        cout << "Siete";
        break;
    case 8:
        cout << "Ocho";
        break;
    case 9:
        cout << "Nueve";
        break;
    case 0:
        cout << "Cero";
    }
    cout << endl;
    cout << "Letras" << endl;
    cout << endl;
    cout <<"------------------------------------------------------------------" << endl;
    /*un for para recorrer saber hasta donde va a ir. Luego si el getCalificacion es igual -2 es por que si tiene correcciones*/
    list<Criterio>:: iterator it = listaCriteriosEstudiante.begin();
    for(i = 1; i < listaCriteriosEstudiante.size(); i++){
        it++;
    }
    if( notaFinal >= 3.5 && it->getCalificacion() != -2){
        cout << "Aprobado" << endl;
    }
    else if( notaFinal >= 3.5 && it->getCalificacion() == -2 ){
        cout << "Pendiente" << endl;
    }
    else{
        cout << "Reprobado" << endl;
    }
}

/*Menu principal para modificar*/

void Estudiante:: menuModificar(){
    cout << "1. Modificar informaion estudiante "<<endl;
    cout << "2. Modificar informacion general de acta "<<endl;
    cout << "3. Modificar informacion criterios  y calificaciones" << endl;
    cout << "0. Salir de modificar" << endl;
    cout << "Opc: ";
}

/*Menu para modificar informacion estudiante*/

void Estudiante::menuModificarInformacionEstudiante(){
    cout << "1. Modificar Nombre" << endl;
    cout << "2. Modificar identificacion" << endl;
    cout << "3. Modificar email"<<endl;
    cout << "4. Modificar celular"<<endl;
    cout << "5. Modificar id"<<endl;
    cout << "0. Salir" << endl;
    cout<< "Opc: ";
}

void Estudiante :: modificarInformacionEstudiante(){
    int opc;
    string nuevoDato;
    /* aqui modificamos la info del estudiante y damos las ociones que tenemos para modificar*/
    do{
        menuModificarInformacionEstudiante();
        cin>>opc;
        switch (opc)
        {
        case 1:
            cout << "Ingrese el nuevo nombre: ";
            fflush( stdin );
            getline( cin, nuevoDato );
            setNombre( nuevoDato );
            break;
        case 2:
            cout << "Ingrese la nueva identificacion: ";
            fflush (stdin );
            getline( cin, nuevoDato );
            setIdentificacion( nuevoDato );
            break;
        case 3:
            cout << "Ingrese el nuevo email: ";
            fflush( stdin);
            getline( cin, nuevoDato );
            setEmail( nuevoDato );
            break;
        case 4:
            cout << "Ingrese el nuevo celular: ";
            fflush( stdin );
            getline( cin, nuevoDato );
            setCelular( nuevoDato );
            break;
        case 5:
            cout<< "Ingrese el nuevo id: ";
            fflush( stdin );
            getline( cin, nuevoDato );
            setId( nuevoDato );
            break;
        case 0:
            cout << "Salio de modificar estudiante" << endl;
            break;
        default:
            cout << "Numero invalido" << endl;
            break;
        }
         
     }while( opc !=0 );

}

void Estudiante :: modificarActa(){
    int opc;
    float notaFinalNueva = 0;
    string facultad, numeroActa;
    /*Damos todas las opciones que se pueden modificar tanto de acta como de estudiante*/
    do{
        menuModificar();
        cin >>opc;
        switch (opc){
        case 1:
            modificarInformacionEstudiante();
            break;
        case 2:
            actaEstudiante.modificarInformacionActaGeneral();
            break;
        case 3:
            actaEstudiante.modificarInformacionCriterios();
            break;
        case 0:
            cout << "Salio de modificar" << endl;
            break;
        default:
            cout << "Numero invalido" << endl;
            break;
        }
    }while(opc != 0);
    /*Calculamos de nuevo la nota final en caso de que se alla entrado en la opcion de modificar algun criterio, que contiene nota*/
    notaFinalNueva = actaEstudiante.calcularNotaFinal();
    cout << "Ingrese la facultad: " << endl;
    fflush(stdin);
    getline(cin, facultad);
    cout << "Ingrese el nuevo numero de acta: " << endl;
    fflush(stdin);
    getline(cin, numeroActa);

    crearTxt(facultad, numeroActa, notaFinalNueva );
}

void Estudiante :: setNombre( string nombre ){
    this->nombre = nombre;
}
void Estudiante::setIdentificacion( string identificacion ){
    this->identificacion = identificacion;
}

void Estudiante :: setEmail ( string email ){
    this->email = email;
}

void Estudiante :: setCelular( string celular ){
    this->celular = celular;
}

void Estudiante :: setId( string id ){
    this->id = id;
}

int Estudiante::getEstadoEstudiante(){
    return actaEstudiante.getEstado();
}

int Estudiante::getTipoTrabajoEstudiante(){
    return actaEstudiante.getModalidad();
}

string Estudiante::getJuradoUno(){
    return actaEstudiante.getJuradoActaUno();
}

string Estudiante::getJuradoDos(){
    return actaEstudiante.getJuradoActaDos();
}

string Estudiante::getDirector(){
    return actaEstudiante.getDirectorActa();
}

float Estudiante:: getNotaFinal(){
    return actaEstudiante.calcularNotaFinal();
}

int Estudiante::getExisteCorrecionesEstudiante(){
    return actaEstudiante.getExisteCorreciones();
}