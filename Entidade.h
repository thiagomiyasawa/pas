#pragma once
#include "Ente.h"
class Entidade : public Ente {
protected:
	float x;
	float y;
public:
	Entidade(float X, float Y);
	Entidade();
	~Entidade();
};

