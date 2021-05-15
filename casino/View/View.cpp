//
// Created by lufe0 on 7/05/2021.
//

#include "View.h"

View::View(){
    controller = Controller();
}
void View::agregarJugador(){
    string nombreJugador;
    float dineroPesos;
    long idJugador;
    cout << "Ingrese el nombre del jugador \n";
    cin.ignore(100, '\n');
    getline(cin, nombreJugador);
    // Id del jugador
    cout << "Ingrese el id del jugador \n";
    cin >> idJugador;
    // Validacion de los datos del jugador
    do{
        cout << "Ingrese el dinero en pesos \n";
        cin >> dineroPesos;
    }while (dineroPesos <= 0);

    // Esta linea de codigo controla la excepcion que lanza el controller y lo muestra en pantalla
    try {
        controller.agregarJugador(idJugador, nombreJugador, dineroPesos);
    } catch (std::domain_error ex) {
        cout << "ERROR: " << ex.what();
    }
}

void View::pedirUsuario(){
    try {
        long idJugador;
        cout << "Ingrese el id del jugador para el que quiere jugar \n";
        cin >> idJugador;
        controller.verInfoJugador(idJugador);

        // LLama a la función que hacer toda la logica de jugar.
        jugarView(idJugador);

    }catch (std::domain_error ex){
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}

void View:: jugarView(long idJugador) {
    int opcion;
    float resultadoGonzos = 0;
    float cantGonzos;
    int idJuego;
    DosColores dosColores;
    Mayor13 mayor13;
    Ruleta ruleta;
    do{
        try {
            do {
                cout << "Cuantos gonzos desea apostar \n";
                cin >> cantGonzos;
                if( controller.getCasino().consultarJugador(idJugador)->getCantGonzos() <= cantGonzos ){
                    cout << "No tiene la cantidad de Gonzos suficientes\n";
                }
            } while (cantGonzos <= 0 || controller.getCasino().consultarJugador(idJugador)->getCantGonzos() <= cantGonzos );
            controller.getCasino().consultarJugador(idJugador)->actualizarGonzos(cantGonzos*-1);
            // Agregue el esto de la logica para el juego 1. Juego mayor a 13, 2 juego de dos colores.
            cout<<"1. Juego Mayor\n2.Juego de dos colores\n3.Juego de ruleta TODO O NADA\n0.Salir\nOpcion: "; cin>>opcion;
           if( opcion == 1 ){
                resultadoGonzos = mayor13.jugar(cantGonzos);
                controller.getCasino().consultarJugador(idJugador)->actualizarGonzos(resultadoGonzos);
                controller.getCasino().consultarJugador(idJugador)->aumentarJuegos();
                verPrincipal();
           }
           else if( opcion == 2 ){
                resultadoGonzos = dosColores.jugar(cantGonzos);
                controller.getCasino().consultarJugador(idJugador)->actualizarGonzos(resultadoGonzos);
                controller.getCasino().consultarJugador(idJugador)->aumentarJuegos();
                verPrincipal();
           }
           else if( opcion == 3 ){
               resultadoGonzos = ruleta.jugar(cantGonzos);
               controller.getCasino().consultarJugador(idJugador)->actualizarGonzos(resultadoGonzos);
               controller.getCasino().consultarJugador(idJugador)->aumentarJuegos();
               verPrincipal();
           }
           else{
               cout<<"Numero invalido\n";
           }
        } catch (std::domain_error ex){
            cout << ex.what();
        }
    }while (opcion!=0);
}

int View::mostrarMenu()
{
    int opcion;
    cout << "Menu\n";
    cout << "1. Agregar jugador " << std::endl;
    cout << "2. Jugar" << std::endl;
    cout << "3. Consultar jugador" << std::endl;
    cout << "4. Vender gonzos" << std::endl;
    cout << "5. Retirar jugador" << std::endl;
    cout << "0. Salir\n"
         << std::endl;
    cout << "Digita el numero: ";
    cin >> opcion;
    return opcion;
}

void View::verPrincipal(){
    int opcion;
    do{
        opcion = mostrarMenu();
        switch (opcion){
            case 1: agregarJugador();
                break;
            case 2:
                pedirUsuario();
                break;
            case 3:
                mostrarJugador();
                break;
            case 4:
                recargarGonzos();
                break;
            case 5:
                retirarJugador();
                break;
        }
    } while (opcion != 0);
}

void View::mostrarJugador(){
    try{
        long idJugador;
        cout << "Ingrese el id del jugador para el que quiere jugar \n";
        cin >> idJugador;
        controller.verInfoJugador(idJugador);
    }catch (std::domain_error ex){
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}

void View::retirarJugador() {
    try {
        long idJugador;
        cout << "Ingrese el id del jugador para retirar \n";
        cin >> idJugador;
        controller.verInfoJugador(idJugador);
        controller.retirarJugador(idJugador);
    }catch (std::domain_error ex){
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}

void View::recargarGonzos(){
    try {
        long idJugador;
        cout << "Ingrese el id del jugador para el que quiere jugar \n";
        cin >> idJugador;
        controller.verInfoJugador(idJugador);
        controller.recargarGonzos(idJugador);
    }catch (std::domain_error ex){
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}

