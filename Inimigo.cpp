#include "Inimigo.h"
using namespace personagens;

Inimigo::Inimigo(int vida, float x,float y) : Personagem(vida,x,y) {
	body.setFillColor(Color::Red);
	body.setPosition(Vector2f(x, y));
}

Inimigo::~Inimigo()
{
}

void personagens::Inimigo::move() 
{
	body.move(Vector2f(01.f, 0.1f));
}

