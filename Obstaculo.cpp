 #include "Obstaculo.h"

Obstaculo::Obstaculo(Vector2f coordenada, Vector2f tamanho, int id)
	: Entidade(coordenada.x, coordenada.y, tamanho.x, tamanho.y, id) {
	body->setPosition(coordenada);
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

