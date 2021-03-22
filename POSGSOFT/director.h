#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*Se crea la clase Director con sus respectivos atributo, sus metodos y sus constructores*/

class Director{
    private:
        string nombreDirector;
        string identificacion;
        string email;
        string celular;
    public:
        Director(  );
        Director( string, string, string, string );
        void mostrarDirector(  );
        string getNombreDirector();
        string getIdentificacion();
};

#endif