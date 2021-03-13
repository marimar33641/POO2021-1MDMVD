#ifndef CRITERIOS_H
#define CRITERIOS_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Criterio{
    private:
        string nombreCriterio;
        float calificacion;
        float ponderacion;
        string observaciones;
        int jurado;
    public:
        Criterio();
        Criterio( string, float, float, string, int );
        void mostrarCriterio();
};

#endif