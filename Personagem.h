#pragma once
#include "Entidade.h"
class Personagem : public Entidade {
protected:
	int num_vidas;
	float velocidadeX;
	float velocidadeY;
public:
	Personagem(int n = 0, float x = 0., float y = 0.);
	Personagem();
	~Personagem();
};
