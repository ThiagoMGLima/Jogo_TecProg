#include "ListaEntidade.h"

ListaEntidade::ListaEntidade()
{

}

ListaEntidade::~ListaEntidade()
{
}

void ListaEntidade::pushEnt(Entidade* entidade)
{
	objListaEntidade.push(entidade);

}

void ListaEntidade::popEnt(int pos)
{
	objListaEntidade.popPos(pos);
}

int ListaEntidade::lenEnt()
{
	return objListaEntidade.getLen();
}

Entidade* ListaEntidade::operator[](int pos)
{
	return objListaEntidade.getItem(pos);
}


void ListaEntidade::executar(sf::RenderWindow* window)
{
	int tam = objListaEntidade.getLen();
	Entidade* aux = nullptr;
	for (int i = 0; i < tam; i++) {
		aux = objListaEntidade.getItem(i);
		if (aux) { //verifica se aux nao e nulo
			/// printf("Posicao entidade%d: %f, %f\n", i+ 1, aux->getCorpo().getPosition().x, aux->getCorpo().getPosition().y);
			aux->atualizar();
			window->draw(aux->getCorpo());
		}
	}
}
