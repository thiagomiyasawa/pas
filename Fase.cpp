#include "Fase.h"
using namespace fases;

Fase::Fase(RenderWindow* w, Jogador* j) {
	colisoes = new GerenciadorColisoes(j);
	window = w;
	j1 = j;
	j2 = nullptr;
	listaEntidades = new ListaEntidades;
	listaEntidades->push(j1);
	listaObstaculos = new Lista<Obstaculo>;
}

Fase::Fase(RenderWindow* w, Jogador* J1, Jogador* J2, float tempo) {
	colisoes = new GerenciadorColisoes(J1, J2);
	window = w;
	j1 = J1;
	j2 = J2;
	tempoInicial = tempo;
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
}

void Fase::inicializaElementos() {
	for (int i = 0; i < listaObstaculos->getSize(); i++) {
		Entidade* temp = listaObstaculos->getItem(i);
		listaEntidades->push(temp);
	}

}

ListaEntidades* Fase::getListaEntidades() {
	return listaEntidades;
}

GerenciadorColisoes* Fase::getGerenciadorColisoes() {
	return colisoes;
}

void Fase::executar() {
	for (int i = 0; i < listaEntidades->getSize(); i++) {
		Entidade* temp = listaEntidades->getItem(i);
		if (temp != nullptr && temp->getVivo())
			temp->move();
	}

	colisoes->executar();
	if (colisoes->testaListaInimigo()) {
		colisoes->limpaListaInimigo();
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
float Fase::getTempo(float tempo) {
	return tempo - tempoInicial;
}

void Fase::setTempoRestante(float tempo) {
	tempoRestante = tempo;
}

float Fase::getTempoRestante()
{
	return tempoRestante;
}

