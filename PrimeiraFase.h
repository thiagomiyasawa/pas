#pragma once
#include "Fase.h"
class PrimeiraFase :
    public Fase
{
private:
public:
    PrimeiraFase(RenderWindow* w, Jogador* j);
    PrimeiraFase(RenderWindow* w, Jogador* J1, Jogador* J2);
    ~PrimeiraFase();
    void criaMapa();
    void geraInimigoAleatorio();
    void geraMoa();
    void geraOctorok();
};

