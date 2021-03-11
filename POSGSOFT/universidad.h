#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H
#include "director.h"
#include "jurado.h"
#include "acta.h"

#include <iostream>
#include <string>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

class Universidad{
    private:
        string nombre;
        list <Jurado> listaJurados;
        list <Director> listDirector;
        list <Acta> listaActasXFacultad;
        list<string> codirectores;
    public:
        Universidad();
        void mostrarJurados();
        void crearJurado();
        void mostrarFolder();
};

#endif