#pragma once
#include "Obstaculo.h"
class Plataforma :
    public Obstaculo
{
private:
public:
    Plataforma(Vector2f coordenada, Vector2f tamanho);
    ~Plataforma();

    void gravar();
    static Lista<Plataforma>* recuperar();
};

