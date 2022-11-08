#include "Gerenciador_Colisoes.h"
Gerenciador_Colisoes::Gerenciador_Colisoes(Jogador* player1,Jogador* player2=NULL){
	jogador1 = player1;
	jogador2 = player2;
}
Gerenciador_Colisoes::~Gerenciador_Colisoes() {
	jogador1 = NULL;
	jogador2 = NULL;
	LIs.clear();
	LOs.clear();
}
void Gerenciador_Colisoes::execultar() {
	list<Inimigo*>::iterator it;
	int i=0;
	while (i<LIs.size()) {


	}
}
void Gerenciador_Colisoes::addObtaculo(Obstaculo* obst) {
	LOs.push_back(obst);
}
void Gerenciador_Colisoes::addInimigo(Inimigo* Inim) {
	LIs.push_back(Inim);
}
void Gerenciador_Colisoes::removeObstaculo(int posicao) {
	vector<Obstaculo*>::iterator it = LOs.begin();
	for (int i = 0; i < posicao; i++) {
		it++;
	}
	LOs.erase(it);
}
void Gerenciador_Colisoes::removeInimigo(int posicao) {
	list<Inimigo*>::iterator it = LIs.begin();
	for (int i = 0; i < posicao; i++) {
		it++;
	}
	LIs.erase(it);
}

