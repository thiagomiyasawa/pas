#include "Fase.h"

Fase::Fase(RenderWindow* w, Jogador* j):colisoes(j) {
	window = w;
	j1 = j;
	i1 = new Inimigo(3,200.,200.);
	colisoes.addInimigo(i1);
	i1->setWindow(w);
	listaEntidades = new ListaEntidades;
	inicializaElementos();
}

Fase::~Fase() {
}

void Fase::inicializaElementos() {
	listaEntidades->push(j1);
	listaEntidades->push(i1);

}

ListaEntidades* Fase::getListaEntidades()
{
	return listaEntidades;
}

void Fase::executar() {
	colisoes.execultar();

}