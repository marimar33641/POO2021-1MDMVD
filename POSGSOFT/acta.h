#ifndef ACTA_H
#define ACTA_H

#include <iostream>
#include <list>
#include "criterio.h"
#include "jurado.h"
#include "director.h" 

using std::getline;
using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using namespace std;

/*Se crea la clase Acta con sus respectivos atributo, sus metodos y sus constructores*/

class Acta{
    private:
        string titulo;
        string fecha;
        Director director;
        int tipoTrabajo;
        Jurado jurado1;
        Jurado jurado2;
        float notaFinal;
        int estado;
        list <Criterio> listaCriterios;
    public:
        Acta(  );
        Acta( string, string, Director , int, Jurado, Jurado, float, int, list<Criterio> );
        void mostrarActa( );
        void setTituloActa( string );
        void setFechaActa( string  );
        void setDirector( Director );
        void setTipoTrabajo( int );
        void setJuradoUno( Jurado );
        void setJuradoDos( Jurado );
        void setNotaFinal( float );
        void setEstado( int );
        void setListaCriterios( list <Criterio> );
        string getFecha();
        string getTitulo();
        int getModalidad();
        string getNombreJuradoDosActa();
        string getNombreJuradoUnoActa();
        string getNombreDirectorActa();
        list <Criterio> getListaCriterios();
        float getNotaFinal();
        void menuModificarActaGeneral();
        void modificarInformacionActaGeneral();
        void menuModificarInformacionCriterios();
        float modificarInformacionCriterios();
        float calcularNotaFinal();
        int getEstado( );
        string getJuradoActaUno();
        string getJuradoActaDos();
        string getDirectorActa();
        int getExisteCorreciones();
};


#endif