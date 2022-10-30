#include "Inimigo.h"
using namespace personagens;

Inimigo::Inimigo() {
	body.setFillColor(Color::Red);
	body.setPosition(Vector2f(200.f, 200.f));
}

Inimigo::~Inimigo()
{
}
