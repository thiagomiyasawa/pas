#include "PlataformaFalsa.h"

PlataformaFalsa::PlataformaFalsa(float X, float Y, float l, float a, int id) :
	Obstaculo(X, Y, l, a, id)
{
	body->setFillColor(Color::Green);
}

PlataformaFalsa::~PlataformaFalsa()
{
}
