#pragma once
#include "Entidade.h"
class Obstaculo : public Entidade{
protected:

public:
	Obstaculo(float X, float Y, float l, float a, int id = 0);
	~Obstaculo();
};

