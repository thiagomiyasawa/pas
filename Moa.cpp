#include "Moa.h"

personagens::Moa::Moa(int vidas, float x, float y) :
	Inimigo(vidas, x, y, 21 )
{
	body->setFillColor(Color::Red);
}

 personagens::Moa::~Moa()
{
}
