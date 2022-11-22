#pragma once
#include "Personagem.h"
#include <math.h>
#include "Projetil.h"
namespace personagens {
	class Jogador : public Personagem {
	private:
		int atacando;
		Projetil* tiro;
		int pulo;
		Texture textura;
		static int pontuacao;

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
		static Jogador* recuperar();

	};
}//fim
