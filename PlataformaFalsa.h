#pragma once
#include "Obstaculo.h"
class PlataformaFalsa :
    public Obstaculo
{
private:
    int ativo;
public:
    PlataformaFalsa(float X, float Y, float l, float a);
    ~PlataformaFalsa();
    int getAtivo();
    void reduzAtivo();
};

