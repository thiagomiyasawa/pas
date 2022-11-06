#include "Fase.h"

Fase::Fase(RenderWindow* w, Jogador* j) {
	window = w;
	j1 = j;
	i1 = new Inimigo;
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
