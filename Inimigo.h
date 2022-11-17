#pragma once
#include "Personagem.h"
namespace personagens {
	class Inimigo : public Personagem {
	protected:
		int dano;
		Texture textura;
	public:
		Inimigo(int vidas, float x, float y, int id = 0, int valor = 1);
		~Inimigo();
		virtual void move();

		int getDano();
		int getImune();

		void setImune();

		void removeVidas(int dano);
	};
}//fim
