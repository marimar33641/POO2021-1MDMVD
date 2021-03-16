#ifndef ACTA_H
#define ACTA_H

#include <iostream>
#include <string>
#include <list>
#include "criterio.h"
#include "jurado.h"
#include "director.h" 

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

class Acta{
    private:
        string titulo;
        string fecha;
        Director director;
        int tipoTrabajo;
        Jurado jurado1;
        Jurado jurado2;
        float notaFinal;
        int estado;
        list <Criterio> listaCriterios;
    public:
        Acta(  );
        Acta( string, string, Director , int, Jurado, Jurado, float, int, list<Criterio> );
        void mostrarActa( );
        void setTitulo( string );
        void setFecha( string );
        void setDirector( Director );
        void setTipoTrabajo( int );
        void setJuradoUno( Jurado );
        void setJuradoDos( Jurado );
        void setNotaFinal( float );
        void setEstado( int );
        
};


#endif