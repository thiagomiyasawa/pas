#include "Projetil.h"
Projetil:: Projetil():Entidade(Vector2f(0.,0.), Vector2f(20.,10.), 41) {
	ativo = false;
	velocidade = Vector2f(0.2, 0.);
}
Projetil::~Projetil() {

}
void Projetil::setAtivo(bool estado) {
	ativo = estado;
	if(ativo)
		body->setFillColor(Color(232, 194, 102));
	else {
		body->setFillColor(Color::Transparent);
		posicao.x = -100;
		posicao.y = -100;
	}
}
bool Projetil::getAtivo() {
	return ativo;
}
void Projetil::move() {
	if (ativo) {
		
		posicao.x += velocidade.x;
		posicao.y += velocidade.y;
		body->setPosition(posicao);
		velocidade.y += 0.001f;
	}
}