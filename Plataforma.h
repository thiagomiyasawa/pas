#pragma once
#include "Obstaculo.h"
class Plataforma :
    public Obstaculo
{
private:
public:
    Plataforma(float X, float Y, float l, float a);
    ~Plataforma();
};

