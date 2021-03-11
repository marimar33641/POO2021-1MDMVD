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
    public:
        Director(  );
        Director( string );
        void mostrarDirector(  );
};

#endif