#include "View.h"

//FUNCIONES DEL PROGRAMA


void View::pedirDatosTriangulo(){
    float base, altura;
    do{
        cout<< "Digite el valor de la base: "<< endl;
        cin >> base;
        cout << "Digite el valor de la altura" << endl;
        cin >>altura;
    }while( base <= 0 || altura <= 0 );
    controller.agregarTriangulo(base, altura);
}

void View::pedirDatosCuadrado(){
    float longitud;
    do{
        cout << "Digite el valor de la longitud " << endl;
        cin >> longitud;
    } while (longitud <= 0);

    controller.agregarCuadrado(longitud);
}

void View::pedirDatosRectangulo()
{
    // Se piden los datos y se valida para asegurar que estan bn
    float largo, ancho;
    do
    {
        cout << "Digite el valor del largo " << endl;
        cin >> largo;
        cout << "Digite el valor del ancho " << endl;
        cin >> ancho;
    } while (largo <= 0 || ancho <= 0);

    // Se llama al metodo del controller
    controller.agregarRectagulo(largo, ancho);
}

void View::pedirDatosCirculo()
{
    float radio;
    do
    {
        cout << "Digite el radio " << endl;
        cin >> radio;
    } while (radio <= 0);

    // Se llama al metodo del controller
    controller.agregarCirculo(radio);
}

void View::mostrarTriangulos(){
    int cont = 0;
    list<Triangulo> &refListaTriangulos = controller.getListaTriangulo();
    for( list<Triangulo>:: iterator it = refListaTriangulos.begin(); it != refListaTriangulos.end(); ++it ){
        cout <<"Triangulo " << ++cont << ":"<<endl;
        it->mostrarFigura();
    }
}

void View::mostrarCuadrados(){
    //  list<Clase_a_recorrer>:: iterator nombre_iterador = nombre_lista_de_Clase.begin(); it != nombre_lista_de_Clase.end(); i++;
    int cont = 0;
    list<Cuadrado> &refListaCuadrado = controller.getListaCuadrado();
    for (list<Cuadrado>::iterator it = refListaCuadrado.begin(); it != refListaCuadrado.end(); ++it){
        cout << "Cuadrado " << ++cont << ":" << endl;
        it->mostrarFigura();
    }
}

void View::mostrarCirculos(){
    int cont = 0;
    list<Circulo> &refListaCirculo = controller.getListaCirculo();
    for(list<Circulo>::iterator it = refListaCirculo.begin(); it != refListaCirculo.end(); ++it){
        cout<<"Circulo " << ++cont << ":" << endl;
        it->mostrarFigura();
    }
}

void View::mostrarRectangulos()
{
    //  list<Clase_a_recorrer>:: iterator nombre_iterador = nombre_lista_de_Clase.begin(); it != nombre_lista_de_Clase.end(); i++;
    int cont = 0;
    list<Rectangulo> &refListaRectangulo = controller.getListaRectangulo();
    for (list<Rectangulo>::iterator it = refListaRectangulo.begin(); it != refListaRectangulo.end(); ++it)
    {
        cout << "Rectangulo " << ++cont << ":" << endl;
        it->mostrarFigura();
    }
}

void View::mostrarTodos()
{
    // LLama al que llena las figuras
    //controller.llenarListaTodosDummy();

    list<FiguraGeometrica *> &pListaFiguras = controller.getListaFiguras();
    cout << "Cantidad de figuras " << pListaFiguras.size() << "\n";
    int cont = 0;
    for (list<FiguraGeometrica *>::iterator it = pListaFiguras.begin(); it != pListaFiguras.end(); ++it)
    {
        FiguraGeometrica *tmp = *it; // Por descifrar
        cout << "Figura con polimorfismo:" << ++cont << ":" << endl;
        tmp->mostrarFigura();
        cout << "\n";
    }
}

int View::mostrarMenu()
{
    int opcion;
    cout << "Menu\n"
         << std::endl;
    cout << "1. Agregar Rectangulos" << std::endl;
    cout << "2. Mostrar Rectangulos" << std::endl;
    cout << "3. Agregar Circulos" << std::endl;
    cout << "4. Mostrar Circulos" << std::endl;
    cout << "5. Agregar Triangulos" << std::endl;
    cout << "6. Mostrar Triangulos" << std::endl;
    cout << "7. [Todos] Mostrar todas figuras" << std::endl;
    cout << " 8.Agregar Cuadrados" << std::endl;
    cout << " 9.Mostrar Cuadrados" << std:: endl;
    cout << "11. Caso para pruebas" << std::endl;
    cout << "0. Salir\n"
         << std::endl;
    cout << "Digita el numero: ";
    cin >> opcion;
    return opcion;
}

void View::verPrincipal()
{
    int opcion;
    do
    {
        opcion = mostrarMenu();
        switch (opcion)
        {
        case 1: //Rectangulos
            pedirDatosRectangulo();
            break;
        case 2: //Mostrar Rectangulos
            mostrarRectangulos();
            break;
        case 3:
            pedirDatosCirculo();
            break;
        case 4:
            mostrarCirculos();
            break;
        case 5:
            pedirDatosTriangulo();
            break;
        case 6:
            mostrarTriangulos();
            break;
        case 7:
            mostrarTodos();
            break;
        case 8:
            pedirDatosCuadrado();
            break;
        case 9:
            mostrarCuadrados();
            break;
        case 11:
        {
            Rectangulo &rectangulo = controller.encontrarMayorAncho();
            rectangulo.mostrarFigura();
        }
        break;
        }
    } while (opcion != 0);
}