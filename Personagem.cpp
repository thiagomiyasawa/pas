#include "Personagem.h"
Personagem::Personagem(int n, float x, float y, int id) 
    : Entidade(x, y, 100.f, 100.f, id) {
	num_vidas = n;
	
    velocidadeX = 0;
	velocidadeY = 0;
    
    NoChao = true;
}

Personagem::~Personagem() {
}

void Personagem::gravidade() {
    if (y >= 280) {
        NoChao = true;
        velocidadeY = 0;
    }

    if (NoChao) {
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            velocidadeY = -0.5;
            NoChao = false;
        }
    }
    
    else {
        velocidadeY += 0.001f;
    }
}
