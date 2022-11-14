#include "Plataforma.h"

Plataforma::Plataforma(float X, float Y, float l, float a) :
	Obstaculo(X, Y, l, a, 31)
{
	body->setFillColor(Color::Blue);
}

Plataforma::~Plataforma()
{
}
