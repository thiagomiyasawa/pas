#pragma once
#include "Entidade.h"
#include "Lista.h"
#include <iostream>

using namespace std;
using namespace entidades;

namespace listas {
	class ListaEntidades
	{
	private:
		Lista<Entidade> lista;

	public:
		ListaEntidades();
		~ListaEntidades();
		void push(Entidade* entidade);
		void pop(Entidade* entidade);
		void pop(int n);
		int getSize();
		Entidade* getItem(int num);



	};
}//fim do namespace

