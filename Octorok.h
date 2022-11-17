#pragma once
#include "Inimigo.h"
#include "Projetil.h"
namespace personagens {
	//polvo que atira
	class Octorok : public Inimigo
	{
	private:
		Projetil* pedra;
		int recarga;

	public:
		Octorok(int vidas, float x, float y);
		~Octorok();
		void move();
		void atira();
		Projetil* getProjetil();
	};
}//fim do namespace

