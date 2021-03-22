#ifndef CRITERIOS_H
#define CRITERIOS_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*Se crea la clase Criterio con sus respectivos atributo, sus metodos y sus constructores*/

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
        float getCalificacion();
        string getNombreCriterio();
        float getPonderacion();
        string getObservaciones();
        void mostrarNombreCriterio();
        void setCalificacionCriterio( float );
        void setObservacionCriterio( string );
};

#endif