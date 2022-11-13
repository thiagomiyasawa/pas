#include "Octorok.h"
using namespace personagens;
Octorok::Octorok(int vidas, float x, float y) :
	Inimigo(vidas, x, y, 22)
{
	body->setFillColor(Color::Magenta);
}

Octorok::~Octorok()
{
}
