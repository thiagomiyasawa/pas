#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "Ganondorf.h"
#include "Moa.h"
#include "Octorok.h"
#include "Obstaculo.h"
#include "Plataforma.h"
#include "PlataformaFalsa.h"
#include "Espinhos.h"
#include "Lava.h"
#include "ListaEntidades.h"
#include "GerenciadorColisoes.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;
using namespace sf;
using namespace personagens;

class Fase {
protected:
	Jogador* j1;
	Jogador* j2;
	Lista<Obstaculo>* listaObstaculos;
	ListaEntidades* listaEntidades;
	GerenciadorColisoes colisoes;
	RenderWindow* window;
	queue<int> fila;
public:
	Fase(RenderWindow* w, Jogador* j1);
	Fase(RenderWindow* w, Jogador* J1, Jogador* J2);
	~Fase();
	void inicializaElementos();
	ListaEntidades* getListaEntidades();
	
	void executar();
	
	virtual void criaMapa() = 0;
	void convertePlatF(int n);
	void converteEsp(int n);

	virtual void geraInimigoAleatorio() = 0;
	
};

