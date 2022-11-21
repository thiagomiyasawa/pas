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
		static int potuacão;

	public:
		Jogador(int vidas, Vector2f p, int num);
		~Jogador();

		void move();

		int getAtacando();
		int getImune();
		int getDirecao();
		void setImune();
		void setNoChao(bool estado);



	};
}//fim
