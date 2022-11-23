#pragma once
#include "Fase.h"
#include "Ganondorf.h"
class SegundaFase :
    public Fase
{
public:
    SegundaFase(RenderWindow* w, Jogador* j, bool nova = true);
    SegundaFase(RenderWindow* w, Jogador* J1, Jogador* J2, bool nova = true);
    ~SegundaFase();
    void criaMapa();
    void geraInimigoAleatorio();
    void geraMoa();
    void geraGanon();
    void salvar(int pontos);
    static SegundaFase* recuperar(RenderWindow* w);
};

