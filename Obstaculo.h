#pragma once
#include "Entidade.h"
class Obstaculo : public Entidade{
protected:

public:
	Obstaculo(float X, float Y, float l, float a, int id=31);
	~Obstaculo();
	virtual int getDano();
	virtual int getAtivo();
	virtual void reduzAtivo();
};

