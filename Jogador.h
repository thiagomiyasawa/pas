#pragma once
#include "Personagem.h"
namespace personagens {
	class Jogador : public Personagem {
	private:



	public:
		Jogador(int vidas, float x, float y);
		~Jogador();

		void move();


	};
}//fim
