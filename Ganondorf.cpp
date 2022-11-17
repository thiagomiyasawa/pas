#include "Ganondorf.h"
using namespace personagens;
Ganondorf::Ganondorf(int vidas, float x, float y) :
	Inimigo(vidas, x, y, 33)
{
	//textura.loadFromFile("sprites/ganondorfIdle.png");
	//body->setTexture(&textura);
}

Ganondorf::~Ganondorf()
{
}
