#include "Ente.h"
Ente::Ente(Vector2f t){
	window = nullptr;
	body = new RectangleShape(t);
	tamanho = t;
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
	return tamanho.x;
}
float Ente::getAltura() const {
	return tamanho.y;
}

RectangleShape* Ente::getBody() const {

	return body;
}
