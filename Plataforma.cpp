#include "Plataforma.h"

Plataforma::Plataforma(Vector2f coordenada, Vector2f tamanho) :
	Obstaculo(coordenada,tamanho, 31)
{
	textura.loadFromFile("sprites/plataforma.png");
	body->setTexture(&textura);
}

Plataforma::~Plataforma()
{
}
