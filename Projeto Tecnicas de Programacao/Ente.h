#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GerenciadorGrafico.h"
#include "Id.h"

class Ente {

protected:
	// ID para identificar o Ente
	const Id::id id;
	// Gerenciador Grafico
	NomeJogo::Gerenciador::GerenciadorGrafico* pGerenciadorGrafico;


public:
	const Ente(const Id::id id);
	~Ente();
	virtual void atualizar() = 0;
	const Id::id getID() const;
};