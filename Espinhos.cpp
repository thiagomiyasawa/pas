#include "Espinhos.h"

Espinhos::Espinhos(float X, float Y, float l, float a) :
	Obstaculo(X, Y, l, a, 32)
{
	body->setFillColor(Color::Cyan);
	dano = 1;
}

Espinhos::~Espinhos()
{
}

int Espinhos::getDano() {
	return dano;
}