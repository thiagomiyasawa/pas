#include "Octorok.h"
using namespace personagens;
Octorok::Octorok(int vidas, Vector2f p) :
	Inimigo(vidas, Vector2f(50.,50.), p, 22)
{
	textura.loadFromFile("sprites/octorok.png");
	body->setTexture(&textura);

	pedra = new Projetil();

	velocidade = Vector2f(0.088, 0.);

	direcao = +1;
}

Octorok::~Octorok()
{
	delete pedra;
}

void Octorok::move() {
	posicao.x += velocidade.x;
	posicao.y += velocidade.y;
	body->setPosition(posicao);
	if (!pedra->getAtivo() && recarga<=0 ) {
		atira();
		recarga = 1000;
	}
	recarga--;
	velocidade.y -= 0.001f;
	gravidade();
}
void Octorok::atira() {
	if (direcao > 0){		
		pedra->setX(posicao.x + tamanho.x+ 2);
		pedra->setY(posicao.y + 20);
		pedra->setVelocidadeX(1.f);
	}
	else {
		pedra->setX(posicao.x - (2 + pedra->getLargura()));
		pedra->setY(posicao.y + 20);
		pedra->setVelocidadeX(-1.f);
	}
	pedra->setVelocidadeY(0);
	pedra->setAtivo(true);
}

Projetil* Octorok::getProjetil() {
	return pedra;
}