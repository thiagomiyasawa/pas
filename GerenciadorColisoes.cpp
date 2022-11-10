#include "GerenciadorColisoes.h"
GerenciadorColisoes::GerenciadorColisoes(Jogador* player1,Jogador* player2){
	jogador1 = player1;
	jogador2 = player2;
}
GerenciadorColisoes::~GerenciadorColisoes() {
	jogador1 = NULL;
	jogador2 = NULL;
	LIs.clear();
	LOs.clear();
}
void GerenciadorColisoes::executar() {
	list<Inimigo*>::iterator it;
	it = LIs.begin();
	int i = 0;
	while (i < LIs.size()) {
		if (jogador1 != NULL)
			testaColisao((Entidade*)jogador1, (Entidade*)*it);
		i++;
		it++;


	}

}
void GerenciadorColisoes::addObstaculo(Obstaculo* obst) {
	LOs.push_back(obst);
}
void GerenciadorColisoes::addInimigo(Inimigo* Inim) {
	LIs.push_back(Inim);
}
void GerenciadorColisoes::removeObstaculo(int posicao) {
	vector<Obstaculo*>::iterator it = LOs.begin();
	for (int i = 0; i < posicao; i++) {
		it++;
	}
	LOs.erase(it);
}
void GerenciadorColisoes::removeInimigo(int posicao) {
	list<Inimigo*>::iterator it = LIs.begin();
	for (int i = 0; i < posicao; i++) {
		it++;
	}
	LIs.erase(it);
}

bool GerenciadorColisoes::testaColisao(Entidade* obj1, Entidade* obj2) {
	if (obj1->getX() + obj1->getLargura() > obj2->getX() && obj1->getX() < obj2->getX() + obj2->getLargura() && obj1->getY() + obj1->getAltura() > obj2->getY() && obj1->getY() < obj2->getY() + obj2->getAltura()) {
		return true;
	}
	return false;
}


