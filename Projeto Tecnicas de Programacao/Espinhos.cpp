#include "Espinhos.h"

void Espinhos::atualizar()
{
}

void Espinhos::colisao(Entidade* entidadeColidida)
{
}


Espinhos::Espinhos(Id::id id, sf::Vector2f pos, sf::Vector2f tam, const char* caminhoTextura) :
	Terreno(pos, tam, Id::id::espinhos)
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

Espinhos::~Espinhos()
{
}
