#include "ListaEntidades.h"

ListaEntidades::ListaEntidades() {

}

ListaEntidades::~ListaEntidades() {

}

void ListaEntidades::push(Entidade* entidade) {
	lista.push(entidade);
}

void ListaEntidades::pop(Entidade* entidade) {
	lista.pop(entidade);
}

void ListaEntidades::popDelete(Entidade* entidade) {
	lista.popDelete(entidade);
}
int ListaEntidades::getSize() {
	return lista.getSize();
}

Ente* ListaEntidades::getItem(int num)
{
	if (num > lista.getSize() || num < 0) {
		return nullptr;
	}
	else {
		return lista.getItem(num);
	}
	
}


