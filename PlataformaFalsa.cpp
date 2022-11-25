#include "PlataformaFalsa.h"

PlataformaFalsa::PlataformaFalsa(Vector2f coordenada, Vector2f tamanho) :
	Obstaculo(coordenada, tamanho, 34)
{
	textura.loadFromFile("sprites/plataformaFalsa.png");
	body->setTexture(&textura);
	ativo = 500;
}

PlataformaFalsa::~PlataformaFalsa()
{
}

void PlataformaFalsa::setAtivo(int a) {
	ativo = a;
}

int PlataformaFalsa::getAtivo() {
	return ativo;
}
void PlataformaFalsa::reduzAtivo() {
	ativo--;
	if (!ativo) {
		body->setFillColor(Color::Transparent);
	}
}

void PlataformaFalsa::gravar()
{
	ofstream gravador("save/plataformafalsa.dat", ios::app);

	if (!gravador)
	{
		return;
	}
	gravador << endl<< posicao.x << ' '
			 << posicao.y << ' '
			 << tamanho.x << ' '
			 << tamanho.y << ' '
			 << ativo ;
	gravador.close();

}

Lista<PlataformaFalsa>* PlataformaFalsa::recuperar() {
	ifstream recuperador("save/plataformafalsa.dat", ios::in);
	Lista<PlataformaFalsa>* l = new Lista<PlataformaFalsa>;
	Vector2f p;
	Vector2f t;
	int a;
	if (!recuperador) {
		return nullptr;
	}
	while (!recuperador.eof()) {
		recuperador >> p.x >> p.y >> t.x >> t.y >> a;

		PlataformaFalsa* temp = new PlataformaFalsa(p, t);
		temp->setAtivo(a);
		l->push(temp);
	}
	recuperador.close();
	return l;


}