#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H
#include "director.h"
#include "jurado.h"
#include "estudiante.h"
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
        list<string> codirectores;
        //Atributos folder
        string facultad;
        list <Director> listaDirector;
        list <Estudiante> listaEstudiantes;
        list <Jurado> listaJurados;
    public:
        Universidad();
        void mostrarJurados();
        void crearJurado();
        void mostrarFolder();
        void crearDirector();
        void mostrarTodosDirectores();
        void crearFolderActas();
        void mostrarEstudiantes();
        Estudiante getListaEstudiante( );
        Director getListaDirectores( );
        //Funciones folder
        void crearNuevaActa( );
        void diligenciarCalifaciones( );
        void calcularNota(  );
        void ingresarInformacionAdicional(  );
        void cerrarActa(  );
        void guardarInformacionActa(  );
        void mostrarInformacionActa(  );
        void listarActas(  );
        void consultarListaCriterios(  );
        void eliminarActas(  );
        void crearEstudiante( );
        Director buscarDirector( int );
        Jurado buscarJuradoUno( int );
        Jurado buscarJuradoDos( int );
        void mostrarDirectores( );
        string getFacultad();

        
};

#endif