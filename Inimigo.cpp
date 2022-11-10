#include "Inimigo.h"
using namespace personagens;

Inimigo::Inimigo(int vida, float x,float y, int id) : Personagem(vida,x,y,id) {
	body.setFillColor(Color::Red);
	body.setPosition(Vector2f(200.f, 200.f));
}

Inimigo::~Inimigo()
{
}
