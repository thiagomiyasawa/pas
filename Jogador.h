#pragma once
#include "Personagem.h"
#include <math.h>
using namespace std;
namespace personagens {
	class Jogador : public Personagem {
	private:
		int atacando;
		int imune;


	public:
		Jogador(int vidas, float x, float y, int id = 0);
		~Jogador();

		void move();
		void colidir(int ID);
		int getImune();



	};
}//fim
