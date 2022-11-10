#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

using namespace sf;
using namespace personagens;

class Fase {
private:
	Jogador* j1;
	Gerenciador_Colisoes colisoes;
	Inimigo* i1;
	ListaEntidades* listaEntidades;
	RenderWindow* window;
public:
	Fase(RenderWindow* w, Jogador* j1);
	~Fase();
	void inicializaElementos();
	ListaEntidades* getListaEntidades();
	void executar();
};

