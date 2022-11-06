#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ente.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "fase.h"
using namespace std;
using namespace sf;
using namespace personagens;
class Jogo{
private:
	RenderWindow window;
	Jogador* jogador1;
	ListaEntidades* LEs;

	Fase* fase1;
public:
	Jogo();
	~Jogo();
	void Executar();


};

