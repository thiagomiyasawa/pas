#include "Ente.h"
Ente::Ente() :body(Vector2f(100.f, 100.f)) {
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
