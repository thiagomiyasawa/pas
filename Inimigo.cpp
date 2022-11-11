#include "Inimigo.h"
using namespace personagens;

Inimigo::Inimigo(int vida, float x,float y, int id) : Personagem(vida, x, y, id) {
	body.setFillColor(Color::Red);
	body.setPosition(Vector2f(x, y));
}

Inimigo::~Inimigo()
{
}

void personagens::Inimigo::move()
{
	velocidadeX *= 0.99f;
	body.move(Vector2f(velocidadeX, velocidadeY));
	x += velocidadeX;
	y += velocidadeY;
	gravidade();
}

void Inimigo::colidir(int ID) {
	if (ID == 11) {
		velocidadeX = 1.0f;
		velocidadeY = -0.5f;

	}
}
