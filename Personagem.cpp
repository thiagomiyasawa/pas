#include "Personagem.h"
Personagem::Personagem(int n, Vector2f t, Vector2f p, int id, int estado)
	: Entidade(p, t, id) {
	num_vidas = n;
	noChao = false;
	vivo = true;
	imune = 0;
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
		//body->setFillColor(Color::Transparent);
	}
}

bool Personagem::getVivo() {
	return vivo;
}

void Personagem::setDirecao(int valor) {
	direcao = valor;
}

int Personagem::getDirecao() {
	return direcao;
}