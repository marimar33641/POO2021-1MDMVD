#ifndef CIRCULO_H
#define CIRCULO_H

class Circulo{
    private:
        float radio;
    public:
        Circulo(  );
        Circulo( float );
        void calcularAreaCirculo(  );
        void calcularPerimetroCirculo(  );
        float getCirculo(  );
        void setRadio( float );
};

#endif
