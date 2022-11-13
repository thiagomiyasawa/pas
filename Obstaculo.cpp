 #include "Obstaculo.h"

Obstaculo::Obstaculo(float X, float Y, float l, float a, int id) 
	: Entidade(X, Y, l, a, id) {
	
	body->setPosition(Vector2f(x, y));
}

Obstaculo::~Obstaculo() {
}
