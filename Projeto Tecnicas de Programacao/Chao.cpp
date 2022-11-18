#include "Chao.h"

Chao::Chao()
{
}

Chao::Chao(string ID, sf::Vector2f tam, sf::Vector2f pos)
{
	// ID
	this->ID = ID;
	// Tamanho
	body.setSize(tam);
	tamanho = tam;
	// Posicao
	body.setPosition(pos);
	posicao = tam;
	body.setFillColor(sf::Color::White);

}

void Chao::colisao(Entidade* entidadeColidida)
{
}

void Chao::atualizar()
{
	pGerenciadorGrafico->desenhaNaTela(body);
}

Chao::~Chao()
{
}
