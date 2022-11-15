#pragma once
#include "Obstaculo.h"
class PlataformaFalsa :
    public Obstaculo
{
private:
    int ativo;
public:
    PlataformaFalsa(Vector2f coordenada, Vector2f tamanho);
    ~PlataformaFalsa();
    int getAtivo();
    void reduzAtivo();
};

