#pragma once
#include <list>
#include <vector>
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Jogador.h"
using namespace std;
using namespace personagens;
class GerenciadorColisoes{
	private:
		list <Inimigo*> LIs;
		vector <Obstaculo*> LOs;
		Jogador* jogador1=NULL;
		Jogador* jogador2=NULL;
	
	public:
		GerenciadorColisoes(Jogador* player1, Jogador* player2);
		~GerenciadorColisoes();
		void execultar();
		void addObtaculo(Obstaculo* obst);
		void addInimigo(Inimigo* Inim);
		void removeObstaculo(int posicao);
		void removeInimigo(int posicao);
		bool testaColisao(Obstaculo* obst, Jogador player);
		bool testaColisao(Inimigo* Inim, Jogador player);
};

