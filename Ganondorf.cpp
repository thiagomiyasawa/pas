#include "Ganondorf.h"
using namespace personagens;
Ganondorf::Ganondorf(int vidas, Vector2f p) :
	Inimigo(vidas,Vector2f(50.,100.), p, 23)
{
	textura.loadFromFile("sprites/ganondorfIdle.png");
	body->setTexture(&textura);
	corOriginal = body->getFillColor();
	irritado = 0;
	velocidade = Vector2f(0.088, 0.);
}

Ganondorf::~Ganondorf()
{
}

void Ganondorf::move() {
	irritado--;
	if (irritado < -1000) {
		irritado = 1000;
		dano = 2;
		body->setFillColor(Color(157, 40, 24));
	}
	if (irritado < 0) {
		body->setFillColor(corOriginal);
		dano = 1;
	}
	if (noChao) {
		if (posicao.y + tamanho.y < 350 && posicao.x < 370) {
			velocidade.x = 0.088;
		}
		else if (posicao.y + tamanho.y < 350 && posicao.x+tamanho.x >930 ) {
			velocidade.x = -0.088;
		}
		else if (posicao.x < 20) {
			velocidade.x = 0.088;
		}
		else if (posicao.x + tamanho.x >1270) {
			velocidade.x = -0.088;
		}

	}
	posicao.x += velocidade.x;
	posicao.y += velocidade.y;
	body->setPosition(posicao);
	if (!noChao) {
		gravidade();
	}
	noChao = false;
}