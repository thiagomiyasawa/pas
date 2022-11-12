#include "Personagem.h"
Personagem::Personagem(int n, float x, float y, int id) 
    : Entidade(x, y, 100.f, 100.f, id) {
	num_vidas = n;
	
    velocidadeX = 0;
	velocidadeY = 0;
	noChao = false;
}

Personagem::~Personagem() {
}

void Personagem::gravidade() {
        velocidadeY += 0.001f;
}
float Personagem::getVelocidadeX() {
	return velocidadeX;
}

float Personagem::getVelocidadeY(){
	return velocidadeY;
}

bool Personagem::getNoChao() {
	return noChao;
}

void Personagem::setVelocidadeX(float velocidade) {
	velocidadeX = velocidade;
}

void Personagem::setVelocidadeY(float velocidade) {
	velocidadeY = velocidade;
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

void Personagem::removevidas(int dano) {
	num_vidas -= dano;
}