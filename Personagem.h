#pragma once
#include "Entidade.h"
class Personagem : public Entidade {
protected:
	int num_vidas;
	float velocidadeX;
	float velocidadeY;
	bool noChao;
public:
	Personagem(int n, float x = 0., float y = 0., int id = 0);
	~Personagem();
	void gravidade();
	virtual void move() = 0;
	virtual void colidir(int ID) = 0;
};
