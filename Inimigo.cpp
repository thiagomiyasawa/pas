#include "Inimigo.h"
using namespace personagens;

Inimigo::Inimigo(int vida, float x,float y, int id,int valor) : Personagem(vida, x, y, id) {
	
	body->setPosition(Vector2f(x, y));
	noChao = false;
	dano = valor;
}

Inimigo::~Inimigo()
{
}

void personagens::Inimigo::move()
{
	body->move(Vector2f(velocidadeX, velocidadeY));
	x += velocidadeX;
	y += velocidadeY;
	if(!noChao) {
		gravidade();
	}
	id = 2;
	noChao = false;
}


int Inimigo::getDano() {
	return dano;
}

int Inimigo::getImune() {
	return imune;
}

void Inimigo::setImune() {
	imune = 100;
}

void Inimigo::removeVidas(int dano) {
	num_vidas -= dano;
	body->setFillColor(Color(232, 124, 171));
	if (num_vidas <= 0) {
		vivo = false;
		body->setFillColor(Color::Transparent);
	}

}