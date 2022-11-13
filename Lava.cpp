#include "Lava.h"

Lava::Lava(float X, float Y, float l, float a) :
	Obstaculo(X, Y, l, a, 33)
{
	body->setFillColor(Color::Red);
}


Lava::~Lava()
{
}
