#include "Moa.h"
using namespace personagens;

Moa::Moa(int vidas, Vector2f p) :
	Inimigo(vidas, Vector2f(50., 50.), p, 22)
{
	textura.loadFromFile("sprites/moa1.png");
	body->setTexture(&textura);
	body->setFillColor(Color::Red);
	velocidade = Vector2f(0.088, 0.);
}

Moa::~Moa()
{
}

void Moa::move() {
	posicao.x += velocidade.x;
	posicao.y += velocidade.y;
	body->setPosition(posicao);
	velocidade.y -= 0.001f;
	gravidade();
}