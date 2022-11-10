#pragma once
#include "Entidade.h"
class Personagem : public Entidade {
protected:
	int num_vidas;
	float velocidadeX;
	float velocidadeY;
	bool NoChao;
public:
	Personagem(int n, float x = 0., float y = 0.,int id =0);
	~Personagem();
	void gravidade();

};
