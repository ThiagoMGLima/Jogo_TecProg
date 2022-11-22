#include "Plataforma.h"

void Plataforma::atualizar()
{
	pGerenciadorGrafico->desenhaNaTela(body);
}


Plataforma::Plataforma(Id::id id, sf::Vector2f pos, sf::Vector2f tam, const char* caminhoTextura) :
	Terreno(pos, tam, Id::id::plataforma)
{

	textura = pGerenciadorGrafico->CarregarTextura(caminhoTextura);
	body.setTexture(&textura);

	// Posicao da plataforma
	body.setPosition(pos);
	posicao = pos;

	// Tamanho da plataforma
	body.setSize(tam);
	tamanho = tam;

}

Plataforma::~Plataforma()
{
}

void Plataforma::colisao(Entidade* entidadeColidida)
{
}