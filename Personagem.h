#pragma once
#include "Entidade.h"
class Personagem : public Entidade {
protected:
	int num_vidas;
public:
	Personagem(int n, float x = 0., float y = 0.);
	Personagem();
	~Personagem();
};
