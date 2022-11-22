#include "Ente.h"

Ente::Ente(const Id::id id) :
	id(id), pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico())
{
}

Ente::~Ente()
{
}

const Id::id Ente::getID() const
{
	return id;
}
