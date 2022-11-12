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
	list<Inimigo*>::iterator it1;
	it1 = LIs.begin();
	int i = 0, j=0;
	int tipoColi;
	Inimigo* obj;
	while (i < LIs.size()) {
		obj = *it1;
		if (jogador1 != NULL) {
			tipoColi=testaColisao((Entidade*)jogador1, (Entidade*)obj);

			if (tipoColi) {
				if(!jogador1->getImune())
					jogador1->colidir(11);
			}
		}

		i++;
		it1++;

	}
	vector<Obstaculo*>::iterator it2;
	it2 = LOs.begin();
	i = 0;
	while(i<LOs.size()){
		if (jogador1 != NULL) {
			int colisao =20 + testaColisao((Entidade*)jogador1, (Entidade*)*it2);
			jogador1->colidir(colisao);
		}
		it1 = LIs.begin();
		j = 0;
		while (j < LIs.size()) {
			int colisao =20 + testaColisao((Entidade*)*it1, (Entidade*)*it2);
			(*it1)->colidir(colisao);
			j++;
			it1++;
		}
		i++;
		it2++;
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

int GerenciadorColisoes::testaColisao(Entidade* obj1, Entidade* obj2){
	if (obj1->getX() + obj1->getLargura() > obj2->getX()-1 && obj1->getX() < obj2->getX() + obj2->getLargura() && obj1->getY() + obj1->getAltura() > obj2->getY()-0.5 && obj1->getY() < obj2->getY() + obj2->getAltura()) {

		if (obj1->getY() + obj1->getAltura() < obj2->getY() + 2) {
			return 1;
		}

		if (obj1->getY() > obj2->getY() + obj2->getAltura() - 5 && obj1->getVelocidadeY() < 0 ) {
			return 2;
		}

		if (obj1->getX() + obj1->getLargura() > obj2->getX() - 1 || obj1->getX() < obj2->getX() + obj2->getLargura()){
			return 3;
		}
	}
	return 0;	
}


