#pragma once
#include "Personagem.h"
#include <math.h>
namespace personagens {
	class Jogador : public Personagem {
	private:
		int atacando;


	public:
		Jogador(int vidas, float x, float y, int id = 0);
		~Jogador();

		void move();
		void colidir(int ID);



	};
}//fim
