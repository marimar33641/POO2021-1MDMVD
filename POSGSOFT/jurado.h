#ifndef JURADO_H
#define JURADO_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;


class Jurado{
    private:
        string nombreJurado;
        int estado;
        string identificacion;
        string email;
        string celular;

    public:
        Jurado( );
        Jurado( string, int, string, string, string );
        void mostrarJurado( );
        void calificarCriterios(  );
        string getNombreJurado();
};

#endif