#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Chao.h"
#include "ListaEntidades.h"

using namespace sf;
using namespace personagens;

class Fase {
private:
	Inimigo* i1;
	Jogador* j1;
	Chao* chao;
	ListaEntidades* listaEntidades;
	RenderWindow* window;
public:
	Fase(RenderWindow* w, Jogador* j1);
	~Fase();
	void inicializaElementos();
	ListaEntidades* getListaEntidades();
};

