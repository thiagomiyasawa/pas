#pragma once
#include "Obstaculo.h"
class Lava :
    public Obstaculo
{
private:
public:
    Lava(Vector2f coordenada, Vector2f tamanho);
    ~Lava();

};

