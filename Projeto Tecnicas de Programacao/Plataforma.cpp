#include "Plataforma.h"

void Plataforma::atualizar()
{
	pGerenciadorGrafico->desenhaNaTela(body);
}

Plataforma::Plataforma()
{
}

Plataforma::Plataforma(string ID, sf::Vector2f pos, sf::Vector2f tam)
{
	// ID da plataforma
	this->ID = ID;
	// Posicao da plataforma
	body.setPosition(pos);
	posicao = pos;
	// Tamanho da plataforma
	body.setSize(tam);
	tamanho = tam;
	body.setFillColor(sf::Color::White);
}

Plataforma::~Plataforma()
{
}

void Plataforma::colisao(Entidade* entidadeColidida)
{
}
