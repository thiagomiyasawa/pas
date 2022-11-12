#include "Fase.h"

Fase::Fase(RenderWindow* w, Jogador* j) : colisoes(j) {
	window = w;
	j1 = j;
	i1 = new Inimigo(3,200.,200.);
	i1->setWindow(w);
	colisoes.addInimigo(i1);
	chao = new Obstaculo(0, 680, 1366, 100);
	obst1 = new Obstaculo(500, 380, 100, 100);
	colisoes.addObstaculo(chao);
	colisoes.addObstaculo(obst1);
	chao->setWindow(w);
	obst1->setWindow(w);
	listaEntidades = new ListaEntidades;
	inicializaElementos();
}

Fase::~Fase() {
}

void Fase::inicializaElementos() {
	listaEntidades->push(j1);
	listaEntidades->push(i1);
	listaEntidades->push(chao);
	listaEntidades->push(obst1);

}

ListaEntidades* Fase::getListaEntidades() {
	return listaEntidades;
}

void Fase::executar() {
	j1->move();
	i1->move();
	colisoes.executar();


}
