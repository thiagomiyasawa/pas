#pragma once
#include "Ente.h"
class Entidade : public Ente {
protected:
	float x;
	float y;
	int id;
	float velocidadeX;
	float velocidadeY;
public:
	Entidade(float X, float Y, float l, float a, int ID);
	~Entidade();
	virtual void move();
	float getX() const;
	float getY() const;
	int getId() const;
	float getVelocidadeX();
	float getVelocidadeY();

	void setX(int valor);
	void setY(int valor);
	void setVelocidadeX(float velocidade);
	void setVelocidadeY(float velocidade);

	void gravidade();
};

