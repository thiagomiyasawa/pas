#include "Fase.h"

Fase::Fase(RenderWindow* w, Jogador* j) : colisoes(j) {
	window = w;
	j1 = j;
	j2 == nullptr;
	/*colisoes.addProjetil(j->getTiro());
	i1 = new Inimigo(3,200.,200.);
	ganondorf = new Ganondorf(3, 400., 200.);
	octo1 = new Octorok(3, 600., 200.);
	moa1 = new Moa(3, 800., 200.);
	i1->setWindow(w);
	colisoes.addInimigo(i1);
	colisoes.addInimigo(ganondorf);
	colisoes.addInimigo(octo1);
	colisoes.addInimigo(moa1);*/
	listaEntidades = new ListaEntidades;
	listaEntidades->push(j1);
	listaObstaculos = new Lista<Obstaculo>;
	criaMapa();
	inicializaElementos();
	
}

Fase::Fase(RenderWindow* w, Jogador* J1, Jogador* J2) : colisoes(J1, J2) {
	window = w;
	j1 = J1;
	j2 = J2;
	/*colisoes.addProjetil(j->getTiro());
	i1 = new Inimigo(3,200.,200.);
	ganondorf = new Ganondorf(3, 400., 200.);
	octo1 = new Octorok(3, 600., 200.);
	moa1 = new Moa(3, 800., 200.);
	i1->setWindow(w);
	colisoes.addInimigo(i1);
	colisoes.addInimigo(ganondorf);
	colisoes.addInimigo(octo1);
	colisoes.addInimigo(moa1);*/
	listaEntidades = new ListaEntidades;
	listaEntidades->push(j1);
	listaEntidades->push(j2);
	listaObstaculos = new Lista<Obstaculo>;
	criaMapa();
	inicializaElementos();

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
	listaEntidades->push(moa1);
	listaEntidades->push(j1->getTiro());*/
	for (int i = 0; i < listaObstaculos->getSize(); i++) {
		Entidade* temp = listaObstaculos->getItem(i);
		listaEntidades->push(temp);
	}

}

ListaEntidades* Fase::getListaEntidades() {
	return listaEntidades;
}

void Fase::criaMapa() {
	int i;
	
	Vector2f coordenada;
	Vector2f tamanho(50.f,50.f);
	


	//meio
	coordenada = Vector2f(465, 370);
	for (i = 0; i < 7; i++) {
		Obstaculo* temp = new Plataforma(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 50.;
	}
	
	//inferior esquerda
	coordenada = Vector2f(15, 520);
	for (i = 0; i < 8; i++) {
		Obstaculo* temp = new Plataforma(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 50.;
	}

	//inferior direita
	coordenada = Vector2f(865, 520);
	for (i = 0; i < 8; i++) {
		Obstaculo* temp = new Plataforma(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 50.;
	}
	//superior esquerda
	coordenada = Vector2f(15, 220);
	for (i = 0; i < 7; i++) {
		Obstaculo* temp = new Plataforma(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 50.;
	}

	//superior direita
	coordenada = Vector2f(915, 220);
	for (i = 0; i < 7; i++) {
		Obstaculo* temp = new Plataforma(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 50.;
	}
	
	//gera um numero aleatorio de plataformas falsas entre 3 e 20% das plaataformas
	srand(time(NULL));
	convertePlatF(rand() % (listaObstaculos->getSize() / 5 - 3) + 3);
	
	//gera um numero aleatorio de plataformas falsas entre 3 e 20% das plataformas
	converteEsp(rand() % (listaObstaculos->getSize() / 5 - 3) + 3);

	//adiciona a lava

	coordenada = Vector2f(-305., 650.);
	tamanho = Vector2f(70., 70.);

	for (i = 0; i < 29; i++) {
		Obstaculo* temp = new Lava(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 70.;
	}

	for (int i = 0; i < listaObstaculos->getSize(); i++) {
		Obstaculo* temp = listaObstaculos->getItem(i);
		colisoes.addObstaculo(temp);
	}
}

void Fase::convertePlatF(int n) {
	srand(time(NULL));
	/*while (n != 0) {
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
	while (n != 0) {
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

void Fase::executar() {
	j1->move();
	(j1->getTiro())->move();
	if (j2 != nullptr) {
	//	j2->move();
	}
	/*i1->move();
	ganondorf->move();
	octo1->move();
	moa1->move();*/
	colisoes.executar();


}
