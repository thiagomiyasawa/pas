#pragma once
#include "Entidade.h"
class Personagem : public Entidade {
protected:
	int num_vidas;
	bool noChao;
	bool vivo;
	int direcao;
	int imune;
public:
	Personagem(int n, float x = 0., float y = 0., int id = 0, int estado = -1);
	~Personagem();

	void gravidade();
	virtual void move() = 0;

	
	bool getNoChao();
	virtual void setNoChao(bool estado);

	void addVidas(int valor);
	virtual void removeVidas(int dano);
	virtual void setImune() = 0;
	virtual int getImune() = 0;


};
