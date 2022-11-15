#include "Espinhos.h"

Espinhos::Espinhos(Vector2f coordenada, Vector2f tamanho) :
	Obstaculo(coordenada, tamanho, 32)
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