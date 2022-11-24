#include "Lava.h"

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
