#pragma once
#include "Ente.h"
#include <list>
#include <iterator>
#include <iostream>
using namespace std;

class ListaEntidades
{
	private:
		list<Ente*> lista;
	
	public:
		ListaEntidades();
		~ListaEntidades();
		void push(Ente* entidade);
		void pop(Ente* entidade);
		int getSize();
		Ente* getItem(int num);//função igual ao [] mas q da pra usar por ponteiro
		Ente* operator[] (int num);



};

