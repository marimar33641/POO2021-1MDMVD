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

/*Se crea la clase Universidad con sus respectivos atributo, sus metodos y su constructor por defecto*/

class Universidad{
    private:
        string nombre;
        list<string> codirectores;
        list <Director> listaDirector;
        list <Estudiante> listaEstudiantes;
        list <Jurado> listaJurados;
    public:
        Universidad();
        void mostrarJurados();
        void crearJurado();
        void crearDirector();
        void mostrarTodosDirectores();
        void mostrarEstudiantes();
        Estudiante getListaEstudiante( );
        Director getListaDirectores( );
        //Funciones folder
        void crearNuevaActa( );
        void mostrarInformacionActa();
        void listarActas();
        void eliminarActas();
        void crearEstudiante( );
        Director buscarDirector( int );
        Jurado buscarJuradoUno( int );
        Jurado buscarJuradoDos( int );
        void mostrarDirectores( );
        void mostrarActa();
        Estudiante buscarEstudiante(int);
        void modificarActaUniversidad();
        void listarActasPorEstado();
        void borrarActa();
        void listarActasPorTipoTrabajo();
        void listarJuradoPorLugarTrabajo();
        void listarActasPorDirector();
        void listarActasPorJurado();
        void listarActasPorNota();
        void menuListarActasPorNota();
        void verActasPorNota( int );
        void funcionalidadSorpresa( );
        
        
};

#endif