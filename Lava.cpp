#include "Lava.h"

using namespace entidades;
using namespace obstaculos;

Lava::Lava(Vector2f coordenada, Vector2f tamanho) :
	Obstaculo(coordenada, tamanho, 33)
{
	textura.loadFromFile("sprites/lava.png");
	body->setTexture(&textura);
	dano = 1000;
	solido = false;
	danoso = true;
}


Lava::~Lava()
{
}

int Lava::getDano() {
	return dano;
}
void Lava::move() {
	velocidade.y -= 0.001f;
	gravidade();

}

void Lava::gravar() {
	ofstream gravador("save/lava.dat", ios::app);

	if (!gravador)
	{
		return;
	}
	gravador << endl<< posicao.x << ' '
			 << posicao.y << ' '
			 << tamanho.x << ' '
		     << tamanho.y ;
	gravador.close();

}

Lista<Lava>* Lava::recuperar() {
	ifstream recuperador("save/lava.dat", ios::in);
	Lista<Lava>* l = new Lista<Lava>;
	Vector2f p;
	Vector2f t;
	if (!recuperador) {
		return nullptr;
	}
	while (!recuperador.eof()) {
		recuperador >> p.x >> p.y >> t.x >> t.y;

		Lava* temp = new Lava(p, t);
		l->push(temp);
	}
	recuperador.close();
	return l;


}
