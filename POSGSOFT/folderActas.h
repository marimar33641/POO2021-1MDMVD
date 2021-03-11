#ifndef FOLDERACTAS_H
#define FOLDERACTAS_H

#include <iostream>
#include <list>
#include "acta.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

class FolderActas{
    private:
        string facultad;
        list <Acta> listaActas;
    public:
        FolderActas(  );
        FolderActas( string, list <Acta> );
        void crearNuevaActa(  );
        void diligenciarCalifaciones(  );
        void calcularNota(  );
        void ingresarInformacionAdicional(  );
        void cerrarActa(  );
        void guardarInformacionActa(  );
        void mostrarInformacionActa(  );
        void listarActas(  );
        void consultarListaCriterios(  );
        void eliminarActas(  );
};  

#endif