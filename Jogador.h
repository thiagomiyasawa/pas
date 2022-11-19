#pragma once
#include "Personagem.h"
#include <math.h>
#include "Projetil.h"
using namespace std;
namespace personagens {
	class Jogador : public Personagem {
	private:
		int atacando;
		Projetil* tiro;
		int pulo;
		Texture textura;

	public:
		Jogador(int vidas, Vector2f p, bool link1 = true);
		~Jogador();

		void move();

		int getAtacando();
		int getImune();
		int getDirecao();
		Projetil* getTiro();
		void setImune();
		void atira();
		void setNoChao(bool estado);



	};
}//fim
