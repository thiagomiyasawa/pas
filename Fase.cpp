#include "Fase.h"

Fase::Fase(RenderWindow* w, Jogador* j) : colisoes(j) {
	window = w;
	j1 = j;
	colisoes.addProjetil(j->getTiro());
	i1 = new Inimigo(3,200.,200.);
	ganondorf = new Ganondorf(3, 400., 200.);
	octo1 = new Octorok(3, 600., 200.);
	moa1 = new Moa(3, 800., 200.);
	i1->setWindow(w);
	colisoes.addInimigo(i1);
	//colisoes.addInimigo(ganondorf);
	//colisoes.addInimigo(octo1);
	//colisoes.addInimigo(moa1);
	chao = new Obstaculo(0, 680, 1366, 100);
	plat1 = new Plataforma(500, 380, 100, 100);
	platF1 = new PlataformaFalsa(650, 380, 100, 100);
	espinho1 = new Espinhos(800, 380, 100, 100);
	lava1 = new Lava(950, 380, 100, 100);
	colisoes.addObstaculo(chao);
	colisoes.addObstaculo(plat1);
	colisoes.addObstaculo(platF1);
	colisoes.addObstaculo(espinho1);
	colisoes.addObstaculo(lava1);
	chao->setWindow(w);
	plat1->setWindow(w);
	listaEntidades = new ListaEntidades;
	inicializaElementos();
}

Fase::~Fase() {
}

void Fase::inicializaElementos() {
	listaEntidades->push(j1);
	listaEntidades->push(i1);
	listaEntidades->push(ganondorf);
	listaEntidades->push(octo1);
	listaEntidades->push(moa1);
	listaEntidades->push(chao);
	listaEntidades->push(plat1);
	listaEntidades->push(platF1);
	listaEntidades->push(espinho1);
	listaEntidades->push(lava1);
	listaEntidades->push(j1->getTiro());

}

ListaEntidades* Fase::getListaEntidades() {
	return listaEntidades;
}

void Fase::executar() {
	j1->move();
	(j1->getTiro())->move();
	i1->move();
	ganondorf->move();
	octo1->move();
	moa1->move();
	colisoes.executar();


}
