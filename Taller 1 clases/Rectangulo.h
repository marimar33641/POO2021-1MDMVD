#ifndef RECTANGULO_H
#define RECTANGULO_H
class Rectangulo{
    private:
        float largo, ancho;
    public:
        Rectangulo(  );
        Rectangulo( float, float );
        void calcularPerimetroRectangulo(  );
        void calcularAreaRectangulo(  );
        float getLargo(  ); 
        float getAncho(  );
        void setLargo( float ); 
        void setAncho( float );

};

#endif
