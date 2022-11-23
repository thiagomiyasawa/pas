#include "Projetil.h"
Projetil:: Projetil():Entidade(Vector2f(0.,0.), Vector2f(20.,10.), 41) {
	ativo = false;
	velocidade = Vector2f(0.2, 0.);
}
Projetil::~Projetil() {

}
void Projetil::setAtivo(bool estado) {
	ativo = estado;
	if(ativo)
		body->setFillColor(Color(232, 194, 102));
	else {
		body->setFillColor(Color::Transparent);
		posicao.x = -100;
		posicao.y = -100;
	}
}
bool Projetil::getAtivo() {
	return ativo;
}
void Projetil::move() {
	if (ativo) {
		
		posicao.x += velocidade.x;
		posicao.y += velocidade.y;
		body->setPosition(posicao);
		velocidade.y += 0.001f;
	}
}

void Projetil::gravar() {
	ofstream gravador("save/projetil.dat", ios::app);

	if (!gravador)
	{
		return;
	}
	gravador << ativo << ' '
			 << posicao.x << ' '
			 << posicao.y << ' '
			 << velocidade.x << ' '
			 << velocidade.y << endl;
	gravador.close();
}

Projetil* Projetil::recuperar() {
	ifstream recuperador("save/projetil.dat", ios::in);
	Projetil* P;
	bool a;
	Vector2f p;
	Vector2f v;

	if (!recuperador || recuperador.eof()) {
		return nullptr;
	}

	recuperador >> a >> p.x >> p.y >> v.x >> v.y;

	P = new Projetil();
	P->setAtivo(a);
	P->setPosicao(p);
	P->setVelocidade(v);
	
	recuperador.close();
	
	return P;
}
