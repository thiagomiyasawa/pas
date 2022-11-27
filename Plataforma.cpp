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
void Plataforma::move() {
	velocidade.y -= 0.001f;
	gravidade();

}
void Plataforma::gravar() {
    ofstream gravador("save/plataforma.dat", ios::app);

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

Lista<Plataforma>* Plataforma::recuperar() {
	ifstream recuperador("save/plataforma.dat", ios::in);
	Lista<Plataforma>* l = new Lista<Plataforma>;
	Vector2f p;
	Vector2f t;
	if (!recuperador) {
		return nullptr;
	}
	while (!recuperador.eof()) {
		recuperador >> p.x >> p.y >> t.x >> t.y;

		Plataforma* temp = new Plataforma(p, t);
		l->push(temp);
	}
	recuperador.close();
	return l;


}