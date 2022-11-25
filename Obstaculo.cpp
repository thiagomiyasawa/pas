 #include "Obstaculo.h"

Obstaculo::Obstaculo(Vector2f p, Vector2f t, int id)
	: Entidade(p, t, id) {
	body->setPosition(p);
	solido = true;
	danoso = false;
}

Obstaculo::~Obstaculo() {
}
int Obstaculo::getDano() {
	return 0;
}
int Obstaculo::getAtivo() {
	return 1;
}
void Obstaculo::reduzAtivo() {

}

bool Obstaculo::getSolido() {
	return solido;
}
bool Obstaculo::getDanoso() {
	return danoso;
}
