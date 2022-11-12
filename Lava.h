#pragma once
#include "Obstaculo.h"
class Lava :
    public Obstaculo
{
    Lava(float X, float Y, float l, float a, int id = 0);
    ~Lava();

};

