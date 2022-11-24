#pragma once
#include "Personagem.h"
#include <math.h>

using namespace std;
namespace personagens {
	class Jogador : public Personagem {
	private:
		int atacando;
		int pulo;
		Texture textura;

	public:
		Jogador(int vidas, Vector2f p, int id);
		~Jogador();

		void move();

		int getAtacando();
		int getImune();
		int getDirecao();
		void setImune();
		void setNoChao(bool estado);

		void gravar();
		static Lista<Jogador>* recuperar();

	};
}//fim
