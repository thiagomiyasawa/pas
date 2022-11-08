#pragma once
#include "Personagem.h"
namespace personagens {
	class Jogador : public Personagem {
	private:
		float velocidadey;
		bool NoChao;


	public:
		Jogador(int vidas, float x, float y);
		~Jogador();

		void move();


	};
}//fim
