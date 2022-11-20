#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ente.h"
#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "fase.h"
#include "Menu.h"
using namespace std;
using namespace sf;
using namespace personagens;
class Jogo{
private:
	GerenciadorGrafico* grafico;
	Jogador* link1;
	Jogador* link2;
	ListaEntidades* LEs;
	Menu* menu;

	Fase* fase1;
	int estado;
public:
	Jogo();
	~Jogo();
	void Executar();
	void setEstado(int valor);


};

