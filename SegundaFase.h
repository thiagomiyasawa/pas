#pragma once
#include "Fase.h"
#include "Ganondorf.h"
class SegundaFase :
    public Fase
{
private:
    float tempoInicial;
public:
    SegundaFase(RenderWindow* w, Jogador* j);
    SegundaFase(RenderWindow* w, Jogador* J1, Jogador* J2, float tempo);
    ~SegundaFase();
    void criaMapa();
    void geraInimigoAleatorio();
    void geraMoa();
    void geraGanon();
};

