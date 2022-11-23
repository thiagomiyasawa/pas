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
	gravador << posicao.x << ' '
			 << posicao.y << ' '
			 << tamanho.x << ' '
			 << tamanho.y << ' '
			 << ativo << endl;
	gravador.close();

}

PlataformaFalsa* PlataformaFalsa::recuperar() {
	ifstream recuperador("save/plataformafalsa.dat", ios::app);

	PlataformaFalsa* pf;
	Vector2f p;
	Vector2f t;
	int a;

	if (!recuperador || recuperador.eof()) {
		return nullptr;
	}

	recuperador >> p.x >> p.y >> t.x >> t.y >> a;

	pf = new PlataformaFalsa(p, t);
	pf->setAtivo(a);

	recuperador.close();

	return pf;
}
