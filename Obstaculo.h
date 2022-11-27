#pragma once
#include "Entidade.h"
class Obstaculo : public Entidade{
protected:
	bool solido;
	bool danoso;
public:
	Obstaculo(Vector2f coordenada, Vector2f tamanho, int id=30);
	~Obstaculo();
	virtual int getDano();
	virtual int getAtivo();
	virtual void reduzAtivo();
	bool getSolido();
	bool getDanoso();
	virtual void move()=0;
};

