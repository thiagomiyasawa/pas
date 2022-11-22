#include "Inimigo.h"
using namespace personagens;

Inimigo::Inimigo(int vida,Vector2f t, Vector2f p, int id, int valor) : Personagem(vida, t, p, id) {
	
	body->setPosition(p);
	noChao = false;
	dano = valor;
}

Inimigo::~Inimigo()
{
}

void personagens::Inimigo::move()
{
	body->move(velocidade);
	posicao.x += velocidade.x;
	posicao.y += velocidade.y;
	if(!noChao) {
		gravidade();
	}
	id = 2;
	noChao = false;
}


int Inimigo::getDano() {
	return dano;
}

int Inimigo::getImune() {
	return imune;
}

void Inimigo::setImune() {
	imune = 100;
}

void Inimigo::removeVidas(int dano) {
	numVidas -= dano;
	body->setFillColor(Color(232, 124, 171));
	if (numVidas <= 0) {
		vivo = false;
		body->setFillColor(Color::Transparent);
	}

}