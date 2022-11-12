#pragma once
#include "Ente.h"
class Entidade : public Ente {
protected:
	float x;
	float y;
	int id;
public:
	Entidade(float X, float Y, float l, float a, int ID);
	~Entidade();
	float getX() const;
	float getY() const;
	int getId() const;
	virtual float getVelocidadeY();
};

