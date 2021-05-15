//
// Created by lufe0 on 7/05/2021.
//

#include "Casino.h"

// Constructor que inicializa las ganancias y perdidas en cero
Casino::Casino() {
    cout <<"Inicialice casino";
    jugadoresMap.clear(); // Se limpian los jugadores del casino
}

void Casino::agregarJuego(Juego * juego) {
    juegosDisponibles.push_back(juego);
}

void Casino::agregarJugador(Jugador *pJugador) {
    // Se agrega el jugador al mapa de jugadores del casino
   //jugadoresMap.insert(pJugador->getId(),pJugador);
   jugadoresMap[pJugador->getId()] = pJugador;
}

bool Casino::verExisteJugador(long id) {

    // Si el jugador se encuentra en el mapa retorna true, de lo contrario retorna false
    map<long, Jugador*>::iterator it;
    it = jugadoresMap.find(id);
    if( it == jugadoresMap.end() ){
        return false;
    }
    else{
        return true;
    }
}

Jugador *Casino::consultarJugador(long id) {
    return jugadoresMap[id]; // Retora el apuntador a jugador.
}

double Casino::convertirPesosAGonzos(double dinero) {

    // Cada 10 mil pesos equivalen a 100 Gonzos
    return (dinero * 100)/10000;
}

vector<Juego *> &Casino::consultarJuegos() {
    return juegosDisponibles;
}

void Casino::retirarJugador(long id) {
    // Investigue como remover el jugador del mapa
    jugadoresMap.erase(id);
}


double Casino::convertirGonzosPesos(float gonzos) {
    return (gonzos * 10000)/100;
}

Casino::~Casino() {

}