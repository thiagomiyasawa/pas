#pragma once
#include "Obstaculo.h"
class Espinhos :
    public Obstaculo 
{
private:
    int dano;
public:
    Espinhos(float X, float Y, float l, float a);
    ~Espinhos();
    int getDano();
};

