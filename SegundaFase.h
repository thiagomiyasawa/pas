#pragma once
#include "Fase.h"
class SegundaFase :
    public Fase
{
public:
    SegundaFase(RenderWindow* w, Jogador* j);
    SegundaFase(RenderWindow* w, Jogador* J1, Jogador* J2);
    ~SegundaFase();
    void criaMapa();
    void geraInimigoAleatorio();
    void geraMoa();
};

