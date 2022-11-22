#include "Chao.h"


Chao::Chao(const sf::Vector2f tam, const sf::Vector2f pos, const char* caminhoTextura) :
	Terreno(pos, tam, Id::id::chao)
{

	// Tamanho
	body.setSize(tam);
	tamanho = tam;
	// Posicao
	body.setPosition(pos);
	posicao = tam;
	textura = pGerenciadorGrafico->CarregarTextura(caminhoTextura);
	body.setTexture(&textura);

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