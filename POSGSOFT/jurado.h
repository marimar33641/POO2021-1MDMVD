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
    public:
        Jurado();
        Jurado( string, int );
        void mostrarJurado();
        void calificarCriterios(  );

};

#endif