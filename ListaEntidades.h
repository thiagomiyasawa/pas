#pragma once
#include "Entidade.h"
#include "Lista.h"
#include <iostream>
using namespace std;


class ListaEntidades
{
	private:
		Lista<Entidade> lista;
	
	public:
		ListaEntidades();
		~ListaEntidades();
		void push(Entidade* entidade);
		void pop(Entidade* entidade);
		int getSize();
		Ente* getItem(int num);



};

