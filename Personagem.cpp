#include "Personagem.h"
Personagem::Personagem(int n, float x, float y) : Entidade(x,y) {
	num_vidas = n;
	velocidadeY = 0;
	velocidadeX = 0;
}


Personagem::~Personagem()
{
	num_vidas = 0;
}
