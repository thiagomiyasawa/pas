#include "ListaEntidade.h"

ListaEntidade::ListaEntidade() {

}

ListaEntidade::~ListaEntidade() {

}

void ListaEntidade::addEnte(Ente* entidade) {
	lista.push_back(entidade);
}

void ListaEntidade::removeEnte(Ente* entidade) {
	lista.remove(entidade);
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

