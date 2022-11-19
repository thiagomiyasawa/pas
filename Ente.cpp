#include "Ente.h"
Ente::Ente(float l, float a){
	window = nullptr;
	body = new RectangleShape(Vector2f(l, a));
	largura = l;
	altura = a;
}

Ente::~Ente() {
	window=nullptr;
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

RectangleShape* Ente::getBody() const {

	return body;
}
