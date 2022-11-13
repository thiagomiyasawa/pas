#include "Plataforma.h"

Plataforma::Plataforma(float X, float Y, float l, float a, int id) :
	Obstaculo(X, Y, l, a, id)
{
	body->setFillColor(Color::Blue);
}

Plataforma::~Plataforma()
{
}
