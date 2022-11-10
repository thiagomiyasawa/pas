#include "Chao.h"

Chao::Chao() : Obstaculo(0, 380, 400, 100) {
	body.setFillColor(Color::Blue);
	body.setPosition(Vector2f(x, y));
}

Chao::~Chao() {
}
