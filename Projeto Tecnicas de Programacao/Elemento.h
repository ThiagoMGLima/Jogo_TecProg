#pragma once
#pragma once
template <class TE> class Elemento
{
private:
	Elemento<TE>* pProx;
	TE* item;
public:
	Elemento();
	~Elemento();
	void setPProx(Elemento<TE>* pProx) {
		this->pProx = pProx;
	}
	void setitem(TE* item) {
		this->item = item;
	}
	Elemento<TE>* getPProx() {
		return pProx;
	}
	TE* getItem() {
		if (item)
			return item;
		return nullptr;
	}
};


template<class TE>
inline Elemento<TE>::Elemento() {
	pProx = nullptr;
	item = nullptr;
}

template<class TE>
inline Elemento<TE>::~Elemento() {
}