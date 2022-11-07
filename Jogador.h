#pragma once
#include "Personagem.h"
namespace personagens {
	class Jogador : public Personagem {
	private:
		float velocidadey;
		bool NoChao;


	public:
		Jogador();
		~Jogador();

		void move();


	};
}//fim
