#include "Espinhos.h"

Espinhos::Espinhos(Vector2f coordenada, Vector2f tamanho) :
	Obstaculo(coordenada, tamanho, 32)
{
	textura.loadFromFile("sprites/espinhos.png");
	body->setTexture(&textura);
	dano = 1;
	solido = true;
	danoso = true;
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
    gravador << endl << posicao.x << ' '
			 << posicao.y << ' '
			 << tamanho.x << ' '
			 << tamanho.y;
    gravador.close();
}

Lista<Espinhos>* Espinhos::recuperar() {
	ifstream recuperador("save/espinhos.dat", ios::in);
	Lista<Espinhos>* l = new Lista<Espinhos>;
	Vector2f p;
	Vector2f t;
	if (!recuperador) {
		return nullptr;
	}
	while (!recuperador.eof()) {
		recuperador >> p.x >> p.y >> t.x >> t.y;

		Espinhos* temp = new Espinhos(p, t);
		l->push(temp);
	}
	recuperador.close();
	return l;


}