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
		Octorok(int vidas, Vector2f p);
		~Octorok();
		void move();
		void atira();
		void setProjetil(Projetil* p);
		Projetil* getProjetil();
		void setRecarga(int rec);
		void gravar();
		static Lista<Octorok>* recuperar();
	};
}//fim do namespace

