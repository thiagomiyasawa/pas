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

void Inimigo::colidir(int ID) {

	if (ID == 21) {
		velocidadeY = 0;
		noChao = true;
	}
}
