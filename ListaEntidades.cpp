#include "ListaEntidades.h"

ListaEntidades::ListaEntidades() {

}

ListaEntidades::~ListaEntidades() {

}

void ListaEntidades::push(Ente* entidade) {
	lista.push_back(entidade);
}

void ListaEntidades::pop(Ente* entidade) {
	lista.remove(entidade);
}
int ListaEntidades::getSize() {
	return lista.size();
}

Ente* ListaEntidades::getItem(int num)
{
	if (num > lista.size() || num < 0) {
		cout << "posicao invalida" << endl;
	}
	list<Ente*>::iterator ptr = lista.begin();
	for (int i = 0; i < num; i++) {
		ptr++;
	}
	return *ptr;
}

Ente* ListaEntidades::operator[] (int num) {
	if (num > lista.size() || num < 0) {
		cout << "posicao invalida" << endl;
	}
	list<Ente*>::iterator ptr = lista.begin();
	for (int i = 0; i < num; i++) {
		ptr++;
	}
	return *ptr;
	
}

