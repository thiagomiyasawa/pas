#include "Plataforma.h"

Plataforma::Plataforma(Vector2f coordenada, Vector2f tamanho) :
	Obstaculo(coordenada,tamanho, 31)
{
	body->setFillColor(Color::Blue);
}

Plataforma::~Plataforma()
{
}
