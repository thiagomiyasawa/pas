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
		void addEntidade(Ente* entidade);
		void removeEntidade(Ente* entidade);
		int getTamanho();
		Ente* operator[] (int num);



};

