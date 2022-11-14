#pragma once
#include "Personagem.h"
#include <math.h>
#include "Projetil.h"
using namespace std;
namespace personagens {
	class Jogador : public Personagem {
	private:
		int atacando;
		Projetil* tiro;

	public:
		Jogador(int vidas, float x, float y );
		~Jogador();

		void move();

		int getAtacando();
		int getImune();
		int getDirecao();
		Projetil* getTiro();
		void setImune();
		void atira();



	};
}//fim
