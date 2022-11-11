#include "Ente.h"
Ente::Ente(float l, float a) :body(Vector2f(l, a)) {
	window = NULL;
	largura = l;
	altura = a;
}

Ente::~Ente() {
}

void Ente::setWindow(RenderWindow* w) {
	this->window = w;
}

void Ente::draw() {
	window->draw(body);
}

float Ente::getLargura() const {
	return largura;
}
float Ente::getAltura() const {
	return altura;
}

void Ente::move() {

}