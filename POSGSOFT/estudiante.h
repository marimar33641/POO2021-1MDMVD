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
        Acta actaEstudiantes;
        string id;
    public:
        Estudiante(  );
        Estudiante( string, string, string, string, Acta, string );
        void mostrarEstudiante(  );
};

#endif