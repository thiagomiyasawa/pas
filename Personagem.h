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

	float getVelocidadeX();
	float getVelocidadeY();
	bool getNoChao();

	void setVelocidadeX(float velocidade);
	void setVelocidadeY(float velocidade);
	void setNoChao(bool estado);
	void addVidas(int valor);
	void removevidas(int dano);


};
