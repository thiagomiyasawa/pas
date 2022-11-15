#pragma once
#include "Personagem.h"
namespace personagens {
	class Inimigo : public Personagem {
	private:
		int dano;
	public:
		Inimigo(int vidas, float x, float y, int valor = 1, int id = 0);
		~Inimigo();
		void move();

		int getDano();
		int getImune();

		void setImune();

		void removeVidas(int dano);
	};
}//fim
