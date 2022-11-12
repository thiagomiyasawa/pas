#pragma once
#include "Obstaculo.h"
class PlataformaFalsa :
    public Obstaculo
{
private:
public:
    PlataformaFalsa(float X, float Y, float l, float a, int id = 0);
    ~PlataformaFalsa();
};

