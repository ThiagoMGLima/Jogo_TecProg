#pragma once
#include "Lista.h"
#include "Entidade.h"

class ListaEntidade
{
private:
	Lista<Entidade> objListaEntidade;
public:
	ListaEntidade();
	~ListaEntidade();
	void pushEnt(Entidade* entidade);
	void popEnt(int pos);
	int lenEnt();
	Entidade* operator[](int pos);
	void executar(sf::RenderWindow* window);
};


