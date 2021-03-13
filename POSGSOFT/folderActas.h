#ifndef FOLDERACTAS_H
#define FOLDERACTAS_H

#include <iostream>
#include <list>
#include "acta.h"
#include "estudiante.h"
#include "director.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

class FolderActas{
    private:
        string facultad;
        list <Estudiante> listaEstudiantes;
    public:
        FolderActas(  );
        FolderActas(string, list <Estudiante> );
        void crearNuevaActa( list<Director>, list<Jurado> );
        void diligenciarCalifaciones( );
        void calcularNota(  );
        void ingresarInformacionAdicional(  );
        void cerrarActa(  );
        void guardarInformacionActa(  );
        void mostrarInformacionActa(  );
        void listarActas(  );
        void consultarListaCriterios(  );
        void eliminarActas(  );
        Estudiante crearEstudiante( );
        Director buscarDirector();
        
};  

#endif