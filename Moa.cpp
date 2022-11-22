#include "Moa.h"
using namespace personagens;

Moa::Moa(int vidas, Vector2f p) :
	Inimigo(vidas, Vector2f(50., 50.), p, 22)
{
	textura.loadFromFile("sprites/moa1.png");
	body->setTexture(&textura);
	body->setFillColor(Color::Red);
	velocidade = Vector2f(0.088, 0.);
}

Moa::~Moa()
{
}

void Moa::move() {
	posicao.x += velocidade.x;
	posicao.y += velocidade.y;
	body->setPosition(posicao);
	velocidade.y -= 0.001f;
	gravidade();
}

void Moa::gravar() {
	ofstream gravador("save/moa.dat", ios::app);

	if (!gravador)
	{
		return;
	}
	gravador << numVidas << ' '
			 << posicao.x << ' '
			 << posicao.y << ' '
			 << velocidade.x << ' '
			 << velocidade.y << endl;
	gravador.close();
}


Moa* Moa::recuperar() {
	ifstream recuperador("save/moa.dat", ios::in);

	Moa* m;
	int vidas;
	Vector2f p;
	Vector2f v;

	if (!recuperador || recuperador.eof()) {
		return NULL;
	}

	recuperador >> vidas >> p.x >> p.y >> v.x >> v.y;

	m = new Moa(vidas, p);
	m->setVelocidade(v);

	recuperador.close();

	return m;
}