#include "Inimigo.h"
using namespace personagens;

Inimigo::Inimigo() : Personagem(1,200.f,200.f) {
	body.setFillColor(Color::Red);
	body.setPosition(Vector2f(x,y));
}

Inimigo::~Inimigo()
{
}
