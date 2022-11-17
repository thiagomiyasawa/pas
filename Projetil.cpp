#include "Projetil.h"
Projetil:: Projetil():Entidade(0,0,20,10,41) {
	ativo = false;
	velocidadeX = 0.2;
	velocidadeY = 0;
}
Projetil::~Projetil() {

}
void Projetil::setAtivo(bool estado) {
	ativo = estado;
	if(ativo)
		body->setFillColor(Color(232, 194, 102));
	else {
		body->setFillColor(Color::Transparent);
		x = -100;
		y = -100;
	}
}
bool Projetil::getAtivo() {
	return ativo;
}
void Projetil::move() {
	if (ativo) {
		x += velocidadeX;
		y += velocidadeY;
		body->setPosition(x, y);
		velocidadeY += 0.001f;
	}
}