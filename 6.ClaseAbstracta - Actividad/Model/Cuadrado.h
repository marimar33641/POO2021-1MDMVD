#ifndef CUADRADO_H
// Guardas
#define CUADRADO_H

#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

#include "FiguraGeometrica.h"

//CLASE Cuadrado

class Cuadrado : public FiguraGeometrica{
private: 
    float longitud;
public:
    Cuadrado(); //NO OLVIDAR
    Cuadrado(float);
    void mostrarFigura() const;
    virtual void calcularArea();
    virtual void calcularPerimetro();
    virtual void mostrarFigura();
    float getLongitud();
    void setLongitud(float);
};

#endif 