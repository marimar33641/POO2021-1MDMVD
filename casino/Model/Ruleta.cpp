//
// Created by Maria on 15/05/2021.
//

#include "Ruleta.h"

float Ruleta::jugar(float gonzosApostar) {
    int numeroUsuario;
    do {
        cout << "Digite un numero del 1-50: "; cin>> numeroUsuario;
    } while ( numeroUsuario <= 0 || numeroUsuario > 50 );
    srand(time(NULL));
    numeroCasino = 1+rand()%51;// numeros de 1 a 50
    cout<<"RULETA GIRANDO OJO PUES"<<endl;
    cout << "Tu numero aleatorio es: "<< numeroJugador <<"\n";
    cout << "Numero ruleta: "<< numeroCasino <<"\n";
    float gonzosResulado = calcularResultado(gonzosApostar);
    return gonzosResulado;
}

float Ruleta::calcularResultado(float gonzosApostar) {
    if( numeroJugador == numeroCasino ){
        cout<<"Gano X25 "<<endl;
        gonzosApostar *= 25;
    }
    else{
        cout<<"Perdio todo"<<endl;
        gonzosApostar = 0;
    }
    return gonzosApostar;
}

Ruleta::~Ruleta() {

}
