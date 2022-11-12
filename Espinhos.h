#pragma once
#include "Obstaculo.h"
class Espinhos :
    public Obstaculo 
{
private:
public:
    Espinhos(float X, float Y, float l, float a, int id = 0);
    ~Espinhos();
};

