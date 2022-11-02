#include "ListaEntidade.h"

ListaEntidade::ListaEntidade() {

}

ListaEntidade::~ListaEntidade() {

}

void ListaEntidade::addEntidade(Ente* entidade) {
	lista.push_back(entidade);
}

void ListaEntidade::removeEntidade(Ente* entidade) {
	lista.remove(entidade);
}
int ListaEntidade::getTamanho() {
	return lista.size();
}

Ente* ListaEntidade::operator[] (int num) {
	if (num > lista.size() || num < 0) {
		cout << "posicao invalida" << endl;
	}
	list<Ente*>::iterator ptr = lista.begin();
	for (int i = 0; i < num; i++) {
		ptr++;
	}
	return *ptr;
	
}

