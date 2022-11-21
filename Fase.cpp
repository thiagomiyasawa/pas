#include "Fase.h"

Fase::Fase(RenderWindow* w, Jogador* j) : colisoes(j) {
	window = w;
	j1 = j;
	j2 = nullptr;
	listaEntidades = new ListaEntidades;
	listaEntidades->push(j1);
	listaObstaculos = new Lista<Obstaculo>;
	
}

Fase::Fase(RenderWindow* w, Jogador* J1, Jogador* J2) : colisoes(J1, J2) {
	window = w;
	j1 = J1;
	j2 = J2;
	listaEntidades = new ListaEntidades;
	listaEntidades->push(j1);
	if (j2 != nullptr) {
		listaEntidades->push(j2);
	}
	listaObstaculos = new Lista<Obstaculo>;

}

Fase::~Fase() {
	for (int i = 0; i < listaEntidades->getSize(); i++) {
		listaEntidades->pop(i);
	}
	delete listaEntidades;
	delete listaObstaculos;
	delete window;
}

void Fase::inicializaElementos() {
	/*listaEntidades->push(i1);
	listaEntidades->push(ganondorf);
	listaEntidades->push(octo1);
	listaEntidades->push(moa1);*/
	for (int i = 0; i < listaObstaculos->getSize(); i++) {
		Entidade* temp = listaObstaculos->getItem(i);
		listaEntidades->push(temp);
	}

}

ListaEntidades* Fase::getListaEntidades() {
	return listaEntidades;
}

void Fase::executar() {
	/*j1->move();
	(j1->getTiro())->move();
	if (j2 != nullptr) {
	j2->move();
	}*/
	for (int i = 0; i < listaEntidades->getSize(); i++) {
		Entidade* temp = listaEntidades->getItem(i);
		if (temp != nullptr && temp->getVivo())
			temp->move();
	}

	colisoes.executar();
	if (colisoes.testaListaInimigo()) {
		colisoes.limpaListaInimigo();
		for (int i = 0; i < 6; i++) {
			geraInimigoAleatorio();
		}
	}

}

void Fase::convertePlatF(int n) {
	srand(time(NULL));
	while (n > 0) {

		for (int i = 0; i < listaObstaculos->getSize(); i++) {
			if (rand() % 100 == 1 && listaObstaculos->getItem(i)->getId() == 31) {
				Obstaculo* temp = listaObstaculos->getItem(i);
				listaObstaculos->pop(temp);
				temp = new PlataformaFalsa(Vector2f(temp->getX(), temp->getY()), Vector2f(temp->getLargura(), temp->getAltura()));
				listaObstaculos->push(temp);
				n--;
			}
		}
	}
}

void Fase::converteEsp(int n) {
	srand(time(NULL));
	while (n > 0) {
		for (int i = 0; i < listaObstaculos->getSize(); i++) {
			if (rand() % 100 == 1 && listaObstaculos->getItem(i)->getId() == 31) {
				Obstaculo* temp = listaObstaculos->getItem(i);
				listaObstaculos->pop(temp);
				temp = new Espinhos(Vector2f(temp->getX(), temp->getY()), Vector2f(temp->getLargura(), temp->getAltura()));
				listaObstaculos->push(temp);
				n--;
			}
		}
	}
}