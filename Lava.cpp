#include "Lava.h"

Lava::Lava(Vector2f coordenada, Vector2f tamanho) :
	Obstaculo(coordenada, tamanho, 33)
{
	textura.loadFromFile("sprites/lava.png");
	body->setTexture(&textura);
}


Lava::~Lava()
{
}
