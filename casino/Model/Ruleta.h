//
// Created by Maria on 15/05/2021.
//

#ifndef CASINO_RULETA_H
#define CASINO_RULETA_H
#include "Juego.h"
#include<cstdlib>
#include<ctime>

class Ruleta : public Juego {
protected:
    virtual float calcularResultado(float gonzosApostar) override;
public:
    virtual ~Ruleta();
    virtual float jugar(float gonzosApostar) override;
};

#endif //CASINO_RULETA_H
