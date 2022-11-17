#include "Moa.h"
using namespace personagens;

Moa::Moa(int vidas, float x, float y) :
	Inimigo(vidas, x, y, 21 )
{
	body->setFillColor(Color::Red);
	velocidadeX = 0.08f;
	velocidadeY = 0.f;
}

Moa::~Moa()
{
}

void Moa::move() {
	x += velocidadeX;
	y += velocidadeY;
	body->setPosition(x, y);
	velocidadeY -= 0.001f;
	gravidade();
}