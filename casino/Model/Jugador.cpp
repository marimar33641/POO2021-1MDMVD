//
// Created by lufe0 on 7/05/2021.
//

#include "Jugador.h"

Jugador::Jugador()
          :cantJuegos(0)
{
}
// Hace llamada delegada al constructor por defecto
Jugador::Jugador(long id, string nombre, float cantGonzos): Jugador() {
    this->id = id;
    this->nombre = nombre;
    this->cantGonzos = cantGonzos;
}


/* Destructor*/
Jugador::~Jugador()
{
}

void Jugador::mostrarInfo() {

    // Muestra el nombre , la cantidad de gonzos y la cantidad de juegos jugados
    cout<<"Nombre: "<< nombre << endl;
    cout<<"Cantidad Gonzos: " << cantGonzos<<endl;
    cout<<"Cantidad juegos jugados: "<< cantJuegos << endl<<endl;

}

void Jugador::aumentarJuegos() {
    cantJuegos+= 1;
}

void Jugador::actualizarGonzos(float resultadoJuego) {
    cantGonzos = cantGonzos + resultadoJuego;
}

const string &Jugador::getNombre() const {
    return nombre;
}

float Jugador::getCantGonzos() const {
    return cantGonzos;
}

long Jugador::getId() const {
    return id;
}






