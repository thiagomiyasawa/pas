#include "Octorok.h"
using namespace personagens;
Octorok::Octorok(int vidas, float x, float y) :
	Inimigo(vidas, x, y, 22)
{
	textura.loadFromFile("sprites/octorok.png");
	body->setTexture(&textura);

	pedra = new Projetil();
	velocidadeX = 0.08f;
	velocidadeY = 0.f;
	direcao = +1;
}

Octorok::~Octorok()
{
	delete pedra;
}

void Octorok::move() {
	x += velocidadeX;
	y += velocidadeY;
	body->setPosition(x, y);
	if (!pedra->getAtivo() && recarga<=0 ) {
		atira();
		recarga = 1000;
	}
	recarga--;
	velocidadeY -= 0.001f;
	gravidade();
}
void Octorok::atira() {
	if (direcao > 0){		
		pedra->setX(x + largura + 2);
		pedra->setY(y + 20);
		pedra->setVelocidadeX(1.f);
	}
	else {
		pedra->setX(x - (2 + pedra->getLargura()));
		pedra->setY(y + 20);
		pedra->setVelocidadeX(-1.f);
	}
	pedra->setVelocidadeY(0);
	pedra->setAtivo(true);
}

Projetil* Octorok::getProjetil() {
	return pedra;
}