#include "PlataformaFalsa.h"

PlataformaFalsa::PlataformaFalsa(Vector2f coordenada, Vector2f tamanho) :
	Obstaculo(coordenada, tamanho, 34)
{
	body->setFillColor(Color::Green);
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