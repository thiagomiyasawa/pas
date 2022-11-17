#include "Octorok.h"
using namespace personagens;
Octorok::Octorok(int vidas, float x, float y) :
	Inimigo(vidas, x, y, 22)
{
	body->setFillColor(Color::Magenta);
	pedra = new Projetil();
	velocidadeX = 0.08f;
	velocidadeY = 0.f;
}

Octorok::~Octorok()
{
	delete pedra;
}

void Octorok::move() {
	x += velocidadeX;
	y += velocidadeY;
	body->setPosition(x, y);
	pedra->setAtivo(true);
	velocidadeY -= 0.001f;
	gravidade();
}