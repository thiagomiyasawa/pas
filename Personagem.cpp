#include "Personagem.h"
Personagem::Personagem(int n, float x, float y, int id, int estado)
    : Entidade(x, y, 40.f, 80.f, id) {
	num_vidas = n;
	
    velocidadeX = 0;
	velocidadeY = 0;
	noChao = false;
	vivo = true;
	direcao = estado;

}

Personagem::~Personagem() {
}

bool Personagem::getNoChao() {
	return noChao;
}

void Personagem::setNoChao(bool estado) {
	noChao = estado;
}

void Personagem::addVidas(int valor) {
	num_vidas += valor;
	if (num_vidas > 5) {
		num_vidas = 5;
	}
}

void Personagem::removeVidas(int dano) {
	num_vidas -= dano;
	if (num_vidas <= 0) {
		vivo = false;
	}
}

bool Personagem::getVivo() {
	return vivo;
}