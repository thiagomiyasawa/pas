#include "Entidade.h"

Entidade::Entidade(float X, float Y, float l, float a,int ID=0) : Ente(l,a) {
	x = X;
	y = Y;
	id = ID;
}

Entidade::~Entidade() {
}

float Entidade::getX() const {
	return x;
}
float Entidade::getY() const {
	return y;
}
int Entidade::getId() const {
	return id;
}
float Entidade::getVelocidadeX() {
	return velocidadeX;
}

float Entidade::getVelocidadeY() {
	return velocidadeY;
}

void Entidade::setX(int valor) {
	x = valor;
}
void Entidade::setY(int valor) {
	y = valor;
}
void Entidade::setVelocidadeX(float velocidade) {
	velocidadeX = velocidade;
}

void Entidade::setVelocidadeY(float velocidade) {
	velocidadeY = velocidade;
}

void Entidade::move() {

}