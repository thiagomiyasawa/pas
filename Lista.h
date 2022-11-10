#pragma once
#include "Elemento.h"
#include <iostream>
using namespace std;
template <class TL> class Lista
{
private:
	Elemento<TL>* pFirst;
	Elemento<TL>* pLast;
	int size;
public:
	Lista();
	~Lista();

	TL* getItem(int position) {
		Elemento<TL>* temp = pFirst;
		if (position > size || position < 0) {
			cout << "posicao invalida" << endl;
			return;
		}
		else if (position == 0)
			return temp->getItem;
		else {
			for (int i = 0; i < position; i++) {
				temp = temp->getPNext();
			}
			return temp->getItem();
		}
	}
	void push(TL* item) {
		if (pFirst == nullptr) {
			pFirst = new Elemento<TL>*;
			pFirst->setItem(item);
			pLast = pFirst;
		}
		else {
			Elemento<TL>* temp = new Elemento<TL>*;
			temp->setItem(item);
			pLast->setPNext(temp);
			pLast = temp;
		}
		size++;
	}

	void pop(TL* item) {
		Elemento<TL>* temp = pFirst;
		Elemento<TL*> tempAnt = nullptr;
		while (temp->getItem() != item) {
			tempAnt = temp;
			temp = temp->getPNext();
		}
		if (temp == pFirst) {
			pFirst = temp->getPNext;
		}
		else if (temp == pLast) {
			tempAnt->setPNext(nullptr);
			pLast = tempAnt;
		}
		else {
			tempAnt->setPNext(temp->getPNext());
		}
		delete temp;
		size--;

	}

	int getSize() { return size; }
};

template<class TL>
inline Lista<TL>::Lista()
{
	pFirst = nullptr;
	pLast = nullptr;
	size = 0;
}

template<class TL>
inline Lista<TL>::~Lista()
{
}
