#include "SegundaFase.h"

SegundaFase::SegundaFase(RenderWindow* w, Jogador* j) : Fase(w, j)
{
	criaMapa();
	inicializaElementos();
}

SegundaFase::SegundaFase(RenderWindow* w, Jogador* J1, Jogador* J2)
	: Fase(w, J1, J2) {
	criaMapa();
	inicializaElementos();
}

SegundaFase::~SegundaFase()
{
}

void SegundaFase::criaMapa()
{
	int i;

	Vector2f coordenada;
	Vector2f tamanho(50.f, 50.f);
	
	
	//inferior
	coordenada = Vector2f(-35, 550);
	for (i = 0; i < 27; i++) {
		Obstaculo* temp = new Plataforma(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 50.;
	}

	//superior
	coordenada = Vector2f(375, 300);
	for (i = 0; i < 11; i++) {
		Obstaculo* temp = new Plataforma(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 50.;
	}

	//quina esquerda
	coordenada = Vector2f(265, 350);
	for (i = 0; i < 3; i++) {
		Obstaculo* temp = new Plataforma(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 50.;
	}

	//quina direita
	coordenada = Vector2f(865, 350);
	for (i = 0; i < 3; i++) {
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

	coordenada = Vector2f(-60., 650.);
	tamanho = Vector2f(70., 70.);

	for (i = 0; i < 20; i++) {
		Obstaculo* temp = new Lava(coordenada, tamanho);
		listaObstaculos->push(temp);
		coordenada.x += 70.;
	}

	//gera o contorno da fase
	coordenada = Vector2f(-100., 0.);
	tamanho = Vector2f(10., 820.);
	Obstaculo* temp = new Plataforma(coordenada, tamanho);
	listaObstaculos->push(temp);

	coordenada = Vector2f(-100., 820.);
	tamanho = Vector2f(1280., 30.);
	temp = new Plataforma(coordenada, tamanho);
	listaObstaculos->push(temp);

	coordenada = Vector2f(1370., 0);
	tamanho = Vector2f(10., 820.);
	temp = new Plataforma(coordenada, tamanho);
	listaObstaculos->push(temp);

	for (int i = 0; i < listaObstaculos->getSize(); i++) {
		Obstaculo* temp = listaObstaculos->getItem(i);
		colisoes.addObstaculo(temp);
	}

	for (int i = 0; i < 3; i++) {
		geraMoa();
	}

}

void SegundaFase::geraInimigoAleatorio()
{
}

void SegundaFase::geraMoa()
{
}
