#ifndef ACTA_H
#define ACTA_H

#include <iostream>
#include <string>
#include <list>
#include "criterio.h"
#include "jurado.h"
#include "estudiante.h"
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
        int periodo;
        int tipoTrabajo;
        Jurado jurado1;
        Jurado jurado2;
        int notaFinal;
        int estado;
        list <Criterio> listaCriterios;
    public:
        Acta(  );
        Acta( string, string, Director , int, int, Jurado, Jurado, int, int, list<Criterio> );
        void mostrarActa( );
        void setActas( );
};


#endif