#include "Personagem.h"
Personagem::Personagem(int n, float x, float y) : Entidade(x,y) {
	num_vidas = n;
}

Personagem::Personagem()
{
}

Personagem::~Personagem()
{
}
