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
using namespace gerenciadores;
using namespace entidades;
using namespace personagens;
using namespace obstaculos;
using namespace listas;

namespace fases {
	class Fase {
	protected:
		Jogador* j1;
		Jogador* j2;
		Lista<Obstaculo>* listaObstaculos;
		ListaEntidades* listaEntidades;
		GerenciadorColisoes* colisoes;
		RenderWindow* window;
		float tempoInicial;
		float tempoRestante;
	public:
		Fase(RenderWindow* w, Jogador* j1);
		Fase(RenderWindow* w, Jogador* J1, Jogador* J2, float tempo);
		~Fase();
		void inicializaElementos();
		ListaEntidades* getListaEntidades();
		GerenciadorColisoes* getGerenciadorColisoes();

		void executar();

		virtual void criaMapa() = 0;
		void convertePlatF(int n);
		void converteEsp(int n);

		virtual void geraInimigoAleatorio() = 0;
		virtual void salvar(int pontos, float tempo) = 0;

		float getTempo(float tempo);
		void setTempoRestante(float tempo);
		float getTempoRestante();
	};
}//fim do namespace
