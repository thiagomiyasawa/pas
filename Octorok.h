#pragma once
#include "Inimigo.h"
namespace personagens {
	//polvo que atira
	class Octorok : Inimigo
	{
	private:
	public:
		Octorok(int vidas, float x, float y);
		~Octorok();
	};
}//fim do namespace

