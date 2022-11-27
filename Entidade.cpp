#include "Entidade.h"

Entidade::Entidade(Vector2f p, Vector2f t,int ID) : Ente(t) {
	posicao = p;
	id = ID;
}

Entidade::~Entidade() {
}


float Entidade::getX() const {
	return posicao.x;
}
float Entidade::getY() const {
	return posicao.y;
}
int Entidade::getId() const {
	return id;
}
float Entidade::getVelocidadeX() {
	return velocidade.x;
}

float Entidade::getVelocidadeY() {
	return velocidade.y;
}

void Entidade::setX(int valor) {
	posicao.x = valor;
}
void Entidade::setY(int valor) {
	posicao.y = valor;
}
void Entidade::setPosicao(Vector2f p) {
	posicao = p;
}
void Entidade::setVelocidadeX(float v) {
	velocidade.x = v;
}

void Entidade::setVelocidadeY(float v) {
	velocidade.y = v;
}

void Entidade::setVelocidade(Vector2f v) {
	velocidade = v;
}

void Entidade::gravidade() {
	velocidade.y += 0.001f;
}

bool Entidade::getVivo() {
	return true;
}