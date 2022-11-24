#pragma once
#include "Ente.h"
#include "Lista.h"
#include <fstream>
using namespace std;
class Entidade : public Ente {
protected:
	Vector2f posicao;
	Vector2f velocidade;
	
	Texture textura;
	int id;
public:
	Entidade(Vector2f p, Vector2f t, int ID = 0);
	~Entidade();
	
	virtual void move();
	float getX() const;
	float getY() const;
	int getId() const;
	float getVelocidadeX();
	float getVelocidadeY();

	void setX(int valor);
	void setY(int valor);
	void setPosicao(Vector2f p);
	void setVelocidadeX(float v);
	void setVelocidadeY(float v);
	void setVelocidade(Vector2f v);

	void gravidade();

	virtual bool getVivo();

	virtual void gravar() = 0;
};

