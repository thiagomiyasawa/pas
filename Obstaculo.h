#pragma once
#include "Entidade.h"
class Obstaculo : public Entidade{
protected:
public:
	Obstaculo(Vector2f coordenada, Vector2f tamanho, int id=30);
	~Obstaculo();
	virtual int getDano();
	virtual int getAtivo();
	virtual void reduzAtivo();
};

