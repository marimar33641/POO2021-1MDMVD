#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

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
};

#endif