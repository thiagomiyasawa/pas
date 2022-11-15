#include "Lava.h"

Lava::Lava(Vector2f coordenada, Vector2f tamanho) :
	Obstaculo(coordenada, tamanho, 33)
{
	body->setFillColor(Color::Red);
}


Lava::~Lava()
{
}
