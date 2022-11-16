#include "PlataformaFalsa.h"

PlataformaFalsa::PlataformaFalsa(Vector2f coordenada, Vector2f tamanho) :
	Obstaculo(coordenada, tamanho, 34)
{
	textura.loadFromFile("sprites/plataformaFalsa.png");
	body->setTexture(&textura);
	ativo = 100;
}

PlataformaFalsa::~PlataformaFalsa()
{
}

int PlataformaFalsa::getAtivo() {
	return ativo;
}
void PlataformaFalsa::reduzAtivo() {
	ativo--;
	if (!ativo) {
		body->setFillColor(Color::Transparent);
	}
}