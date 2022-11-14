#include "PlataformaFalsa.h"

PlataformaFalsa::PlataformaFalsa(float X, float Y, float l, float a) :
	Obstaculo(X, Y, l, a, 34)
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
}