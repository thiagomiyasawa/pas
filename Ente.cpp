#include "Ente.h"
Ente::Ente(float l, float a){
	window = NULL;
	body = new RectangleShape(Vector2f(l, a));
	largura = l;
	altura = a;
}

Ente::~Ente() {
	delete window;
	delete body;
}

void Ente::setWindow(RenderWindow* w) {
	this->window = w;
}

void Ente::draw() {
	window->draw(*body);
}

float Ente::getLargura() const {
	return largura;
}
float Ente::getAltura() const {
	return altura;
}

RectangleShape* Ente::getBody()
{
	return body;
}
