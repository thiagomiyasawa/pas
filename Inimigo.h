#pragma once
#include "Personagem.h"
class Jogo;
namespace personagens {
	class Inimigo : public Personagem {
	protected:
		int dano;
	public:
		Inimigo(int vidas, Vector2f t, Vector2f p, int id = 0, int valor = 1);
		~Inimigo();
		virtual void move();

		int getDano();
		int getImune();

		void setImune();

		void removeVidas(int dano);

	};
}//fim
