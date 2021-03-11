#ifndef ACTA_H
#define ACTA_H

#include <iostream>
#include <string>
#include <list>
#include "criterio.h"
#include "jurado.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

class Acta{
    private:
        string nombreEstudiante;
        string fecha;
        string nombreTrabajo;
        int periodo;
        int tipoTrabajo;
        int idEstudiante;
        Jurado jurado1;
        Jurado jurado2;
        int notaFinal;
        int estado;
        list <Criterio> listaCriterios;
    public:
        Acta(  );
        Acta( string, string, string, int, int, int, Jurado, Jurado, int, int, list<Criterio> );
        void mostrarActa(  );

};


#endif