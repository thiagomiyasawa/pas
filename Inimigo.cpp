#include "Inimigo.h"
using namespace personagens;

Inimigo::Inimigo(int vida, float x,float y, int id) : Personagem(vida, x, y, id) {
	body->setFillColor(Color::Red);
	body->setPosition(Vector2f(x, y));
	noChao = false;
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
	}

}