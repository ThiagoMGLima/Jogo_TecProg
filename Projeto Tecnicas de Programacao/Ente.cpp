
#include "Ente.h"

Ente::Ente(): pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico())
{
}

Ente::Ente(string ID)
{
	ID = ID;
}

Ente::~Ente()
{
}

const string Ente::getID()
{
	return ID;
}

void Ente::setID(string ID)
{
	this->ID = ID;
}
