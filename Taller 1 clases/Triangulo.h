#ifndef TRIANGULO_H
#define RECTANGULO_H

class Triangulo{
    private:
        float base, altura;
    public:
        Triangulo();
        Triangulo( float, float );
        void calcularPerimetroTriangulo(  );
        void calcularAreaTriangulo(  );
        float getAlturaTriangulo(  ); 
        float getBaseTriangulo(  );
        void setAlturaTriangulo( float ); 
        void setBaseTriangulo( float );
};

#endif