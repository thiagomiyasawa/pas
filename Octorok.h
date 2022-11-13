#pragma once
#include "Inimigo.h"
namespace personagens {
	//polvo que atira
	class Octorok : public Inimigo
	{
	private:
	public:
		Octorok(int vidas, float x, float y);
		~Octorok();
	};
}//fim do namespace

