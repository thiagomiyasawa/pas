#include "Plataforma.h"

Plataforma::Plataforma(Vector2f coordenada, Vector2f tamanho) :
	Obstaculo(coordenada,tamanho, 31)
{
	textura.loadFromFile("sprites/plataforma.png");
	body->setTexture(&textura);
}

Plataforma::~Plataforma()
{
}

void Plataforma::gravar() {
    ofstream gravador("save/plataforma.dat", ios::app);

    if (!gravador)
    {
        return;
    }
    gravador << posicao.x << ' '
             << posicao.y << endl;
    gravador.close();
}

Plataforma* Plataforma::recuperar() {
	ifstream recuperador("save/plataforma.dat", ios::app);

	Plataforma* P;
	Vector2f p;
	Vector2f t;

	if (!recuperador || recuperador.eof()) {
		return NULL;
	}

	recuperador >> p.x >> p.y >> t.x >> t.y;

	P = new Plataforma(p, t);

	recuperador.close();

	return P;
}
