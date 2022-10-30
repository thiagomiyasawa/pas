#pragma once
#include "Ente.h"
#include <list>
#include <iterator>
#include <iostream>
using namespace std;

class ListaEntidade
{
	private:
		list<Ente*> lista;
	
	public:
		ListaEntidade();
		~ListaEntidade();
		void addEnte(Ente* entidade);
		void removeEnte(Ente* entidade);
		void getTamanho();
		Ente* operator[] (int num);



};

