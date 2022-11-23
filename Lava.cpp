#include "Lava.h"

Lava::Lava(Vector2f coordenada, Vector2f tamanho) :
	Obstaculo(coordenada, tamanho, 33)
{
	textura.loadFromFile("sprites/lava.png");
	body->setTexture(&textura);
}


Lava::~Lava()
{
}

void Lava::gravar() {
	ofstream gravador("save/lava.dat", ios::app);

	if (!gravador)
	{
		return;
	}
	gravador << posicao.x << ' '
			 << posicao.y << ' '
			 << tamanho.x << ' '
		     << tamanho.y << endl;
	gravador.close();

}

Lava* Lava::recuperar() {
	ifstream recuperador("save/lava.dat", ios::app);

	Lava* l;
	Vector2f p;
	Vector2f t;

	if (!recuperador || recuperador.eof()) {
			return nullptr;
	}

	recuperador >> p.x >> p.y >> t.x >> t.y;

	l = new Lava(p, t);

	recuperador.close();

	return l;
}
