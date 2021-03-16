#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include "acta.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Estudiante{
    private:
        string nombre;
        string identificacion;
        string email;
        string celular;
        Acta actaEstudiante;
        string id;
    public:
        Estudiante(  );
        Estudiante( string, string, string, string, Acta, string );
        void mostrarEstudiante(  );
        void setActa( Acta );
};

#endif