#include "Fase.h"

Fase::Fase(RenderWindow* w, Jogador* j) : colisoes(j) {
	window = w;
	j1 = j;
	i1 = new Inimigo(3,200.,200.);
	i1->setWindow(w);
	colisoes.addInimigo(i1);
	chao = new Chao;
	chao->setWindow(w);
	listaEntidades = new ListaEntidades;
	inicializaElementos();
}

Fase::~Fase() {
}

void Fase::inicializaElementos() {
	listaEntidades->push(j1);
	listaEntidades->push(i1);
	listaEntidades->push(chao);

}

ListaEntidades* Fase::getListaEntidades() {
	return listaEntidades;
}

void Fase::executar() {
	colisoes.executar();

}
