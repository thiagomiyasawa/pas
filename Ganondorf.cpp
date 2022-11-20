#include "Ganondorf.h"
using namespace personagens;
Ganondorf::Ganondorf(int vidas, Vector2f p) :
	Inimigo(vidas,Vector2f(50.,100.), p, 33)
{
	textura.loadFromFile("sprites/ganondorfIdle.png");
	body->setTexture(&textura);
}

Ganondorf::~Ganondorf()
{
}
