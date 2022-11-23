#pragma once
#include "Obstaculo.h"
class Espinhos :
    public Obstaculo 
{
private:
    int dano;
public:
    Espinhos(Vector2f coordenada, Vector2f tamanho);
    ~Espinhos();
    int getDano();

    void gravar();
    static Espinhos* recuperar();
};

