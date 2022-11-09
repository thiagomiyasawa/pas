#pragma once
#include "Personagem.h"
namespace personagens {
	class Inimigo : public Personagem {
	private:
	public:
		Inimigo(int vidas, float x, float y);
		~Inimigo();
	};
}//fim
