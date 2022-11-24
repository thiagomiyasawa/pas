#pragma once
#include "Fase.h"
#include "Ganondorf.h"
class SegundaFase :
    public Fase
{
private:
public:
    SegundaFase(RenderWindow* w, Jogador* j, bool nova = true);
    SegundaFase(RenderWindow* w, Jogador* J1, Jogador* J2,float tempo, bool nova = true);
    ~SegundaFase();
    void criaMapa();
    void geraInimigoAleatorio();
    void geraMoa();
    void geraGanon();
    void salvar(int pontos, float tempo);
    static SegundaFase* recuperar(RenderWindow* w);
};

