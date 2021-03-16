#ifndef FOLDERACTAS_H
#define FOLDERACTAS_H

#include <iostream>
#include <list>
#include "universidad.h"
#include "acta.h"
#include "estudiante.h"
#include "director.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

class FolderActas : public Universidad{
    private:
        string facultad;
        list <Estudiante> listaEstudiantes;
        list <Acta> listaActas;
    public:
        FolderActas(  );
        FolderActas(list <Director>, list <Jurado> ,string, list <Estudiante> );
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
        Estudiante crearEstudiante( );
        Director buscarDirector( int );
        Jurado buscarJurado( int );
        void mostrarDirectores( );
        
};  

#endif