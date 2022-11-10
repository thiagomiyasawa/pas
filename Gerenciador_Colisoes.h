#pragma once
#include <list>
#include <vector>
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Jogador.h"
using namespace std;
using namespace personagens;
class Gerenciador_Colisoes{
	private:
		list <Inimigo*> LIs;
		vector <Obstaculo*> LOs;
		Jogador* jogador1=NULL;
		Jogador* jogador2=NULL;
	
	public:
		Gerenciador_Colisoes(Jogador* player1, Jogador* player2=NULL);
		~Gerenciador_Colisoes();
		void execultar();
		void addObtaculo(Obstaculo* obst);
		void addInimigo(Inimigo* Inim);
		void removeObstaculo(int posicao);
		void removeInimigo(int posicao);
		int testaColisao(Entidade* obj1, Entidade* obj2);
		
};

