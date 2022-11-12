#pragma once
#include "Inimigo.h"
namespace personagens {
	//polvo que atira
	class Octorok : Inimigo
	{
	private:
	public:
		Octorok(int vidas, float x, float y, int id = 0);
		~Octorok();
	};
}//fim do namespace

