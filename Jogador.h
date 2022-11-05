#pragma once
#include "Ente.h"
namespace personagens {
	class Jogador : public Ente {
	private:
		float velocidadey;
		bool NoChao;
		float x;
		float y;


	public:
		Jogador();
		~Jogador();

		void move();


	};
}//fim
