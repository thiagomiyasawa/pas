#pragma once
#include "Personagem.h"
namespace personagens {
	class Jogador : public Personagem {
	private:



	public:
		Jogador(int vidas, float x, float y, int id = 0);
		~Jogador();

		void move();


	};
}//fim
