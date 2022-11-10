#pragma once
template <class TE> class Elemento
{
private:
	Elemento<TE>* pNext;
	TE* item;
public:
	Elemento();
	~Elemento();
	void setPNext(Elemento<TE>* p) { pNext = p; }
	void setItem(TE* i) { item = i; }
	Elemento<TE>* getPNext() { return pNext; }
	TE* getItem() { return item; }
};

template<class TE>
inline Elemento<TE>::Elemento()
{
	pNext = nullptr;
	item = nullptr;
}

template<class TE>
inline Elemento<TE>::~Elemento()
{
}
