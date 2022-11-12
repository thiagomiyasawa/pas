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
	list<Inimigo*>::iterator itI;
	itI = LIs.begin();
	int i = 0, j=0;
	int tipoColi;
	Inimigo* obj;
	while (i < LIs.size()) {
		obj = *itI;
		if (jogador1 != NULL) {
			tipoColi=testaColisao((Entidade*)jogador1, (Entidade*)obj);

			if (testaColisao((Entidade*)jogador1, (Entidade*)obj)) {
				if (!jogador1->getImune())
					colidirInimigo(jogador1, *itI);
			}
		}

		i++;
		itI++;

	}
	vector<Obstaculo*>::iterator itO;
	itO = LOs.begin();
	i = 0;
	while(i<LOs.size()){
		if (jogador1 != NULL) {
			int tipo =testaColisao((Entidade*)jogador1, (Entidade*)*itO);
			colidirObstaculo(tipo, jogador1, *itO);
		}
		itI = LIs.begin();
		j = 0;
		while (j < LIs.size()) {
			int tipo = testaColisao((Entidade*)*itI, (Entidade*)*itO);
			colidirObstaculo(tipo, *itI, *itO);
			j++;
			itI++;
		}
		i++;
		itO++;
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

		if (obj1->getX() + obj1->getLargura() < obj2->getX() + 2 ){
			return 3;
		}
		if (obj1->getX() > obj2->getX() + obj2->getLargura() - 1) {
			return 4;
		}
	}
	return 0;	
}

void GerenciadorColisoes::colidirObstaculo(int direcao, Jogador* obj1, Obstaculo* obj2) {
	if (obj2->getId() == 31) {
		if (direcao == 1 && !obj1->getNoChao()) {
			obj1->setVelocidadeY(0);
			obj1->setNoChao(true);
		}

		else if (direcao == 2) {
			obj1->setVelocidadeY(obj1->getVelocidadeY() * -0.5f);
		}

		else if (direcao == 3) {
			obj1->setVelocidadeX(0);
			obj1->setX(obj2->getX() - obj1->getLargura()-2);
		}
		else if (direcao == 4) {
			obj1->setVelocidadeX(0);
			obj1->setX(obj2->getX() + obj2->getLargura());
		}
	}
}
void GerenciadorColisoes::colidirObstaculo(int direcao, Inimigo* obj1, Obstaculo* obj2) {
	if (obj2->getId() == 31) {
		if (direcao == 1 && !obj1->getNoChao()) {
			obj1->setVelocidadeY(0);
			obj1->setNoChao(true);
		}

		else if (direcao == 2) {
			obj1->setVelocidadeY(obj1->getVelocidadeY() * -0.5f);
		}

		else if (direcao == 3) {
			obj1->setVelocidadeX(0);
			obj1->setX(obj2->getX() - obj1->getLargura() - 2);
		}
		else if (direcao == 4) {
			obj1->setVelocidadeX(0);
			obj1->setX(obj2->getX() + obj2->getLargura());
		}
	}
}
void GerenciadorColisoes::colidirInimigo( Jogador* obj1, Inimigo* obj2){
	obj1->removevidas(obj2->getDano());
	obj1->setImune();
	obj1->getBody()->setFillColor(Color::Color(20, 34, 184));
}

