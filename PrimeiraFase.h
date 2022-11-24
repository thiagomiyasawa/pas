#pragma once
#include "Fase.h"
class PrimeiraFase :
    public Fase
{
private:
public:
    PrimeiraFase(RenderWindow* w, Jogador* J1, float tempo, bool nova = true);
    PrimeiraFase(RenderWindow* w, Jogador* J1, Jogador* J2,float tempo, bool nova = true);
    ~PrimeiraFase();
    void criaMapa();
    void geraInimigoAleatorio();
    void geraMoa();
    void geraOctorok();
    void salvar(int pontos);
    static PrimeiraFase* recuperar(RenderWindow* w);
};

