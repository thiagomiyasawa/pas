#include "Ente.h"
Ente::Ente(float l, float a) :body(Vector2f(l, a)) {
	window = NULL;
}

Ente::~Ente() {
}

void Ente::setWindow(RenderWindow* w) {
	this->window = w;
}

void Ente::draw() {
	window->draw(body);
}
