#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>
#include <fstream>
#include "acta.h"
#include "criterio.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using namespace std;
class Estudiante{
    private:
        string nombre;
        string identificacion;
        string email;
        string celular;
        Acta actaEstudiante;
        string id;
        list<Criterio> listaCriterios;
    public:
        Estudiante(  );
        Estudiante( string, string, string, string, Acta, string );
        void mostrarEstudiante(  );
        void setActa( Acta );
        void ingresarCriterios(  );
        void recibirDatos( string , string, Director, int, Jurado, Jurado, float, int );
        void crearTxt( string, string, float );
};

#endif