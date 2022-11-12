#pragma once
#include "Personagem.h"
namespace personagens {
	class Inimigo : public Personagem {
	private:
		int dano;
	public:
		Inimigo(int vidas, float x, float y, int id = 0);
		~Inimigo();
		void move();

		int getDano();
	};
}//fim
