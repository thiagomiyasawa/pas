#include "Espinhos.h"

Espinhos::Espinhos(Vector2f coordenada, Vector2f tamanho) :
	Obstaculo(coordenada, tamanho, 32)
{
	textura.loadFromFile("sprites/espinhos.png");
	body->setTexture(&textura);
	dano = 1;
}

Espinhos::~Espinhos()
{
}

int Espinhos::getDano() {
	return dano;
}

void Espinhos::gravar() {
    ofstream gravador("save/espinhos.dat", ios::app);

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

Espinhos* Espinhos::recuperar() {
	ifstream recuperador("save/espinhos.dat", ios::app);

	Espinhos* e;
	Vector2f p;
	Vector2f t;

	if (!recuperador || recuperador.eof()) {
		return nullptr;
	}

	recuperador >> p.x >> p.y >> t.x >> t.y;

	e = new Espinhos(p, t);

	recuperador.close();

	return e;
}
