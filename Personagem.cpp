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

float Personagem::getVelocidadeY(){
	return velocidadeY;
}
