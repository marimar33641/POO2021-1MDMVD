//
// Created by lufe0 on 7/05/2021.
//

#include "Mayor13.h"

float Mayor13::jugar(float gonzosApostar) {
    int opcion;
    float gonzosResultado;
    srand(time(NULL));
    do {
        cout << "1.Darse por vencido" << endl << "2.Jugar" << endl<<"Opcion: ";
        cin >> opcion;
    }while( opcion <=0 or opcion > 2 );
    if( opcion == 1 ){
        gonzosApostar /= 2;
        return gonzosApostar;
    }
    else{
        numeroJugador = 1+rand()%14;// numeros de 1 a 13
        numeroCasino = 1+rand()%14;// numeros de 1 a 13
        cout << "Tu numero aleatorio es: "<< numeroJugador <<endl;
        cout << "Numero aleatorio del casino es: "<< numeroCasino <<endl;
        gonzosResultado = calcularResultado( gonzosApostar );
    }
    return gonzosResultado;
}

float Mayor13::calcularResultado(float gonzosApostar) {
    if( numeroJugador <= numeroCasino ){
        cout<<"Perdio todo"<<endl;
        gonzosApostar = 0;
    }
    else{
        cout<<"Gano gonzoz X2"<<endl;
        gonzosApostar *= 2;
    }
    return gonzosApostar;
}

Mayor13::~Mayor13() {

}
